#ifndef TRIE_H_
#define TRIE_H_
#define ABC ((int)26)
#define WORD 30


typedef struct node {
	char letter;
	char word[WORD];
	long unsigned int count;
	struct node* children[ABC];
} node;

typedef enum { FALSE = 0, TRUE = 1 } boolean;

node* _alloc();
void addWord(node* head, char* str);
void freeAll(node* head);
void printAll(node* head, int sortabc);



#endif /* TRIE_H_ */