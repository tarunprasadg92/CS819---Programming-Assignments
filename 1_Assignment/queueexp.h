#include<fstream>
#include<iostream>
#include<exception>

#ifndef QUEUEEXP_H
#define QUEUEEXP_H

class queueexp
{
private:
    int *_item;             // Pointer to the dynamic integer array
    int _front;             // Index to front element in the queue
    int _size;              // Number of current elements in the queue
    int _capacity;          // Current capacity    

public:
    // Default constructor
    queueexp();

    // Copy constructor
    queueexp(const queueexp &source);
    
    // Assignment operator overloading
    queueexp& operator = (const queueexp &source);
    
    // Destructor
    ~queueexp();

    // Add element to end of queue
    void enqueue(const int);
    
    // Expand queue size when size reached the capacity
    void expand();
    
    // Remove element from front of queue
    int dequeue();
    
    // Output queue elements to ostream
    void dump(std::ostream &os);
    
    // Funtion to return the number of elements in the queue
    int size();

    // Funtion to return the capacity of the queue
    int capacity();
    
    // Return true if the queue is empty
    bool empty();
    
    // Return true if queue is full
    bool full();
    
    // Function to get the first element from the queue
    int front();
    
    // Function to set the value of the first element in the queue
    void setfront(int);
};

// Class to throw empty queue exception
class EmptyQueueException: public std::exception
{
public:
    const char *what() const throw();
};

#endif
