#include "command.h"

static std::unordered_map<Cmd, std::string> cmdMap = {
    {STEP_OVER   , "stepover"},
    {INIT_OVER   , "initover"},
    {PUB         , "pub"     },
    {SUB         , "sub"     },
    {UNSUB       , "unsub"   },
    {SYN_PUB_OVER, "synpubover"},
    {NODE_NAME   , "nodename"},
    {INIT        , "init"    },
    {STEP        , "step"    },
    {SYN_PUB     , "synpub"  }
};

std::string getCmdStr(Cmd c) {
    return cmdMap[c];
}

std::string makeSendCmd(Cmd c) {
    return cmdMap[c] + "\r\n";
}

std::string makeSendCmd(Cmd c, const std::string& topic) {
    return cmdMap[c] + " " + topic + "\r\n";
}

std::string makeSendCmd(Cmd c, const std::string& topic, const std::string& content) {
    return cmdMap[c] + " " + topic + "\r\n" + content + "\r\n";
}

void log(Level lev, std::string msg) {
    switch (lev)
    {
    case INFO:
        std::cout << "[INFO] " << msg << std::endl;
        break;
    case DEBUG:
        std::cout << "[DEBUG] " << msg << std::endl;
        break;
    case WARN:
        std::cout << "[WARN] " << msg << std::endl;
        break;
    case ERROR:
        std::cout << "[ERROR] " << msg << std::endl;
        break;
    default:
        break;
    }
}
