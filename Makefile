CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -g -Wextra
TARGET = program.exe
OBJS = print_help.o main.o 

SDL_LIBS = -lSDL2main -lSDL2

DEST_DIR = /mnt/c/Users/anish/OneDrive/Desktop/Code/mediaProject

make: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -mconsole 
	mv $(TARGET) $(DEST_DIR)

#make_file: $(CC) file_help.c -o file_help.o

main.o:
	$(CC) main.c -o main.o 


print_help.o:
	$(CC) print_help.c -o print_help.o $(SDL_LIBS)



clean:
	rm $(DEST_DIR)/program.exe