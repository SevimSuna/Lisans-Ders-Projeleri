INCLUDE = -I
LIBS = libfdr.a 

CC = gcc

EX = soru1 soru2
all: $(EX) 

soru1: soru1.o 
	$(CC) -g $(INCLUDE) -c soru1.c
	$(CC) -g -o soru1 soru1.o 

soru2: soru2.o $(LIBS)
	$(CC) -g $(INCLUDE) -c soru2.c $(LIBS)
	$(CC) -g -o soru2 soru2.o $(LIBS)



.SUFFIXES: .c .o

.c.o: 
	$(CC) $(INCLUDE) -g  -c  $*.c
		
