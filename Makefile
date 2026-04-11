CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -g
CFLAGS += -Wconversion -Wno-sign-compare
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
TARGET := main.exe
RM := rm -f

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean:
	$(RM) $(TARGET)

.PHONY: all clean