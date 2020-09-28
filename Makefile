CFLAGS = -c -Wall -Werror
OBJECTS = build/src/main.o build/src/verb_functions.o build/src/random_numbers.o build/src/irrverbs.o
TESTOBJ = build/test/main.o build/test/verb_functions.o build/test/random_numbers.o build/test/irrverbs.o
TARGET = iv
PREFIX = bin

all: install test

irrverbs.o: src/irrverbs.c
	gcc $(CFLAGS) src/irrverbs.c -o build/src/irrverbs.o
random_numbers.o: src/random_numbers.c
	gcc $(CFLAGS) src/random_numbers.c -o build/src/random_numbers.o
verb_functions.o: src/verb_functions.c
	gcc $(CFLAGS) src/verb_functions.c -o build/src/verb_functions.o
main.o: src/main.c
	gcc $(CFLAGS) src/main.c -o build/src/main.o
iv_test.o: test/iv_test.c
	gcc $(CFLAGS) -I thirdparty -I src test/iv_test.c -o build/test/iv_test.o
build/test/main.o: test/main.c
	gcc $(CFLAGS) -I thirdparty test/main.c -o build/test/main.o
install: main.o irrverbs.o random_numbers.o verb_functions.o
	gcc $(OBJECTS) -o $(PREFIX)/$(TARGET)
clean:
	rm $(OBJECTS)
	rm bin/*
	rm build/test/*
	rm build/src/*
run:
	bin/iv
runt:
	bin/test
test: iv_test.o build/test/main.o irrverbs.o random_numbers.o verb_functions.o
	gcc build/test/main.o build/test/iv_test.o  build/src/random_numbers.o build/src/irrverbs.o build/src/verb_functions.o -o bin/test
