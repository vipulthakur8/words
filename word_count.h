
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <stdio.h>
#define CHAR_LIMIT 50

typedef struct token {
	int freq;
	char word[CHAR_LIMIT];
} Token;

void word_counter(FILE *file, int flag);

void reset_word(char word[], int len);

#endif
