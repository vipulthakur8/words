
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

typedef struct word {
	char word[20];
	int freq;
	struct word *next_word;
} Word;

typedef struct word_count {
	int total_wc;
	Word *words_freq;
} WordCount;

WordCount *word_count(char string[], int len);

void freq_counter(WordCount *wc, char subStr[], int n);

int wordcount_sort(char string[], int len);

int wordcount_less();

#endif
