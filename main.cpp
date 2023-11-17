/******************************************************************************

Austin Kinnear
Chapter 19 Programming Assignment
11/14/24 - 11/16/23


*******************************************************************************/
using namespace std;
#include "Stack.h"
#include <iostream>
#include <string>

// Function to validate if a word meets my criteria
bool validateWord(const string& word) {
    return !word.empty() && word.length() <= 10;
}
// Function to push a word onto the stack when it's validated
void pushWord(Stack& stack) {
    string word;
    cout << "Enter a word to push: ";
    cin >> word;
    if (validateWord(word)) {
        stack.push(word);
    } else {
        cout << "Invalid word. Words cannot be blank and must be less than 11 letters." << endl;
    }
}
// Function to pop
void popWord(Stack& stack) {
    if (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    } else {
        cout << "Stack is empty." << endl;
    }
}
// Function to capitalize everything
void capitalizeWords(Stack& stack) {
    if (!stack.isEmpty()) {
        stack.capitalizeStack();
        cout << "All words in the stack have been capitalized." << endl;
    } else {
        cout << "Stack is empty." << endl;
    }
}
// Function to display
void displayStack(const Stack& stack) {
    if (!stack.isEmpty()) {
        stack.displayStack();
    } else {
        cout << "Stack is empty." << endl;
    }
}
// Function to create the story
void makeStory(const Stack& stack) {
    if (stack.size() < 5) {
        cout << "Not enough words in the stack to make a story." << endl;
        return;
    }

    Stack tempStack = stack; // Create a temporary stack to avoid modifying the original stack
    string words[5];
    for (int i = 0; i < 5; ++i) {
        words[i] = tempStack.pop();
    }

    cout << "In San Diego, I saw a " << words[4] << " at " << words[3] << ". Then I went to " << words[2] << ", ate some delicious " << words[1] << ", and felt really " << words[0] << "!" << endl;
}

void menu(Stack& stack) {
    int choice;
    do {
        cout << "\n"
             << "*** In San Diego, I saw a (choice 1) at (choice 2). Then I went to (choice 3), ate some delicious (choice 4), and felt really (choice 5)! ***\n"
             << "Menu:\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Capitalize\n"
             << "4. Display Stack\n"
             << "5. Make a Story\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pushWord(stack);
                break;
            case 2:
                popWord(stack);
                break;
            case 3:
                capitalizeWords(stack);
                break;
            case 4:
                displayStack(stack);
                break;
            case 5:
                makeStory(stack);
                break;
            case 6:
                cout << "Thank you for playing!" << endl;
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);
}
//Starts the program
int main() {
    Stack wordStack;
    menu(wordStack);
    return 0;
}
