# include <stdio.h>
# include "word_count.h"

#define BUFF_LEN 1000

void reset_buffer(char *buffer, int len); 

void see_buffer(char *buffer, int len); 

int main(int n, char *argc[]) {
	int wc = 0;
	char buffer[BUFF_LEN+1];
	char c;
	int counter = 0;

	reset_buffer(buffer, BUFF_LEN+1);

	if (n < 2) {
		while((c = getchar()) != EOF && counter < BUFF_LEN+1) {
			//printf("%c\n", c);
			buffer[counter] = c;								
			counter++;
		}

		see_buffer(buffer, counter);
		wc = word_count(buffer, counter);
		printf("word_count: %d \n", wc);
		reset_buffer(buffer, BUFF_LEN+1);
		see_buffer(buffer, counter);
	}
	
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
