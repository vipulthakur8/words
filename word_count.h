
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

typedef struct word {
	char word[20];
	int freq;
} Word;

typedef struct word_count {
	int wc;
	Word *next;
} WordCount;

int word_count(char string[], int len);

int wordcount_sort(char string[], int len);

int wordcount_less();

#endif
