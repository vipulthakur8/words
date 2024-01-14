
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

typedef struct word {
	int freq;
	char word[20];
	struct word *next;
} Word;

int word_count(char string[], int len);

#endif
