TARGET= ball-jump
CC= gcc -std=c99 -Wall -Wextra -g
SRC= $(shell ls *.c)
HDR= $(shell ls *.h)

$(TARGET): $(SRC) $(HDR)
	gcc $^ -o $@ -lGL -lGLU -lglut -lm
