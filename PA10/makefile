CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

PA10 : PA10.o MedType.o SimpleTimer.o
	$(CC) $(LFLAGS) PA10.o MedType.o SimpleTimer.o -o PA10

PA10.o : PA10.cpp HashClass.h HashClass.cpp MedType.h MedType.cpp SimpleVector.h SimpleVector.cpp SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) PA10.cpp

BSTClass.o : HashClass.h HashClass.cpp SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) HashClass.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

SimpleVector.o : SimpleVector.h SimpleVector.cpp
	$(CC) $(CFLAGS) SimpleVector.cpp

MedType.o : MedType.h MedType.cpp
	$(CC) $(CFLAGS) MedType.cpp

clean:
	\rm *.o PA10

