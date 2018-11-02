#include "queuelist.h"

using namespace std;

// Empty Queue Exception class declaration
extern EmptyQueueException EmptyQueueEx;

// Function to return the error message on empty queue exception
const char* EmptyQueueException::what() const throw()
{
    return "EmptyQueueException";
}

// Constructor for initializing the front and rear pointers to NULL
queuelist::queuelist()
{
    rear = NULL;
    front = NULL;
}

// Copy constructor
queuelist::queuelist(const queuelist& source)
{
    front = NULL;
    rear = NULL;
    
    // Pointer to the front for iterating through the list
    struct node *source_current = source.front;

    // Iterate through the last but one node
    while (source_current != source.rear)
    {
        struct node *new_element = new node;
        new_element->data = source_current->data;
        new_element->next = NULL;
        
        if (empty())
        {
            front = new_element;
            rear = new_element;
            front->next = rear;
        }
        else
        {
            rear->next = new_element;
            new_element->next = front;
            rear = new_element;
        }
        source_current = source_current->next;
    }

    // Handling the last node / single node
    struct node *new_element = new node;
    new_element->data = source_current->data;
    new_element->next = NULL;
    
    if (empty())
    {
        front = new_element;
        rear = new_element;
        front->next = rear;
    }
    else
    {
        rear->next = new_element;
        new_element->next = front;
        rear = new_element;
    }
}

// Overloaded assignment operator
queuelist& queuelist::operator = (const queuelist &source)
{
    front = NULL;
    rear = NULL;
    
    struct node *source_current = source.front;
    while (source_current != source.rear)
    {
        struct node *new_element = new node;
        new_element->data = source_current->data;
        new_element->next = NULL;
        
        if (empty())
        {
            front = new_element;
            rear = new_element;
            front->next = rear;
        }
        else
        {
            rear->next = new_element;
            new_element->next = front;
            rear = new_element;
        }
        source_current = source_current->next;
    }

    struct node *new_element = new node;
    new_element->data = source_current->data;
    new_element->next = NULL;
    
    if (empty())
    {
        front = new_element;
        rear = new_element;
        front->next = rear;
    }
    else
    {
        rear->next = new_element;
        new_element->next = front;
        rear = new_element;
    }
}

// Destructor for clearing the contents of the queue
queuelist::~queuelist()
{
    if (empty())
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node *current = front;
        while (current != rear)
        {
            front = front->next;
            delete current;
            current = front;
        }
        delete current;
        front = NULL;
        rear = NULL;
    }
}

// Function to check if the queue is empty
bool queuelist::empty()
{
    if ((front == NULL) && (rear == NULL))
        return true;
    return false;
}

// Function to return the size of the queue
int queuelist::size()
{
    if (empty())
        return 0;
    int size = 1;
    struct node *current = front;
    while (current->next != front)
    {
        size++;
        current = current->next;
    }
    return size;
}

// Function to add an element into the queue
void queuelist::enqueue(const int data)
{
    struct node *new_element = new node;
    new_element->data = data;
    new_element->next = NULL;
    
    if (empty())
    {
        front = new_element;
        rear = new_element;
        front->next = rear;
    }
    else
    {
        rear->next = new_element;
        new_element->next = front;
        rear = new_element;
    }
}

// Function to remove an element from the queue
int queuelist::dequeue()
{
    int data;
    // Check if the queue is empty
    if (empty())
    {
        throw EmptyQueueEx;
    }
    
    // One element in the queue
    if (front == rear)
    {
        data = front->data;
        delete front;
        front = NULL;
        rear = NULL;
        return data;
    }
    
    // Multiple elements present in the queue
    else
    {
        data = front->data;
        struct node *current = front;
        front = front->next;
        rear->next = front;
        delete current;
        return data;
    }
}

// Function to dump the contents of the queue into the output stream
void queuelist::dump(ostream &os)
{
    // Check if the queue is empty
    if (empty())
    {
        os << "Empty queue" << endl;
        return;
    }
    
    struct node *current = front;
    while (current->next != front)
    {
        os << current->data << "  ";
        current = current->next;
    }
    os << current->data << endl;
}
