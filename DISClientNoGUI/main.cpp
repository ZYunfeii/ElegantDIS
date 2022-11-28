#include "disclient.h"
#include "gflags/gflags.h"
// net config
DEFINE_string(ip, "localhost", "ip for admin node");
DEFINE_int32(port, 9999, "port for admin node");
// log config
DEFINE_string(log_path, "./log", "log file path");
DEFINE_string(log_suffix, ".log", "log file suffix");
DEFINE_int32(log_level, 1, "log level");
// node name
DEFINE_string(node_name, "testnode", "the name of client node");


int main(int argc, char* argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    auto client = new DisClient;
    client->connect();
    return 0;
}