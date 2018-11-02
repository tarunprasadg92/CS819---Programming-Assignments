#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
using namespace std;

int main()
{
    // Testing using negative values
    int i, x;
    
    cout << "Test 1: Enqueuing..." << endl;
    int a0[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
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

    cout << "Test success." << endl;    
    return 0;    
}

