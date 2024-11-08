CC = gcc
CFLAGS = -Wall -g
TARGET = home_task_7

all: $(TARGET)

$(TARGET): c_list.o main.o
	$(CC) -o $(TARGET) c_list.o main.o

c_list.o: c_list.c c_list.h
	$(CC) $(CFLAGS) -c c_list.c

main.o: main.c c_list.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(TARGET) *.o
