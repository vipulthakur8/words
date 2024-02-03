
TARGETS = word

word: main.c word_count.h word_count.c 
	gcc main.c word_count.h word_count.c -o word

clean:
	rm $(TARGETS) 


