CXX=g++

2048:2048.o modele.o
	$(CXX)  2048.o modele.o -o 2048
    
2048.o:2048.cpp
	$(CXX) -Wall -c -std=c++11  2048.cpp
    
modele.o:modele.cpp
	$(CXX) -Wall -c -std=c++11  modele.cpp

clean:
	rm *.o 2048 -rf 
    
