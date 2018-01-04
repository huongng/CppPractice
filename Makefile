CC = g++
CFLAGS = -Wall -g
OBJS = permutationBalanceParens.cpp
EXE = exe
all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)
clean :
	rm $(EXE) *~
