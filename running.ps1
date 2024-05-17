# Run bison
bison --yacc Parser.y -d

# Run flex
flex Lexer.l

# Compile the C files
gcc y.tab.c lex.yy.c linked_list.c stack.c utils.c parameters.c quadGen.c -o a.exe
