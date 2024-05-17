NAME=electric01
CC=gcc
CFLAGS=$(shell pkg-config --cflags raylib) -Wall -g
LDFLAGS=$(shell pkg-config --libs raylib) -lm
OBJECTS=$(NAME).o particle.o field.o vec2d.o

$(NAME): $(OBJECTS)

clean:
	rm -f $(NAME) $(OBJECTS)

.PHONY: clean

include Makefile.dep
