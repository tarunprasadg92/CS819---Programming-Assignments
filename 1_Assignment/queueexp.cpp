#include"queueexp.h"

using namespace std;

extern EmptyQueueException EmptyQueueEx;

const char* EmptyQueueException::what() const throw()
{
    return "EmptyQueueException";
}

// Constructor for queue initialization
queueexp::queueexp()
{
    _item = new int[8];
    _front = 0;
    _size = 0;
    _capacity = 8;
}

// Copy constructor
queueexp::queueexp(const queueexp &source)
{
    _item = new int[source._capacity];
    _front = source._front;
    _size = source._size;
    _capacity = source._capacity;
    
    for (int i = 0; i < source._capacity; i++)
    {
        _item[i] = source._item[i];
    }
}

// Overloaded assignment operator
queueexp& queueexp::operator = (const queueexp &source)
{
    _item = new int[source._capacity];
    _front = source._front;
    _size = source._size;
    _capacity = source._capacity;
    
    for (int i = 0; i < source._capacity; i++)
    {
        _item[i] = source._item[i];
    }

}

// Destructor
queueexp::~queueexp()
{
    delete[] _item;
}

// Function to return the capacity of the queue
int queueexp::capacity()
{
    return _capacity;
}

// Function that returns the front element in the queue
int queueexp::front()
{
    return _item[_front];
}

// Function to set the front element to the specified value
void queueexp::setfront(int f)
{
    _item[_front] = f;
}

// Funtion to return the number of elements in the queue
int queueexp::size()
{
    return _size;
}

// Function to check if the queue is filled to capacity
bool queueexp::full()
{
    if (_size == _capacity)
        return true;
    return false;
}

// Function to check if the queue is empty
bool queueexp::empty()
{
    if (_size == 0)
        return true;
    return false;
}

// Function to expand queue when size has reached capacity
void queueexp::expand()
{
    int *_new_queue = new int[2 * _capacity];
    for (int i = 0; i < _capacity; i++)
    {
        _new_queue[i] = _item[(_front + i) % _capacity];
    }
    delete[] _item;
    _item = _new_queue;
    _capacity = 2 * _capacity;
    _front = 0;
}

// Function to add an element into the queue
void queueexp::enqueue(const int data)
{
    // Check if the queue is full
    if (full())
    {
        expand();
    }
    
    _item[(_size + _front) % _capacity] = data;
    _size++;
}

// Function to remove an element from the queue
int queueexp::dequeue()
{
    // Check if the queue is empty
    if (empty())
    {
        throw EmptyQueueEx;
    }
    _size--;
    _front = (_front + 1) % _capacity;
    return _item[_front - 1];
}

// Function to dump the contents of the queue to the output stream
void queueexp::dump(ostream &os)
{
    // Check if the queue is empty
    if (empty())
    {
        cout << "Empty queue." << endl;
        return;
    }
    
    for (int i = 0; i < _size; i++)
    {
        os << _item[(_front + i) % _capacity] << "  ";
    }
    os << endl;
}
