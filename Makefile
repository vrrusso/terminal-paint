all:
	gcc *.c -lm -Wall -o t
run:
	./t
clear:
	rm t *.pgm