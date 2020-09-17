all: src/hello-world-gtk.c
	gcc -g -Wall `pkg-config --cflags gtk+-3.0` -o bin/hello-world-gtk src/hello-world-gtk.c `pkg-config --libs gtk+-3.0`

clean:
	$(RM) hello-world-gtk
