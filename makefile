all: signals.o
	gcc -o signalsRUN signals.o
signals.o: signals.c
	gcc -c signals.c
clean:
	rm *.o
	rm signalsRUN
run:
	./signalsRUN