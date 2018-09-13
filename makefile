CC		= gcc
CFLAGS	= -g
TARGET	= ass1
OBJS	= ass1.o

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

ass1.o:	ass1.c 
	$(CC)	$(CFLAGS) -c ass1.c

clean:
		rm -f *.o $(TARGET)