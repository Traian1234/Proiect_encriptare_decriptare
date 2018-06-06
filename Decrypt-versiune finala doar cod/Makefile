CC=gcc

CFLAGS=-c -Wall

all: decrypt

decrypt: main.o identify.o  search_row.o print_decrypted.o 
	$(CC) main.o  identify.o  search_row.o print_decrypted.o -o decrypt
	
main.o: main.c
	$(CC) $(CFLAGS) main.c
	
identify.o: identify.c
	$(CC) $(CFLAGS) identify.c
	
search_row.o: search_row.c
	$(CC) $(CFLAGS) search_row.c
	
print_decrypted.o: print_decrypted.c
	$(CC) $(CFLAGS) print_decrypted.c
		
clean:
	rm *o decrypts