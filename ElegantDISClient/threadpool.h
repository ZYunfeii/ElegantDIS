#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>
#include <assert.h>
class ThreadPool {
public:
    explicit ThreadPool(size_t threadCount = 8): pool_(std::make_shared<Pool>()) {
            assert(threadCount > 0);
            for(size_t i = 0; i < threadCount; i++) {
                std::thread([pool = pool_] {
                    std::unique_lock<std::mutex> locker(pool->mtx); // 会对mtx加锁 mtx是线程池唯一的一把🔓
                    while(true) {
                        if(!pool->tasks.empty()) {
                            auto task = std::move(pool->tasks.front());
                            pool->tasks.pop();
                            locker.unlock();
                            task(); // 执行任务
                            locker.lock();
                        } 
                        else if(pool->isClosed) break;
                        else pool->cond.wait(locker); // 真正开始wait后才解锁locker,被唤醒后加锁以保护共享数据 每个任务只会有一个线程被唤醒执行 正常情况一开始都在这wait起
                    }
                }).detach(); // 主线程和子线程相互分离，互不干扰
            }
    }

    ThreadPool() = default; // 构造默认

    ThreadPool(ThreadPool&&) = default; // 移动构造默认
    
    ~ThreadPool() {
        if(static_cast<bool>(pool_)) {
            {
                std::lock_guard<std::mutex> locker(pool_->mtx); 
                pool_->isClosed = true;
            }
            pool_->cond.notify_all(); // 唤醒所有阻塞的线程 存在锁竞争 只有一个线程能够获得锁 剩余的线程阻塞 等待解锁后再次竞争出一个线程 持续下去 最后所有wait的线程全部唤醒
        }
    }

    template<class F>
    void AddTask(F&& task) {  // 完美转发
        {   // 括号一定要有 划定作用域
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->tasks.emplace(std::forward<F>(task)); // 完美转发
        }
        pool_->cond.notify_one(); // 生产者 唤醒一个线程处理 不存在锁竞争
    }

    int getTaskSizeInPool() {
        return pool_->tasks.size();
    }

private:
    struct Pool {
        std::mutex mtx;
        std::condition_variable cond;
        bool isClosed;
        std::queue<std::function<void()>> tasks;
    };
    std::shared_ptr<Pool> pool_;
};


#endif //THREADPOOL_H