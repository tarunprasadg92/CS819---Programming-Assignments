#include<fstream>
#include<iostream>

// Structure of a node in the queue
struct node
{
    int data;
    struct node *next;
};

#ifndef QUEUELIST_H
#define QUEUELIST_H

class queuelist
{
private:
    struct node *rear;               // Pointer to rear of queue
    struct node *front;              // Pointer to front of queue

public:
    // Default constructor
    queuelist();
    
    // Copy constructor
    queuelist(const queuelist &source);
    
    // Assignment operator overloading
    queuelist& operator = (const queuelist &source);
    
    // Destructor
    ~queuelist();
    
    // Add element to end of queue
    void enqueue(const int);
    
    // Remove element from front of queue
    int dequeue();
    
    // Output queue elements to ostream
    void dump(std::ostream &os);
    
    // Return number of elements in the queue
    int size();
    
    // Return true if the queue is empty
    bool empty();
};

// Class to throw Empty Queue Exceptions
class EmptyQueueException: public std::exception
{
public:
    const char *what() const throw();
};

#endif
