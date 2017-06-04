CC=gcc
CFLAGS=-g -Wall -O0 -DDEMO -DMAX_CHANNELS=10
LIBRARY_PATH=../src/
FILES= main.c \
../common/debug.c \
../common/controller.c \
../common/controls.c \
../common/memory-buffers/src/bufferMemory.c \
./adc.c \

TARGET = DEMO

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES) -I -I../common -I../common/memory-buffers/src

clean:
	rm -f *.o core
	rm $(TARGET)
