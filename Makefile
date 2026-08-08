CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = myeditor

SRC = $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)