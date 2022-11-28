#include "disclient.h"
int main(int argc, char* argv[]) {
    auto client = new DisClient;
    client->connect();
    return 0;
}