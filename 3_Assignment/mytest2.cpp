#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
using namespace std;

int main()
{
    // Testing using duplicate values
    int i, x;
    
    cout << "Test 1: Enqueuing duplicates (zeros)..." << endl;
    int a0[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    PQueue q0(a0, 10);
    assert(q0.size()==10);
    cout << "Test 1: Dequeuing - checking size and min-element..." << endl;
    for( i = 0; i < 10; i++ ) {
        x = q0.findMin();
        assert(x == a0[9-i]);
        assert(q0.size() == (10 - i));
        q0.deleteMin();
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Test 2: Enqueuing duplicates..." << endl;
    int a1[10] = {1, 1, 1, 2, -6, 6, -6, -6, -6, -6};
    PQueue q1(a1, 10);
    assert(q1.size()==10);
    assert(q1.findMin() == -6);
    cout << "Test 2: Dequeuing..." << endl;
    for( i = 0; i < 10; i++ ) {
        x = q1.findMin();
        assert(q1.size() == (10 - i));
        q1.deleteMin();
        cout << x << " ";
    }
    cout << endl;

    cout << "Test success." << endl;
    return 0;    
}
