#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node(int id);
    
    void start();//启动节点
    void stop();//停止节点
    int getId();//获取节点ID

private:
    int id;
    bool running//节点运行状态
};


#endif
