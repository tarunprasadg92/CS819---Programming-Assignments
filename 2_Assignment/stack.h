#include <iostream>

#ifndef STACK_H
#define STACK_H

using namespace std;

class stack
{
private:
    int size;               // Size of the stack
    int top;                // Array value pointing to the top of the stack
    string *items;          // Array to hold the items of the stack
    
public:
    // Default constructor
    stack(int s = 8);
    
    // Copy constructor
    stack(const stack &source);
    
    // Assignment operator overloading
    stack& operator = (const stack &source);
    
    // Destructor
    ~stack();
    
    // Push function to add an item to the stack
    void push(string data);
    
    // Pop function to remove an item from the stack
    void pop();
    
    // Function to return the size of the stack
    int getSize();
    
    // Function to return the top value in the stack
    string getTop();
};

// Class declaration to throw empty stack exception
class EmptyStackException: public std::exception
{
public:
    const char *what() const throw();
};

// Class declaration to throw full stack exception
class FullStackException: public std::exception
{
public:
    const char *what() const throw();
};

#endif
