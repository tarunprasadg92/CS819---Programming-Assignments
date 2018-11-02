#include "PQueue0.h"

// Default constructor - Empty heap
PQueue::PQueue()
{
   _size = 0; 
}

// Construct a heap from the given array of values for given size
PQueue::PQueue(int *items, int size)
{
    // Insert all the elements into the tree and reorder through buildHeap function
    for (int i = 0; i < size; i++)
    {
        _array[i] = items[i];
    }
    _size = size;

    buildHeap();
}

// Linear heap construction
void PQueue::buildHeap()
{
    // Floyd's algorithm - order elements only when they are accessed
    for (int i = (_size - 1); i >= 0; i--)
    {
       moveDown(i); 
    }
}

// Move down the element at the given index
void PQueue::moveDown(int index)
{
    // Repeat until leaf node is reached
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int length = _size;
        int min_index = index;

        // if left child is lesser than the parent
        if ((left < length) && (_array[left] < _array[min_index]))
            min_index = left;

        // if right child is lesser than the parent
        if ((right < length) && (_array[right] < _array[min_index]))
            min_index = right;

        // swap the child with the lesser value
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
void PQueue::moveUp()
{
    int child_index = _size - 1;
    int parent_index = child_index / 2;

    // if child is lesser than the parent and child is not the root
    while ((_array[child_index] < _array[parent_index]) && (child_index >= 0) && (parent_index >= 0))
    {
        // swap the parent and child
        int temp = _array[child_index];
        _array[child_index] = _array[parent_index];
        _array[parent_index] = temp;

        // adjust the child and parent to point to the next level
        child_index = parent_index;
        parent_index = child_index / 2;
    }
}

// Insert an item into the heap
void PQueue::insert(T item)
{
    // insert at the end and move up based on the value
    if (_size == MAX_SIZE)
    {
        cout << "Maximum capacity reached" << endl;
        return;
    }
    _size += 1;
    _array[_size - 1] = item;
    moveUp();
}

// Find the minimum element in the heap
T PQueue::findMin()
{
    // the root holds the minimum value
    if (_size == 0)
    {
        cout << "Heap is empty" << endl;
        return -1;
    }
    return _array[0];
}

// Delete the smallest element from the queue
void PQueue::deleteMin()
{
    if (_size == 0)
    {
        cout << "Heap is empty" << endl;
        return;
    }

    int child_index = _size - 1;

    // overwrite the root with the last leaf
    int temp = _array[child_index];
    _array[child_index] = _array[0];
    _array[0] = temp;

    // decrease the count
    _size -= 1;

    // readjust the tree structure
    moveDown(0);
}

// Test if the priority queue is empty
bool PQueue::isEmpty()
{
    if (_size == 0)
        return true;
    return false;
}

// Return queue size
int PQueue::size()
{
    return _size;
}
