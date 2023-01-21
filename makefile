MAKEFLAGS += --silent

CC = g++
CFLAGS = -g -I.

compile:
	@echo "Compile from source."
	$(CC) main.cpp $(CFLAGS) -o main
	@echo "Done."

clean:
	rm -f main primes.txt
