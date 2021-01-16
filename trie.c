#include "trie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ABC ((int)26)
#define WORD 30

node* _alloc() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}


void addWord(node* head, char* str) {
	node* current = head;
	while (*str) {
		char thechar = *str;
		if (thechar >= 65 && thechar <= 92)
		{
			thechar = thechar + 32;
		}
		if (current->children[thechar - 97] == NULL) {
			current->children[thechar - 97] = (node*)calloc(1, sizeof(node));
			current->children[thechar - 97]->letter = thechar;
			strcpy(current->children[thechar - 97]->word, current->word);
			int index_last = strlen(current->children[thechar - 97]->word);
			current->children[thechar - 97]->word[index_last] = thechar;
		}
		current = current->children[thechar - 97];
		str++;
	}
	current->count++;

}

void freeAll(node* head) {
	if (head == NULL)
		return;
	for (int i = 0; i < ABC; i++)
	{
		freeAll(head->children[i]);
	}
	free(head);
	return;
}


void printAll(node* head, int sortabc) {
	if (head == NULL)
		return;
	if (head->count >0)
		printf("%s\t%ld\n", head->word, head->count);

	if (sortabc == 1) {
		for (int i = 0; i < ABC; i++)  // z to a
			printAll(head->children[i], 1);
	}
	if (sortabc == 0)
	{
		for (int i =0; i <= ABC - 1; i++)   //regular print (a to z)
			printAll(head->children[ABC - 1-i], 0);
	}

}













