#include "queue.h"

using namespace std;

// Declaration of exception objects
extern EmptyQueueException EmptyQueueEx;
extern FullQueueException FullQueueEx;

// Function to return error message on empty queue
const char* EmptyQueueException::what() const throw()
{
    return "EmptyQueueException";
}

// Function to return error message on full queue
const char* FullQueueException::what() const throw()
{
    return "FullQueueException";
}

// Constructor initializing the front and rear positions to 0
queue::queue()
{
    rear = -1;
    front = -1;
}

// Copy constructor
queue::queue(const queue &source)
{
    rear = source.rear;
    front = source.front;
    for (int i = 0; i < MAX_CAP; i++)
    {
        item[i] = source.item[i];
    }
}

// Assignment operator overloading
queue& queue::operator = (const queue &source)
{
    rear = source.rear;
    front = source.front;
    for (int i = 0; i < MAX_CAP; i++)
    {
        item[i] = source.item[i];
    }
}

// Function to check if the queue is filled to capacity
bool queue::full()
{
    if (((rear + 1) % MAX_CAP) == front)
        return true;
    return false;
}

// Function to check if the queue is empty
bool queue::empty()
{
    if ((front == -1) && (rear == -1))
        return true;
    return false;
}

// Function to add an element into the queue
void queue::enqueue(const int data)
{
    // Check if the queue is filled to capacity
    if (full())
    {
        throw FullQueueEx;
    }
    
    // Add element to the queue
    rear = (rear + 1) % MAX_CAP;
    item[rear] = data;
    
    // Upon enqueueing the first element, front is moved to 0
    if (front == -1)
        front = 0;
    cout << "enqueu: front=" << front << "rear=" << rear << endl;
}

// Function to remove an element from the queue
int queue::dequeue()
{
    // Check if the queue is empty
    if (empty())
    {
        throw EmptyQueueEx;
    }
    
    // Dequeue operation
    int element = item[front];
    
    // Removing the last element
    if (front == rear)
    {
        front = -1;
        rear = -1;
        cout << "dequeue: front=" << front << "rear=" << rear << endl;
        return element;
    }
    
    // Dequeueing steps when more than one element is present in the queue
    front = (front + 1) % MAX_CAP;
    cout << "dequeue: front=" << front << "rear=" << rear << endl;
    return element;
}

// Function to return the number of elements in the queue
int queue::size()
{
    if ((front == -1) && (rear == -1))
        return 0;
    
    int size = rear - front + 1;
    if (size < 0)
        return (size + MAX_CAP);

    return size;
}

// Function to dump the contents of the queue into the output stream
void queue::dump(ostream &os)
{
    // Check if the queue is empty
    if (empty())
    {
        return;
    }
    
    // Initialize the iterating variable to front
    int ptr = front;
    
    // Print out all the items until rear is reached
    while (ptr != rear)
    {
        os << item[ptr] << endl;
        ptr = (ptr + 1) % MAX_CAP;
    }
    os << item[ptr] << endl;
}
