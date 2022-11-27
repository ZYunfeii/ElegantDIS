#ifndef COMMAND_H
#define COMMAND_H
#include <unordered_map>
#include <string>
#include <iostream>

enum Cmd {
    STEP_OVER = 0,
    INIT_OVER,
    PUB,
    SUB,
    UNSUB,
    SYN_PUB_OVER,
    NODE_NAME,
    INIT,
    STEP,
    SYN_PUB
};

extern std::string getCmdStr(Cmd c);

extern std::string makeSendCmd(Cmd c);

extern std::string makeSendCmd(Cmd c, const std::string& topic);

extern std::string makeSendCmd(Cmd c, const std::string& topic, const std::string& content);

enum Level {
    INFO = 0,
    DEBUG,
    WARN,
    ERROR
};

extern void log(Level lev, std::string msg);


#endif