module load sw/compiler/gcc530
sw5g++ -mhost  -std=c++11 -I/usr/sw-mpp/mpi2/include -c main.cpp ./QRunesParser/*.cpp 
#sw5cc -slave -c slave.c
#mpiswg++ -I/usr/sw-mpp/mpi2/include *.cpp -o QVM
mpiswg++ -std=c++11 *.o  -o QVM
