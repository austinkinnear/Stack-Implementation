#ifndef STACK_H
#define STACK_H
#include <string>

// Node structure for stack
struct Node {
    std::string word;
    Node* next;
};

// Stack class
class Stack {
public:
    Stack(); //Constructor
    ~Stack(); //Deconstructor

    void push(const std::string& word);
    std::string pop();
    void capitalizeStack();
    void displayStack() const;
    bool isEmpty() const;
    int size() const;

private:
    Node* top; //For the top node of the stack
};

#endif 
