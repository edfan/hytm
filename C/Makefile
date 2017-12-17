# Source, Executable, Includes, Library Defines
#INCL   = loop.h defs.h
TARGET := main
SRC    = transcational_memory.c main.c 
OBJ := $(SRC:.c=.o)
UNAME := $(shell uname)

# Compiler, Linker Defines
CC      = gcc
CFLAGS := -std=gnu99 -Wall -g
LDFLAGS= -Wall -lm -lrt -ldl -maes -mpclmul -mssse3 -pthread


.PHONY : default clean
default : $(TARGET)

# Each C source file will have a corresponding file of prerequisites.
# Include the prerequisites for each of our C source files.
-include $(SRC:.c=.d)

# This rule generates a file of dependencies (i.e., a makefile) %.d
# from the C source file %.c.
%.d : %.c
	@set -e; rm -f $@; \
	$(CC) -MM -MT $*.o -MP -MF $@.$$$$ $(CFLAGS) $<; \
	sed -e 's|\($*\)\.o[ :]*|\1.o $@ : |g' < $@.$$$$ > $@; \
	rm -f $@.$$$$*

# We could use the -MMD and -MP flags here to have this rule generate
# the dependencies file.
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
main : main.o $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@ -lrt
