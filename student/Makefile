#compiler
CC= cc 
#objects
OBJS= my_string.o ArrayList.o tokenizer.o

#

#compiler flags -g for debug -O3 for optimization
CFLAGS= -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
        -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: main

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

main: ${OBJS} main.o 
	${CC} -o $@ $^

run: main
	./main

clean:
	rm -f *.o main

my_string.o: my_string.h
ArrayList.o: ArrayList.h
tokenizer.o: tokenizer.h
main.o: main.c