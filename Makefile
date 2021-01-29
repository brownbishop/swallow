CC=g++
CPPFLAGS=-lX11 -Wall -Wextra -fPIE -O2 -D_FORTIFY_SOURCE=2
SOURCE=swallow.cpp 
TARGET=swallow 
PREFIX=/usr/bin/

build: $(TARGET) 
	$(CC) $(CPPFLAGS) $(SOURCE) -o $(TARGET) 

install: build 
	cp $(PREFIX)$(TARGET)

uninstall: 
	rm -f $(PREFIX)$(TARGET)

clean: 
	rm -f $(TARGET)

.PHONY: install uninstall clean
