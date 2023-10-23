# -*- Makefile -*-

datamem: datamem.o hexdump.o
	gcc datamem.o hexdump.o -o datamem

datamem.o: datamem.c ../hexdump/hexdump.h
	gcc -c datamem.c

hexdump.o: ../hexdump/hexdump.c
	gcc -c ../hexdump/hexdump.c

clean:
	rm -f *.o datamem
