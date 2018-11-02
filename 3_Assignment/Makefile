CXX=g++

test: testPQ0 testPQ PQtest2 mytest1 mytest2 mytest3

testPQ0: testPQ0.cpp PQueue0.cpp PQueue0.h
	$(CXX) testPQ0.cpp PQueue0.cpp -g -o testPQ0

testPQ: testPQ.cpp PQueue.cpp PQueue.h
	$(CXX) testPQ.cpp -g -o testPQ

PQtest2: PQtest2.cpp PQueue0.cpp PQueue0.h
	$(CXX) PQtest2.cpp PQueue0.cpp -g -o PQtest2

mytest1: mytest1.cpp PQueue0.cpp PQueue0.h
	$(CXX) mytest1.cpp PQueue0.cpp -g -o mytest1

mytest2: mytest2.cpp PQueue0.cpp PQueue0.h
	$(CXX) mytest2.cpp PQueue0.cpp -g -o mytest2

mytest3: mytest3.cpp PQueue0.cpp PQueue0.h
	$(CXX) mytest3.cpp PQueue0.cpp -g -o mytest3

clean:
	rm -fr testPQ0 testPQ PQtest2 mytest1 mytest2 mytest3


