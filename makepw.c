/*
 ============================================================================
 Name        : makepw
 Author      : Murat Çileli
 Version     : 1.0
 Copyright   : GNU General Public License v3.0
 Description : Simple password generator.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define uchar unsigned char

const char* pw(uchar lower, uchar upper, uchar count) {
	char chr[2];
	char *pass = malloc(count + 1);
	for (uchar i = 0; i < count; i++) {
		uchar num = (rand() % (upper - lower + 1)) + lower;
		sprintf(chr, "%c", num);
		strcat(pass, chr);
	}
	return pass;
}

int main(int argc, char **argv) {
	uchar count = 12;
	if (argc > 1) {
		count = atoi(argv[1]);
	}
	srand(time(0));
	for (uchar i = 0; i < 30; i++) {
		if (i != 0 && i % 6 == 0) {
			printf("\n");
		}
		printf("%s\t", pw(65, 122, count));
	}
	printf("\n");
	return EXIT_SUCCESS;
}
