#!make -f

demo: TreeDemo.o Tree.o
	g++ -std=c++11 $^ -o demo

test: TreeTest.o Tree.o
	g++ -std=c++11 $^ -o test

%.o: %.cpp
	g++ -std=c++11 --compile $< -o $@

TreeTest.o: badkan.hpp Tree.hpp

TreeDemo.o: Tree.hpp

clean:
	rm -f *.o demo test
