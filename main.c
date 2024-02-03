# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "word_count.h"

#define BUFF_LEN 1000


int main(int argc, char argv[]) {
	FILE *file;	

	if (argc > 1) {
		puts("Hello from argc > 1 block");	
	}
	else {
		file = stdin;
		word_counter(file, 1);
	}

	if (file != stdin) {
		free(file);
	}

	return 0; }

/* 
void reset_buffer(char *buffer, int len); 

void see_buffer(char *buffer, int len); 
 
void see_word_frequency(WordCount *words);

int main(int n, char *argc[]) {
	WordCount *words;
	int wc = 0;
	char buffer[BUFF_LEN+1];
	char c;
	int counter = 0;

	Word *wd = NULL;
	
	reset_buffer(buffer, BUFF_LEN+1);

	if (n < 2) {
		while((c = getchar()) != EOF && counter < BUFF_LEN+1) {
			if (counter == BUFF_LEN) {
				words = word_count(buffer, counter);
				//wc = wc + word_count(buffer, counter).total_wc;
				wc = wc + words->total_wc;
				printf("word_count: %d \n", wc);
				reset_buffer(buffer, BUFF_LEN+1);
				counter = 0;
				continue;
			}

			buffer[counter] = c;								
			counter++;
		}
		
		if (counter != 0) {
		//	wc = wc + word_count(buffer, counter);
			words = word_count(buffer, counter);
			wc = wc + words->total_wc;
			reset_buffer(buffer, BUFF_LEN+1);
		}
		printf("word_count: %d \n", wc);
	}

	see_word_frequency(words);

	
	return 0;
}

void reset_buffer(char *buffer, int len) {
	char *temp;
	temp = buffer;
	for (int i = 0; i < len; ++i) {
		temp[i] = '\0';
	}
}

void see_buffer(char *buffer, int len) {
	char *temp;
	temp = buffer;
	puts("Character's in buffer:");
	for (int i = 0; i < len; ++i ) {
		printf("%c", *temp);
		temp++;
	}
	puts("");
}

void see_word_frequency(WordCount *words) {
	Word *ptr = words->words_freq;
	while (ptr->next_word != NULL) {
		printf("%s\t%d\n", ptr->word, ptr->freq);
		ptr = ptr->next_word;
	}
	printf("%s\t%d\n", ptr->word, ptr->freq);
}
*/
