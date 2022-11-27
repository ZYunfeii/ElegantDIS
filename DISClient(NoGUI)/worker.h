#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <sys/stat.h>
#include <vector>
#include "jsoncpp/json/json.h"
#include "../ElegantDISClient/threadpool.h"
#include "../CMD/command.h"

class Worker {
public:
    Worker() : thread_pool_(new ThreadPool(4)),
               pf_(nullptr) {
        max_sim_steps_ = 0;
        free_simulation_ = false;
        save_cache_max_size_ = 1;
        cur_sim_steps_ = 0;
        dir_path_ = topic_save_name_ = data_save_name_ = "";
    }
    size_t get_max_sim_steps() const {
        return max_sim_steps_;
    }
    bool free_simulation() const {
        return free_simulation_;
    }
    size_t get_save_cache_max_size() const {
        return save_cache_max_size_;
    }
    size_t get_cur_sim_steps() const {
        return cur_sim_steps_;
    }
    std::string get_dir_path() const {
        return dir_path_;
    }
    std::string get_topic_save_name() const {
        return topic_save_name_;
    }
    std::string get_data_save_name() const {
        return data_save_name_;
    }
    void set_dir_path(const std::string& dir_path) {
        dir_path_ = dir_path;
    }
    void set_save_name(const std::string& topic, const std::string& data) {
        topic_save_name_ = topic;
        data_save_name_ = data;
    }
    void add_steps() {
        cur_sim_steps_++;
    }
    void setting_init(std::string& init_setting) {
        Json::Reader rd;
        Json::Value init_val;
        rd.parse(init_setting, init_val);
        max_sim_steps_ = init_val["max_sim_steps"].asInt();
        free_simulation_ = init_val["free_simulation"].asBool();
        if (free_simulation_) save_cache_max_size_ = 100;
        else save_cache_max_size_ = max_sim_steps_ / 10; // 设置缓存水位线

        if (!dir_path_.empty() && !topic_save_name_.empty() && !data_save_name_.empty()) {
            std::string file_path = dir_path_ + "/" + topic_save_name_ + "-" + data_save_name_;
            mkdir(dir_path_.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); // https://www.cnblogs.com/xiaofeiIDO/p/6695459.html
            pf_ = fopen(file_path.c_str(), "w+");
        }
    }
    void save(Json::Value& val_save) {
        save_cache_.push_back(val_save);
        if (save_cache_.size() >= save_cache_max_size_ || cur_sim_steps_ >= max_sim_steps_) {
            thread_pool_->addTask(std::bind(&Worker::save_sim_trace, this, save_cache_)); // 将IO任务扔进线程池
            save_cache_.clear();
        }
    }
    void save_sim_trace(std::vector<Json::Value>& val_save_vec) {
        for (auto &val_save : val_save_vec) {
            if (val_save.isDouble()) {
                char buf[256];
                sprintf(buf, "%.3lf\r\n", val_save.asDouble());
                fputs(buf, pf_);
            } else if (val_save.isString()) {
                fputs((val_save.asString() + "\r\n").data(), pf_);
            }
        }
        fflush(pf_);
    }
private:
    std::size_t max_sim_steps_;
    std::size_t save_cache_max_size_;
    std::size_t cur_sim_steps_;
    bool free_simulation_;
    FILE* pf_;
    std::string dir_path_;
    std::string topic_save_name_;
    std::string data_save_name_;
    std::vector<Json::Value> save_cache_;
    std::unique_ptr<ThreadPool> thread_pool_;
};

#endif