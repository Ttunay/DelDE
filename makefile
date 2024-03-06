CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

SRCS = ubuntu.c arch.c
OBJS = $(SRCS:.c=.o)
TARGET = DE

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
