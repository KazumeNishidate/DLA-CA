CC= gcc
CFLAGS= -O2 -Wall

INC=  -I/usr/include/X11R5 -I/usr/include/X11 -I/usr/X11R6/include/X11  -I/opt/X11/include -I/usr/local/include
LIBS= -leggx -L/usr/X11R6/lib -lX11 -lgsl -lgslcblas -lm

SOURCES= init.c main.c ran.c control.c dynamics.c egg.c 
OBJECTS= init.o main.o ran.o control.o dynamics.o egg.o 

TARGET= dla

.c.o	:$(SOURCES)
	$(CC) -c $(CFLAGS) $(INC) $(RUN_OPTIONS) $< -o $@ 

$(TARGET)	:$(OBJECTS)
	$(CC) $(CFLAGS) $(RUN_OPTIONS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean	:
	rm -f $(OBJECTS) *.core core $(TARGET) a.out *~ "#"*

lint	:
	lint -cbx $(SOURCES)
