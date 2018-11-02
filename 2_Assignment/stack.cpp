#include "stack.h"

// Declaration of exception objects
extern EmptyStackException EmptyStackEx;
extern FullStackException FullStackEx;

// Function to return error message on empty stack
const char* EmptyStackException::what() const throw()
{
    return "EmptyStackException";
}

// Function to return error message on full stack
const char* FullStackException::what() const throw()
{
    return "FullStackException";
}

// Default constructor for initializing the stack
stack::stack(int s)
{
    size = s;
    top = -1;
    items = new string[s];
}

// Copy constructor
stack::stack(const stack& source)
{
    size = source.size;
    top = source.top;
    items = new string[source.size];
    for (int i = 0; i < source.size; i++)
    {
        items[i] = source.items[i];
    }
}

// Assignment operator overloading
stack& stack::operator = (const stack& source)
{
    size = source.size;
    top = source.top;
    items = new string[source.size];
    for (int i = 0; i < source.size; i++)
    {
        items[i] = source.items[i];
    }
}

// Destructor
stack::~stack()
{
    delete[] items;
}

// Add an item into the stack
void stack::push(string data)
{
    if ((top + 1) == size)
    {
        throw FullStackEx;
    }
    top++;
    items[top] = data;    
}

// Remove an item from the stack
void stack::pop()
{
    if (top < 0)
    {
        throw EmptyStackEx;
    }
    top--;
}

// Function to return the size of the stack
int stack::getSize()
{
    return size;
}

// Function to return the top element of the stack
string stack::getTop()
{
    return items[top];
}
