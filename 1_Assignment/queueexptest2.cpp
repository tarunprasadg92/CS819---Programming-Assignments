/* This test driver tests queue interface methods using C asserts */

#include "queueexp.h"
#include <cassert>

using namespace std;

//  Empty Queue Exception object declaration
EmptyQueueException EmptyQueueEx;


int main(){
    queueexp myqueue;
	cout << "capacity:" << myqueue.capacity() << endl;
    assert(myqueue.size()==0);
    assert(myqueue.empty()==true);
    
    try {
   	 	myqueue.dequeue();
	}
	catch(EmptyQueueException e){
		cout << "exception caught" << endl;	
	}	

    for(int i=0; i<10000; i++){
        myqueue.enqueue(i);
	}
	cout << "capacity:" << myqueue.capacity() << endl;

	assert(myqueue.size()==10000);
	assert(myqueue.front()==0);
	
	// myqueue.front()=88;
	myqueue.setfront(88);
	assert(myqueue.front()==88);
	
    for(int i=0; i<9999; i++){
        myqueue.dequeue();
	}
	cout << "capacity:" << myqueue.capacity() << endl;

	assert(myqueue.size()==1);
	assert(myqueue.front()==9999);
	
	myqueue.setfront(88);
	assert(myqueue.front()==88);
	
	myqueue.dequeue();
    assert(myqueue.size()==0);
    assert(myqueue.empty()==true);
    try {
    	myqueue.dequeue();
 	}
 	catch(EmptyQueueException e){
 		cout << "exception caught" << endl;	
 	}	
}


