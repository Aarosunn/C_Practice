CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -g
CFLAGS += -Wconversion -Wno-sign-compare
HEADERS := $(wildcard *.h)
TARGET := main.exe
ARENA_TARGET := arena.exe
REFCOUNT_TARGET := refcount.exe
MEMLEAK_TARGET := memleak.exe
RM := rm -f

VALGRIND := valgrind 
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(TARGET) $(ARENA_TARGET) $(REFCOUNT_TARGET) $(MEMLEAK_TARGET)

$(TARGET): main.c $(HEADERS)
	$(CC) $(CFLAGS) main.c -o $@

$(ARENA_TARGET): arena.c
	$(CC) $(CFLAGS) arena.c -o $@

$(REFCOUNT_TARGET): refcount.c
	$(CC) $(CFLAGS) refcount.c -o $@

$(MEMLEAK_TARGET): memleak.c 
	$(CC) $(CFLAGS) memleak.c -o $@

debug: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

debug-arena: $(ARENA_TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(ARENA_TARGET)

debug-refcount: $(REFCOUNT_TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(REFCOUNT_TARGET)

debug-memleak: $(MEMLEAK_TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(MEMLEAK_TARGET)

clean:
	$(RM) $(TARGET) $(ARENA_TARGET) $(REFCOUNT_TARGET) $(MEMLEAK_TARGET)

.PHONY: all debug debug-arena debug-refcount debug-memleak clean