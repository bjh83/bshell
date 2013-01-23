PACKAGE= bshell
OBJS= main.o execute.o gram.tab.o lex.yy.o list.o
CC= gcc

.PHONY: all

all: $(PACKAGE)

$(PACKAGE): $(OBJS)
	$(CC) -o $(PACKAGE) $(OBJS)

main.o: gram.tab.h

gram.tab.o: gram.tab.c

gram.tab.c gram.tab.h: gram.y
	bison -d gram.y

lex.yy.o: lex.yy.c

lex.yy.c: lex.l
	flex lex.l

.PHONY: clean

clean:
	rm -rf $(OBJS) $(PACKAGE) gram.tab.c gram.tab.h lex.yy.c

