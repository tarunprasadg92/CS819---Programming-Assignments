#include <iostream>

using namespace std;

#ifndef EXPSTACK_H
#define EXPSTACK_H

class expstack
{
private:
    int size;               // Size of the stack
    int top;                // Array value pointing to the top of the stack
    string *items;          // Array to hold the items of the stack
    
public:
    // Default constructor
    expstack(int s = 8);
    
    // Copy constructor
    expstack(const expstack &source);
    
    // Assignment operator overloading
    expstack& operator = (const expstack &source);
    
    // Destructor
    ~expstack();
    
    // Push function to add an item to the stack
    void push(string data);
    
    // Pop function to remove an item from the stack
    void pop();
    
    // Function to return the size of the stack
    int getSize();
    
    // Function to return the top value in the stack
    string getTop();
    
    // Function to expand the size of the stack
    void expand();
    
    // Function to find if the stack has any elements in it
    bool empty();
};

// Class declaration to throw empty stack exception
class EmptyStackException: public std::exception
{
public:
    const char *what() const throw();
};

#endif
