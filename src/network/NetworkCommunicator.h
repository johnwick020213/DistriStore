#ifndef NETWORK_COMMUNICATOR_H
#define NETWORK_COMMUNICATOR_H

#include<string>

class NetworkCommunicator
{
public:
    NetworkCommunicator();
    ~NetworkCommunicator();

    void sendMessage(const std::string&msg,const std::string& address);

    std::string receiveMessage();
private:
    int socket;
    bool sendn(int sockfd, const char* buf, int len);
    bool recvn(int sockfd, char* buf, int len);
};

#endif
