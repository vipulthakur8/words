#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "./word_count.h"

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
	if (ptr->words_freq == NULL) {
		Word *w = NULL; 
		w = (Word*)malloc(sizeof(Word));	
		strncat(w->word, subStr, n);
		w->freq = 1;
		w->next_word = NULL;
		ptr->words_freq = w;
	}
	else {
		Word *w = NULL;
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
