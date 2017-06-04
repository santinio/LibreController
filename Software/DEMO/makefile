CC=gcc
CFLAGS=-g -Wall -O0 -DDEMO
LIBRARY_PATH=../src/
FILES= main.c ../common/debug.c
TARGET = DEMO

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES) -I -I../common

clean:
	rm -f *.o core
	rm $(TARGET)
