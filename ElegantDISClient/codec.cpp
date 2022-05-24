#include "codec.h"

using namespace muduo;
using namespace muduo::net;
using namespace pubsub;

ParseResult pubsub::parseMessage(Buffer* buf, string* cmd, string* topic, string* content) {
    ParseResult result = kError;
    const char* crlf = buf->findCRLF();
    if (crlf)
    {
        // pub + " " + topic + "\r\n" + content + "\r\n"
        // step + " " + sim_time + "\r\n"
        const char* space = std::find(buf->peek(), crlf, ' ');
        if (space != crlf)
        {
            cmd->assign(buf->peek(), space);
            if (*cmd == "pub") {
                topic->assign(space+1, crlf);
                const char* start = crlf + 2;
                crlf = buf->findCRLF(start);
                if (crlf)
                {
                    content->assign(start, crlf);
                    buf->retrieveUntil(crlf+2);
                    result = kSuccess;
                }
                else
                {
                    result = kContinue;
                }
            } else if (*cmd == "step") {
                content->assign(space + 1, crlf); // 仿真时间
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
            else
            {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
        }
        else
        {
            cmd->assign(buf->peek(), space);
            if (*cmd == "init") {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            } else if (*cmd == "synpub") {
                buf->retrieveUntil(crlf+2);
                result = kSuccess;
            }
            else {
                result = kError;
            }

        }
    }
    else
    {
        result = kContinue;
    }
    return result;
}
