CXX=g++
CFLAGS = -g -Wall -pedantic -Wno-sign-compare -Wno-unused-value -std=c++11 -DNDEBUG -D_FORTIFY_SOURCE=2 -O2 -isystem /opt/conda/include -Wl,-O2 -Wl,--sort-common -Wl,--as-needed -Wl,-z,relro -Wl,-z,now -Wl,--disable-new-dtags -Wl,--gc-sections -Wl,-rpath,/opt/conda/lib -Wl,-rpath-link,/opt/conda/lib -L/opt/conda/lib

2048:2048.o modele.o
	$(CXX)  2048.o -lncurses modele.o -o 2048
    
2048.o:2048.cpp
	$(CXX) ${CFLAGS} -c  2048.cpp 
    
modele.o:modele.cpp
	$(CXX) ${CFLAGS} -c  modele.cpp

clean:
	rm *.o 2048 -rf 
    
