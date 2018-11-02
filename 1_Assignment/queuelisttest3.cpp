/* This test driver tests queue interface methods using C asserts */

#include "queuelist.h"
#include <cassert>

EmptyQueueException EmptyQueueEx;

using namespace std;

int main(){
    queuelist q1;
	
	for(int i=1; i<=1050; i++)
		q1.enqueue(i);

    assert(q1.size()==1050);
	
	queuelist q2;
    assert(q2.size()==0);

    // assignment operator 
    q2 = q1;
    assert(q2.size()==1050);
	
	for(int i=1; i<1050; i++)
		q2.dequeue();
    assert(q2.size()==1);

    assert(q1.size()==1050);

	for(int i=1; i<=1050; i++)
		q2.enqueue(i);
    assert(q2.size()==1051);
}


