NAME = graphics_module
LIBFLAGS = -Llib -lSDL2main -lSDL2
DEBUG = -g
PP = g++ $(DEBUG)
CC := gcc $(DEBUG)
SRCS := $(wildcard *.c) $(wildcard *.cpp) 
OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRCS)))
HEADERS := $(wildcard *.h)

.PHONY: help all clean build ship 

help:
	@echo Makefile contains:
	@echo 
	@echo help - print this
	@echo build - build project for testing only
	@echo ship - build project and export to home/lib and home/inlude
	@echo clean - clear .o files
	@echo all - build + lship + clean

all:
	make build
	make ship
	make clean

clean: 
	rm $(wildcard *.o)

.cpp.o:
	$(PP) -c $(LIBFLAGS) $<

.c.o:
	$(CC) -c $(LIBFLAGS) $<

lib.a: $(OBJS)
	ar rcs lib.a $(OBJS)

../.lib:
	mkdir ../.lib
	
../.include:
	mkdir ../.include

build: lib.a | ../.lib ../.include
	mv lib.a ../.lib/lib$(NAME).a
	cp $(HEADERS) ../.include/
	if [ -d ".include" ]; then \
        cp -r .include/* ../.include/; \
    fi
	if [ -d ".lib" ]; then \
        cp .lib/* ../.lib/; \
    fi

ship: build
	mv lib.a ~/lib/lib$(NAME).a
	rm -rf ~/include/$(NAME)
	mkdir ~/include/$(NAME)
	cp $(HEADERS) ~/include/$(NAME)/
