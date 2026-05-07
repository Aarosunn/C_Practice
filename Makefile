CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -g
CFLAGS += -Wconversion -Wno-sign-compare
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
TARGET := main.exe
RM := rm -f

VALGRIND := valgrind 
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

debug: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

clean:
	$(RM) $(TARGET)

.PHONY: all clean