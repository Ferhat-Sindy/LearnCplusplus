UseBookClass : Book.o UseBookClass.o
	g++ -O -o UseBookClass Book.o UseBookClass.o  

Book.o : Book.cpp Book.hpp
	g++ -c -O Book.cpp

UseBookClass.o : UseBookClass.cpp Book.hpp
	g++ -c -O UseBookClass.cpp 

clean:
	del *.o UseBookClass