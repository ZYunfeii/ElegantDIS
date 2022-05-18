#ifndef CLIENTTOPIC_H
#define CLIENTTOPIC_H
#include <string>

class ClientTopic {
public:
    ClientTopic() = default;
    ClientTopic(std::string topic_name, double topic_data) : topic_name_(topic_name), topic_data_(topic_data) {};
    std::string topic_name_;
    double topic_data_;
};

#endif // CLIENTTOPIC_H
