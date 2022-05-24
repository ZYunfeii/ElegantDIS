#include "timer.h"
using namespace tools;

Timer::Timer() {
    offset_time_ = 0;
    timer_state_ = TIMERSTOP;
}

void Timer::timer_start() {
    timer_state_ = TIMERRUN;
    time_stamp_ = get_wall_time();
}

double Timer::elapsed_time() { // 单位:s
    cur_time_ = get_wall_time() - time_stamp_ + offset_time_;
    if (timer_state_ == TIMERSTOP) return 0;
    return cur_time_;
}

void Timer::pause_time() {
    offset_time_ += get_wall_time() - time_stamp_; 
    timer_state_ = TIMERPAUSE;
}

void Timer::stop_time() {
    offset_time_ = 0;
    cur_time_ = 0;
    timer_state_ = TIMERSTOP;
}

double Timer::get_wall_time()
    {
    struct timeval time ;
    if (gettimeofday(&time,NULL)){
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
