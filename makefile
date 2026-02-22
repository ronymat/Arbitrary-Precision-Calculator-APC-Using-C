apc.exe : main.o function.o addition.o subtraction.o multiplication.o division.o printlist.o
	gcc -o apc.exe main.o function.o addition.o subtraction.o multiplication.o division.o printlist.o
main.o:main.c 
	gcc -c main.c 
function.o:function.c 
	gcc -c function.c 
addition.o:addition.c 
	gcc -c addition.c 
subtraction.o:subtraction.c 
	gcc -c subtraction.c 
multiplication.o:multiplication.c 
	gcc -c multiplication.c 
divisuion.o:division.c 
	gcc -c division.c 
printlist.o:printlist.c
	gcc -c printlist.c	
clean:
	rm*.exe*.o