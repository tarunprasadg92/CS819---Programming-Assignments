#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
using namespace std;

int main()
{
    // Testing over empty heap
    int i, x;
    
    PQueue q0;
    assert(q0.size() == 0);
    assert(q0.isEmpty() == true);

    cout << q0.findMin() << endl;

    q0.deleteMin();
    
    q0.insert(0);
    assert(q0.size() == 1);
    assert(q0.isEmpty() == false);
    cout << q0.findMin() << endl;
    q0.deleteMin();
    assert(q0.size() == 0);
    assert(q0.isEmpty() == true);

    // Trying to insert over MAX_SIZE number of elements
    PQueue q1;
    for (i = 0; i < 101; i++)
    {
        q1.insert(i);
    }

    cout << q1.findMin() << endl;
    
    cout << "Test success." << endl;

    return 0;    
}
