# cpp_compiler

To run our C+-™ Compiler, you should write these 4 commands in succession in your command prompt where the source files are stored (exclude the [no.)] from the commands):

1. bison --yacc Parser.y -d
2. flex Lexer.l
3. gcc y.tab.c lex.yy.c linked_list.c linked_list.h utils.c utils.h parameters.c parameters.h quadGen.h quadGen.c stack.h stack.c
4. a.exe
