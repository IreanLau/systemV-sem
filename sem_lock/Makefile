BIN = libsem_lock.a
SRC = sem_lock.c
OBJ=$(SRC:.c=.o)
CC = gcc
AR=ar
FLAGS =#-g -D_DEBUG_
$(BIN):$(OBJ)
	$(AR) -rc $@ $^ $(FLAGS)
$(OBJ):$(SRC)
	$(CC) -c -o $@ $^

.PHONY:clean
clean:
	rm -rf $(BIN) $(OBJ) lib sem_lock

.PHONY:output
output:
	mkdir lib 
	cp sem_lock.h lib
	cp $(BIN) lib

	
