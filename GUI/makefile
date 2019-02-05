# change application name here (executable output name)
TARGET=mybatmax

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS1=main.o
OBJS2=mybatmax.o

all: $(OBJS1) $(OBJS2)
	$(LD) -o $(TARGET) $(OBJS1) $(OBJS2) $(LDFLAGS)
	rm -f *.o
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o
	
mybatmax.o: src/mybatmax.c
	$(CC) -c $(CCFLAGS) src/mybatmax.c $(GTKLIB) -o mybatmax.o
    
clean:
	rm -f *.o $(TARGET)
