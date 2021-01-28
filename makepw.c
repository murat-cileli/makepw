/*
 ============================================================================
 Name        : makepw
 Author      : Murat Çileli
 Version     : 1.0
 Copyright   : MIT License
 Description : Simple password generator.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "makepw.h"

const char* pw(ushort lower, ushort upper, ushort count) {
	char chr[2];
	char *pass = malloc(count + 1);
	for (ushort i = 0; i < count; i++) {
		ushort num = (rand() % (upper - lower + 1)) + lower;
		sprintf(chr, "%c", num);
		strcat(pass, chr);
	}
	return pass;
}

int main(int argc, char **argv) {
	ushort count = 8;
	if (argc > 1) {
		count = atoi(argv[1]);
	}
	srand(time(0));
	for (ushort i = 0; i < 30; i++) {
		if (i != 0 && i % 6 == 0) {
			printf("\n");
		}
		printf("%s\t", pw(65, 122, count));
	}
	printf("\n");
	return EXIT_SUCCESS;
}
