#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>
#include <time.h>

namespace tools{
class Timer {
public:
    Timer();
    void timer_start();
    double elapsed_time();
    void pause_time();
    void stop_time();

private:
    double get_wall_time();
    double time_stamp_;
    double cur_time_;
    double offset_time_;

    enum{
        TIMERSTOP,
        TIMERRUN,
        TIMERPAUSE
    } timer_state_;
};
}

#endif // TIMER_H