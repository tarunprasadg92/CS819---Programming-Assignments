#include<fstream>
#include<iostream>

#define MAX_CAP 10         // Queue size set to 10

#ifndef QUEUE_H
#define QUEUE_H

class queue
{
private:
    int item[MAX_CAP];      // Array for queue items
    int rear;               // Index to rear of queue
    int front;              // Index to front of queue

public:
    // Default constructor
    queue();
 
    // Copy constructor
    queue(const queue &source);
    
    // Assignment operator overloading
    queue& operator = (const queue &source);
 
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
    
    // Return true if queue is full
    bool full();
};

// Class declaration to throw empty queue exceptions
class EmptyQueueException: public std::exception
{
public:
    const char *what() const throw();
};

// Class declaration to throw full queue exceptions
class FullQueueException: public std::exception
{
public:
    const char *what() const throw();
};

#endif
