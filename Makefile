CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -O2
LDFLAGS =

ifeq ($(OS),Windows_NT)
RM = cmd /C del /Q /F
else
RM = rm -f
endif

SRCDIR = src
TARGET = fctr

SRCS = $(SRCDIR)/main.c $(SRCDIR)/fctr.c $(SRCDIR)/data.c
OBJS = main.o fctr.o data.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(RM) $(OBJS)

%.o: $(SRCDIR)/%.c $(SRCDIR)/fctr.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-$(RM) $(OBJS) $(TARGET) $(TARGET).exe
