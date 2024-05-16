# Bison and Flex
BISON = bison --yacc
FLEX = flex

# Target
TARGET = a.exe

SRCS = y.tab.c lex.yy.c linked_list.c utils.c parameters.c
HEADERS = linked_list.h utils.h parameters.h

CC = gcc

# Default target
all: $(TARGET)

# Compile Bison and Flex files
y.tab.c y.tab.h: Parser.y
    $(BISON) $< -d

lex.yy.c: Lexer.l
    $(FLEX) $<

# Compile source files
$(TARGET): $(SRCS) $(HEADERS)
    $(CC) $(CFLAGS) $^ -o $@

# Clean rule
.PHONY: clean
clean:
    rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c