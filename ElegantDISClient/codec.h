#ifndef CODECC_H
#define CODECC_H
#include "muduo/base/Types.h"
#include "muduo/net/Buffer.h"

namespace pubsub
{
using muduo::string;

enum ParseResult
{
  kError,
  kSuccess,
  kContinue,
};

ParseResult parseMessage(muduo::net::Buffer* buf,
                         string* cmd,
                         string* topic,
                         string* content);
}  // namespace pubsub
#endif // CODECC_H
