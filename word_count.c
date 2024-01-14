#include<stdio.h>
#include<ctype.h>
#include "./word_count.h"

int word_count(char string[], int len) {
	int wc = 0;	
	static Word *head = NULL;
	int w = 0;
	int counter = 0;

	while (counter <= len) {
		if (isalpha(string[counter])) {
			w = counter+1;
			while(isalpha(string[w])) {
				w++;		
			}
			wc++;	
			counter = w;	
		}
		counter++;
	}
	return wc;
}
