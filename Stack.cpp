#include "Stack.h"
#include <cctype>
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Push method for adding a new word to the stack
void Stack::push(const std::string& word) {
    Node* newNode = new Node;
    newNode->word = word;
    newNode->next = top;
    top = newNode;
}
// Pop method for removing the top word of the stack
std::string Stack::pop() {
    if (isEmpty()) {
        return "";
    }
    Node* temp = top;
    std::string word = top->word;
    top = top->next;
    delete temp;
    return word;
}
// Method to capitalize
void Stack::capitalizeStack() {
    Node* current = top;
    while (current != nullptr) {
        for (char &c : current->word) {
            c = toupper(c);
        }
        current = current->next;
    }
}
// Method to display 
void Stack::displayStack() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->word << std::endl;
        current = current->next;
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}
//Method to return stack size
int Stack::size() const {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
