#include "Node.h"

Node::Node(int id):id(id),running(false){}

void Node::start(){
    running=true;
}

void Node::stop(){
    running=false;
}

int Node::getId(){
    return id;
}

