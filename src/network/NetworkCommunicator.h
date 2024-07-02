#ifndef NETWORK_COMMUNICATOR_H
#define NETWORK_COMMUNICATOR_H

#include<string>

class NetworkCommunicator
{
public:
    NetworkCommunicator();
    
    void sendMessage(const std::string&msg,const std::string& address);

    std::string receiveMessage();
private:
    int socket;

};

#endif
