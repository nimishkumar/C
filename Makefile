CC=gcc
CFLAGS=-Wall -g
TARGET=test

default: compile

compile: $(TARGET).c
	@$(CC) $(CFLAGS) *.c -o $(TARGET)

clean:
	@rm -f $(TARGET)

run: test
	@./$(TARGET)
