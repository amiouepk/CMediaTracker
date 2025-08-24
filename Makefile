CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -g -Wextra
DEST_DIR = /mnt/c/Users/anish/OneDrive/Desktop/Code/mediaProject

make:
	$(CC) main.c -o program.exe
	mv program.exe $(DEST_DIR)

clean:
	rm $(DEST_DIR)/program.exe