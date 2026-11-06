CXX_COMPILER=g++
CXX_FLAGS=-Wall
main: main.cpp matrix.cpp
	$(CXX_COMPILER) main.cpp matrix.cpp $(CXX_FLAGS) -o main

clean:
	rm -f main