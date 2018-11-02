CXX=g++

all: stack.o expstack.o

stack.o: stack.cpp stack.h
	$(CXX) -c stack.cpp

expstack.o: expstack.cpp expstack.h
	$(CXX) -c expstack.cpp

test: stacktest evaluation expstacktest

stacktest: stacktest.cpp stack.cpp stack.h
	$(CXX) stacktest.cpp stack.cpp -g -o stacktest

evaluation: evaluation.cpp
	$(CXX) evaluation.cpp -g -o evaluator

expstacktest: expstacktest.cpp expstack.cpp expstack.h
	$(CXX) expstacktest.cpp expstack.cpp -g -o expstacktest

clean:
	rm -f stack.o stacktest expstack.o expstacktest evaluator
