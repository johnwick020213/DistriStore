#include"NetworkCommunicator.h"
#include <iostream>
#include<cstring>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

NetworkCommunicator::NetworkCommunicator(){
   socket=::socket(AF_INET,SOCK_STREAM,0) ;
   if(socket==-1){
       std::cerr<<"创建套接字失败"<<std::endl;
   }
}

NetworkCommunicator::~NetworkCommunicator(){
    close(socket);
}

bool NetworkCommunicator::sendn(int sockfd,const char * buf,int len){
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

bool NetworkCommunicator::recvn(int sockfd,char*buf,int len){
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

void NetworkCommunicator::sendMessage(const std::string&msg,const std::string& address){
    //设置服务器地址
    sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(8080);

    //地址字符串转换为网络地址
    if(inet_pton(AF_INET,address.c_str(),&serverAddr.sin_addr)<=0){
        std::cerr<<"地址不支持或错误"<<std::endl;
        return;
    }

    //连接服务器
    if(connect(socket,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
        std::cerr<<"连接服务器失败"<<std::endl;
        return;
    }

    //发送消息长度
    int msgLen=msg.size();
    if(!sendn(socket,(char*)&msgLen,sizeof(msgLen))){
        std::cerr<<"发送消息长度失败"<<std::endl;
        return;
    }

    //发送信息
    if(!sendn(socket,msg.c_str(),msgLen)){
        std::cerr<<"发送消息内容失败"<<std::endl;
        return;
    }

    std::cout<<"消息发送到： "<<msg<<std::endl;

}

std::string NetworkCommunicator::receiveMessage(){
    //接收消息长度
    int msgLen;
    if(!recvn(socket,(char*)&msgLen,sizeof(msgLen))){
        std::cerr<<"接收长度失败"<<std::endl;
        return "";
    }

    //接收消息内容
    char* buffer=new char[msgLen];
    if(!recvn(socket,buffer,msgLen)){
        std::cerr<<"接收内容失败"<<std::endl;
        delete[]buffer;
        return "";
    }
    std::string msg(buffer,msgLen);
    delete[]buffer;
    std::cout<<"消息接收："<<msg<<std::endl;
    return msg;
}
