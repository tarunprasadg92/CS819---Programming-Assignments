/* This test driver tests queue copy constructor and assignment operator using asserts */

#include "queuelist.h"
#include <cassert>

EmptyQueueException EmptyQueueEx;

using namespace std;

int main(){
    queuelist q1;
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);
    q1.enqueue(10);
    q1.enqueue(12);
    assert(q1.size()==6);
    
    queuelist q2(q1);
	assert(q2.size()==6);
	
	q1.dequeue();
    assert(q1.size()==5);
	assert(q2.size()==6);
	q1.dump(cout);
	q2.dump(cout);
	
	q1 = q2;
    assert(q1.size()==6);
	assert(q2.size()==6);
	q1.dump(cout);
	q2.dump(cout);
	
}


