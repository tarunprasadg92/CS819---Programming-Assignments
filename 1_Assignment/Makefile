CXX=g++

all: queue.o queuelist.o queueexp.o

queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp 

queuelist.o: queuelist.cpp queuelist.h
	$(CXX) -c queuelist.cpp

queueexp.o: queueexp.cpp queueexp.h
	$(CXX) -c queueexp.cpp
    
tests: queuelisttest1 queuelisttest2 queuelisttest3 queueexptest1 queueexptest2 queueexptest3 queueexptest4 queueexptest5 queuetest1 queuetest2 queuetest3 queuetest4

queuetest1: queuetest1.cpp queue.cpp queue.h
	$(CXX) queuetest1.cpp queue.cpp -g -o queuetest1

queuetest2: queuetest2.cpp queue.cpp queue.h
	$(CXX) queuetest2.cpp queue.cpp -g -o queuetest2

queuetest3: queuetest3.cpp queue.cpp queue.h
	$(CXX) queuetest3.cpp queue.cpp -g -o queuetest3

queuetest4: queuetest4.cpp queue.cpp queue.h
	$(CXX) queuetest4.cpp queue.cpp -g -o queuetest4

queuelisttest1: queuelisttest1.cpp queuelist.cpp queuelist.h
	$(CXX) queuelisttest1.cpp queuelist.cpp -g -o queuelisttest1

queuelisttest2: queuelisttest2.cpp queuelist.cpp queuelist.h
	$(CXX) queuelisttest2.cpp queuelist.cpp -g -o queuelisttest2

queuelisttest3: queuelisttest3.cpp queuelist.cpp queuelist.h
	$(CXX) queuelisttest3.cpp queuelist.cpp -g -o queuelisttest3

queueexptest1: queueexptest1.cpp queueexp.cpp queueexp.h
	$(CXX) queueexptest1.cpp queueexp.cpp -g -o queueexptest1
    
queueexptest2: queueexptest2.cpp queueexp.cpp queueexp.h
	$(CXX) queueexptest2.cpp queueexp.cpp -g -o queueexptest2

queueexptest3: queueexptest3.cpp queueexp.cpp queueexp.h
	$(CXX) queueexptest3.cpp queueexp.cpp -g -o queueexptest3

queueexptest4: queueexptest4.cpp queueexp.cpp queueexp.h
	$(CXX) queueexptest4.cpp queueexp.cpp -g -o queueexptest4

queueexptest5: queueexptest5.cpp queueexp.cpp queueexp.h
	$(CXX) queueexptest5.cpp queueexp.cpp -g -o queueexptest5

clean: 
	rm -f queuetest1 queuetest2 queuetest3 queuetest4 queuelisttest1 queuelisttest2 queuelisttest3 queueexptest1 queueexptest2 queueexptest3 queueexptest4 queueexptest5 queue.o queuelist.o queueexp.o
