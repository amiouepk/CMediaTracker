CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -g -Wextra
TARGET = program.exe
OBJS = file_help.c print_help.c main.c 

#SDL_LIBS = -lSDL2main -lSDL2

DEST_DIR = /mnt/c/Users/anish/OneDrive/Desktop/Code/mediaProject

make: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -mconsole 
	mv $(TARGET) $(DEST_DIR)

#make_file: $(CC) file_help.c -o file_help.o

# main.o:
# 	$(CC) main.c -o main.o 

# print_help.o:
# 	$(CC) print_help.c -o print_help.o 

clean:
	rm $(DEST_DIR)/program.exe