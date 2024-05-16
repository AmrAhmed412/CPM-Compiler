all: a.exe

a.exe: y.tab.c lex.yy.c linked_list.c linked_list.h utils.c utils.h parameters.c parameters.h 
    gcc y.tab.c lex.yy.c linked_list.c linked_list.h utils.c utils.h parameters.c parameters.h -o a.exe

y.tab.c: Parser.y
    bison --yacc Parser.y -d

lex.yy.c: Lexer.l
    flex Lexer.l

clean:
    rm -f a.exe y.tab.c lex.yy.c y.tab.h

.PHONY: all clean