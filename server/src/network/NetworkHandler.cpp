#include"../../include/network/NetworkHandler.h"
#include <iostream>
#include<cstring>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//构造函数初始化网络服务
NetworkHandler::NetworkHandler(const std::string& address,int port)
:address(address),port(port),socketFd(-1)
{}

//创建套接字链接到指定端口
int NetworkHandler::createSocket(const std::string& address,int port)
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        std::cerr<<"错误：创建套接字失败"<<std::endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(port);
    if(inet_pton(AF_INET,address.c_str(),&serverAddr.sin_addr)<=0){
        std::cerr<<"错误：未知地址"<<std::endl;
        close(sockfd);
        return -1;
    }

    if(connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
        std::cerr<<"错误：连接失败"<<std::endl;
        close(sockfd);
        return -1;
    }
    
    return sockfd;
}

//发送数据到指定端口
bool NetworkHandler::sendData(const std::string&address,int port,const std::string &data)
{
    int sockfd = createSocket(address,port);
    if(sockfd<0){
        return false;
    }

    int dataLength=data.size();
    if(sendn(sockfd,(char*)&dataLength,sizeof(dataLength))==-1){
        std::cerr<<"错误：获得数据长度失败"<<std::endl;
        close(sockfd);
        return false;
    }

    if(sendn(sockfd,data.c_str(),dataLength)==-1)
    {
        std::cerr<<"错误：发送数据失败"<<std::endl;
        close(sockfd);
        return false;
    }

    close(sockfd);
    return true;
}


//接收数据
std::string NetworkHandler::receiveData(){
    int dataLength;
    if(recvn(socketFd,(char*)&dataLength,sizeof(dataLength))==-1){
        std::cerr<<"错误：接收数据长度失败"<<std::endl;
        return "";
    }

    char* buffer=new char[dataLength+1];
    if(recvn(socketFd,buffer,dataLength)==-1){
        std::cerr<<"错误：接收数据失败"<<std::endl;
        delete []buffer;
        return "";
    }

    buffer[dataLength]='\0';
    std::string data(buffer);
    delete []buffer;
    return data;
}


int NetworkHandler::sendn(int sockfd,const char * buf,int len){
    int total=0;//已发送字节
    int byteleft=len;//剩余需要发送的字节数
    int n;

    while(total<len){
        n=send(sockfd,buf+total,byteleft,0);
        if(n==-1){
            break;
        }
        total +=n;
        byteleft-=n;
    }
    return n!=-1;
}

int NetworkHandler::recvn(int sockfd,char*buf,int len){
     int total = 0; // 已接收的字节数
    int bytesleft = len; // 剩余需要接收的字节数
    int n;

    while (total < len) {
        n = recv(sockfd, buf + total, bytesleft, 0);
        if (n == -1 || n == 0) {
            break;
        }
        total += n;
        bytesleft -= n;
    }

    return n != -1 && n != 0;
}

//开启网络服务
void NetworkHandler::startService(){
    socketFd=createSocket(address,port);
    if(socketFd<0){
        std::cerr<<"错误：网络服务启动失败"<<std::endl;
    }
}

//关闭网络服务
void NetworkHandler::stopService(){
    if(socketFd>=0){
        close(socketFd);
        socketFd=-1;
    }
}
