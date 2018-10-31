CC=gcc
CFLAGS=-lWarn -pedantic

all:    tester irtester blink button

tester: tester.o libmyifttt.a
	cc tester.o -L. -lmyifttt -lcurl -o tester

irtester: irtester.o libmyifttt.a
	cc irtester.o -lwiringPi -L. -lmyifttt -lcurl -o irtester

irtester.o: irtester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

blink: blink.o 
	cc blink.o -lwiringPi -o blink

button: button.o 
	cc button.o -lwiringPi -o button

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm tester irtester *.o
