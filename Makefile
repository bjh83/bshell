PACKAGE= bshell
OBJS= main.o execute.o y.tab.o lex.o
CC= gcc

.PHONY: all

all: $(PACKAGE)

$(PACKAGE): $(OBJS)
	$(CC) -o $(PACKAGE) $(OBJS)

main.o: gram.tab.h

gram.tab.o: gram.tab.c
	$(CC) -c gram.tab.c

gram.tab.c gram.tab.h: gram.y
	bison gram.y

lex.o: lex.c
	$(CC) -c lex.c

lex.c: lex.l
	$(CC) flex lex.l

.PHONY: clean

clean:
	rm -rf $(OBJS) $(PACKAGE) gram.tab.c lex.c

