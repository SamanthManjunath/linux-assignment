CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -g
TARGET = writer

# List of object files
OBJ = writer.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

writer.o: writer.c
	$(CC) $(CFLAGS) -c -o writer.o writer.c

clean:
	rm -f $(TARGET) $(OBJ)

