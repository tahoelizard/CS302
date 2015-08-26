CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA01.o LinkedList.o ListNode.o
	$(CC) $(LFLAGS) PA01.o LinkedList.o ListNode.o -o PA01

PA01.o : LinkedList.h
	$(CC) $(CFLAGS) PA01.cpp

LinkedList.o : LinkedList.h
	$(CC) $(CFLAGS) LinkedList.cpp

ListNode.o : ListNode.h
	$(CC) $(CFLAGS) ListNode.cpp

clean:
	\rm *.o PA01

