# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "word_count.h"


int main(int argc, char *argv[]) {
	FILE *file;	
	char flag[3] = "-f";

	if (argc > 1) {
		if (strcmp(argv[1], flag) == 0) {
			file = fopen(argv[2], "r");
			if (file == NULL) {
				puts("Error: File can't be open");
			}
			word_counter(file, 1);	
		}
		else {
			file = fopen(argv[1], "r");
			if (file == NULL) {
				puts("Error: File can't be open");
			}
			word_counter(file, 0);
		}
	}
	else {
		file = stdin;
		word_counter(file, 1);	
	}

	if (file != stdin) {
		free(file);
	}

	return 0;
}

