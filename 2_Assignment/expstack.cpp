#include "expstack.h"

using namespace std;

// Declaration of exception objects
extern EmptyStackException EmptyStackEx;

// Function to return error message on empty stack
const char* EmptyStackException::what() const throw()
{
    return "EmptyStackException";
}

// Default constructor for initializing the stack
expstack::expstack(int s)
{
    size = s;
    top = -1;
    items = new string[s];
}

// Copy constructor
expstack::expstack(const expstack& source)
{
    size = source.size;
    top = source.top;
    items = new string[source.size];
    for (int i = 0; i < source.size; i++)
    {
        items[i] = source.items[i];
    }
}

// Function to expand the size of the stack
void expstack::expand()
{
    string *new_items = new string[size * 2];
    for (int i = 0; i < size; i++)
    {
        new_items[i] = items[i];
    }
    delete[] items;
    items = new_items;
    size = size * 2;
}

// Assignment operator overloading
expstack& expstack::operator = (const expstack& source)
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
expstack::~expstack()
{
    delete[] items;
}

// Add an item into the stack
void expstack::push(string data)
{
    if ((top + 1) == size)
    {
        expand();
    }
    top++;
    items[top] = data;    
}

// Remove an item from the stack
void expstack::pop()
{
    if (top < 0)
    {
        throw EmptyStackEx;
    }
    top--;
}

// Function to return the size of the stack
int expstack::getSize()
{
    return size;
}

// Function to return the top element of the stack
string expstack::getTop()
{
    return items[top];
}

// Function to determine if the stack has any elements in it
bool expstack::empty()
{
    if (top == -1)
        return true;
    return false;
}
