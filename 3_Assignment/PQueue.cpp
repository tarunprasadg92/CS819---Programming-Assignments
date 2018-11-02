#include "PQueue.h"

// Default constructor - Empty heap
template <class T, int max_size>
PQueue<T, max_size>::PQueue()
{
   _size = 0; 
}

// Construct a heap from the given array of values for given size
template <class T, int max_size>
PQueue<T, max_size>::PQueue(T *items, int size)
{
   for (int i = 0; i < size; i++)
   {
        _array[i] = items[i];
   }
   _size = size;

   buildHeap();
}

// Linear heap construction
template <class T, int max_size>
void PQueue<T, max_size>::buildHeap()
{
    // Floyd's algorithm
    for (int i = (_size - 1); i >= 0; i--)
    {
       moveDown(i); 
    }
}

// Move down the element at the given index
template <class T, int max_size>
void PQueue<T, max_size>::moveDown(int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int length = _size;
        int min_index = index;

        if ((left < length) && (_array[left] < _array[min_index]))
            min_index = left;

        if ((right < length) && (_array[right] < _array[min_index]))
            min_index = right;

        if (index != min_index)
        {
            int temp = _array[min_index];
            _array[min_index] = _array[index];
            _array[index] = temp;
            index = min_index;
        }

        else
            break;
    }
}

// Move up the last element in the heap array
template <class T, int max_size>
void PQueue<T, max_size>::moveUp()
{
    int child_index = _size - 1;
    int parent_index = child_index / 2;

    while ((_array[child_index] < _array[parent_index]) && (child_index >= 0) && (parent_index >= 0))
    {
        int temp = _array[child_index];
        _array[child_index] = _array[parent_index];
        _array[parent_index] = temp;

        child_index = parent_index;
        parent_index = child_index / 2;
    }
}

// Insert an item into the heap
template <class T, int max_size>
void PQueue<T, max_size>::insert(T item)
{
    _size += 1;
    _array[_size - 1] = item;
    moveUp();
}

// Find the minimum element in the heap
template <class T, int max_size>
T PQueue<T, max_size>::findMin()
{
    return _array[0];
}

// Delete the smallest element from the queue
template <class T, int max_size>
void PQueue<T, max_size>::deleteMin()
{
    int child_index = _size - 1;

    int temp = _array[child_index];
    _array[child_index] = _array[0];
    _array[0] = temp;

    _size -= 1;

    moveDown(0);
}

// Test if the priority queue is empty
template <class T, int max_size>
bool PQueue<T, max_size>::isEmpty()
{
    if (_size == 0)
        return true;
    return false;
}

// Return queue size
template <class T, int max_size>
int PQueue<T, max_size>::size()
{
    return _size;
}
