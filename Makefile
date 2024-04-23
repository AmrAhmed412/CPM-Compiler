all: a.exe

a.exe: y.tab.c lex.yy.c
    gcc y.tab.c lex.yy.c -o a.exe

y.tab.c: Parser.y
    bison --yacc Parser.y -d

lex.yy.c: Lexer.l
    flex Lexer.l

clean:
    rm -f a.exe y.tab.c lex.yy.c y.tab.h

.PHONY: all clean