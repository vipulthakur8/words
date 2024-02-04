#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "./word_count.h"

void reset_word(char word[], int len) {
	for (int i = 0; i < len; ++i) {
		word[i] = '\0';
	}
}


void word_counter(FILE *file, int flag) {
	Token *token_arr = NULL;	
	char word[CHAR_LIMIT];
	int count = 0;
	int tw = 0;

	while (fscanf(file, "%49s", word) == 1) {
		int found = 0;
		for (int i = 0; i < count; ++i) {
			if (strcmp(word, token_arr[i].word) == 0) {
			//	puts("Inside if block of strcmp");
				found = 1;
				token_arr[i].freq++;	
				tw++;
				reset_word(word, CHAR_LIMIT);
				break;
			}

		}

		/* If not found in the array */
		if (!found) {
			//puts("Inside the found");
			token_arr = realloc(token_arr, (count+1)*sizeof(Token));
			strcpy(token_arr[count].word, word);
			token_arr[count].freq = 1;
			count++;
			tw++;
		}
		reset_word(word, CHAR_LIMIT);
	}

	printf("word count is %d\n", tw);
	
	if (flag == 1) {
		//printf("Frequency\tWord\n");	
		for (int i = 0; i < count; ++i) {
			printf("%d\t%s\n", token_arr[i].freq, token_arr[i].word);	
		}
	}

	free(token_arr);
	
}

