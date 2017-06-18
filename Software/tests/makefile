CC=gcc
CFLAGS=-g -Wall -O0 -DDEMO -DMAX_CHANNELS=10 -DDEBUG_LEVEL=DEBUG_NOTE
LIBRARY_PATH=../src/
FILES= testFilters.c \
../common/debug.c \
../common/controller.c \
../common/controls.c \
../common/filters.c \
../common/memory-buffers/src/bufferMemory.c \

LIBS = -lpthread \


TARGET = DEMO

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) -pthread $(CFLAGS) -o $(TARGET) $(FILES) -I -I../common -I../common/memory-buffers/src

clean:
	rm -f *.o core
	rm $(TARGET)
