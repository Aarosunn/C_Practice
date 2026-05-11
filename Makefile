CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -g
CFLAGS += -Wconversion -Wno-sign-compare
HEADERS := $(wildcard *.h)
TARGET := main.exe
ARENA_TARGET := arena.exe
RM := rm -f

VALGRIND := valgrind 
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(TARGET) $(ARENA_TARGET)

$(TARGET): main.c $(HEADERS)
	$(CC) $(CFLAGS) main.c -o $@

$(ARENA_TARGET): arena.c
	$(CC) $(CFLAGS) arena.c -o $@

debug: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

debug-arena: $(ARENA_TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(ARENA_TARGET)

clean:
	$(RM) $(TARGET) $(ARENA_TARGET)

.PHONY: all debug debug-arena clean