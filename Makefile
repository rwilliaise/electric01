NAME=electric01
CC=gcc
CFLAGS=$(shell pkg-config --cflags raylib) -Wall -g
LDFLAGS=$(shell pkg-config --libs raylib) -lm

$(NAME): $(NAME).o vec2d.o
