$(CC) = gcc
rate:
	$(CC) ratemono_aux.c mono.h  ratemono.c -o rate

Clean:
	rm *.o rate rate_mlaj.out