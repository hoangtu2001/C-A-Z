#include <string>
#include <exception>
#ifndef STACK_H
#define STACK_H
//Dynamic stack data structure

bool isEmpty()
{
    return top == nullptr;
}
struct Node
{
    std::string data;
    Node* next;

    Node()
    {
        data = "";
        next = nullptr;
    }

    Node(std::string data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
Node* top = nullptr;
//push
void push(std::string str)
{
    top = new Node(str, top);
}
//pop
std::string pop()
{
    Node* tmpNode = top;
    if(isEmpty())
        throw std::range_error("Stack is empty");

    std::string tmp = top->data;
    
    top = top->next;
    delete tmpNode;
    return tmp;
}
//isEmpty

//peek
std::string peek()
{
    if(isEmpty())
        throw std::range_error("Stack is empty");
    return top->data;
}

#endif