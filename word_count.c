#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "./word_count.h"


void word_counter(FILE *file, int flag) {
	Token *token_arr = NULL;	
	char word[CHAR_LIMIT];
	int count = 0;


	while (fscanf(file, "%s", word) == 1) {
		int found = 0;
		for (int i = 0; i < count; ++i) {
			if (strcmp(word, token_arr[i].word) == 0) {
			//	puts("Inside if block of strcmp");
				found = 1;
				token_arr[i].freq++;	
				break;
			}

		}

		/* If not found in the array */
		if (!found) {
			//puts("Inside the found");
			token_arr = realloc(token_arr, (count+1)*sizeof(token_arr));
			strcpy(token_arr[count].word, word);
			token_arr[count].freq = 1;
			count++;
		}
	}

	int wc = 0;
	for (int i = 0; i < count; ++i) {
		wc += token_arr[i].freq;
	}

	printf("word count is %d\n", wc);
	
	if (flag == 1) {
		//printf("Frequency\tWord\n");	
		for (int i = 0; i < count; ++i) {
			printf("%d\t%s\n", token_arr[i].freq, token_arr[i].word);	
		}
	}

	free(token_arr);
	
}

/*
WordCount *word_count(char string[], int len) {
	//int wc = 0;	
	static WordCount wc;
	wc.total_wc = 0;
	wc.words_freq = NULL;
	int counter = 0;
	int w = 0;
	int w_begin = 0;
	int w_end = 0;

	while (counter <= len) {
		if (isalpha(string[counter])) {
			w_begin = counter;
			w = counter+1;
			while(isalpha(string[w])) {
				w++;		
			}
			w_end = w;
			wc.total_wc++;	
			char subStr[(w_end - w_begin) + 1];
			for (int c = w_begin; c < w_end+1; ++c) {
				subStr[c] = string[c];
			}
			counter = w;	
		}
		counter++;
	}
	return &wc;
}

void freq_counter(WordCount *wc, char subStr[], int n) {
	WordCount *ptr = wc;
	Word *w = NULL;
	if (ptr->words_freq == NULL) {
		Word *w = NULL; 
		w = (Word*)malloc(sizeof(Word));	
		strncat(w->word, subStr, n);
		w->freq = 1;
		w->next_word = NULL;
		ptr->words_freq = w;
	}
	else {
		Word *tracker = NULL;
		tracker = ptr->words_freq;
		while (tracker->next_word != NULL) {
			if (strncmp(subStr, tracker->word, n)) {
				tracker->freq++;		
				break;
			}
			tracker = tracker->next_word;
		}
		w = (Word*)malloc(sizeof(Word));	
		strncat(w->word, subStr, n);
		w->freq = 1;
		w->next_word = NULL;
		tracker->next_word = w;
	}
}

*/
