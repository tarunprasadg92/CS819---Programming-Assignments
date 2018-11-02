#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
using namespace std;

int main(){
    PQueue q;
    int i, x;
    
    assert(q.size() == 0);
    q.insert(3);
    q.insert(10);
    q.insert(9);
    q.insert(8);
    q.insert(2);
    q.insert(2);
    q.insert(1);
    q.insert(3);
    q.insert(9);
    q.insert(10);
    
    x = q.findMin();
    assert(q.size() == 10);
    assert(x==1);
    q.deleteMin();
    assert(q.size() == 9);
    
    x = q.findMin();
    assert(q.size() == 9);
    assert(x==2);
    q.deleteMin();
    assert(q.size() == 8);
    
    q.insert(1);
    assert(q.size() == 9);
    
    x = q.findMin();
    assert(q.size() == 9);
    assert(x==1);
    q.deleteMin();
    assert(q.size() == 8);
    
}
