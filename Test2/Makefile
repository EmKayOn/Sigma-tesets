PROG = main.exe 
SRC = main.cpp CatColor.cpp
CC= g++
CFLAGS = -g
LIBS = 

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)
	
.PHONY: all clean