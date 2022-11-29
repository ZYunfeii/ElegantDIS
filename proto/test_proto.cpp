#include <iostream>
#include <string>
#include "transdata.pb.h"

using namespace std;
// g++ -o test test_proto.cpp transdata.pb.cc -g -lprotobuf
int main() {
    transdata::Topic1* topic = new transdata::Topic1;
    topic->set_id(44);
    topic->add_data(1.2);
    topic->add_data(2.2);


    string tmp;
    topic->SerializeToString(&tmp);

    transdata::Topic1* topic_parse = new transdata::Topic1;
    topic_parse->set_id(10); // 脏对象也可以直接parse
    if(!topic_parse->ParseFromString(tmp)) {
        cout << "parse error\n";
    }

    cout << topic_parse->id() << endl;
    for (int i = 0; i < topic_parse->data_size(); ++i) {
        cout << topic_parse->data(i) << " ";
    } cout << endl;

    return 0;
}