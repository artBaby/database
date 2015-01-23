#ifndef TREAP_H
#define TREAP_H

#include "main.h"
typedef kvp_t* KEY_TYPE;

typedef struct treap_t
{
	KEY_TYPE key;
	int priority;
	struct treap_t* leftChild;
	struct treap_t* rightChild;
} treap_t;

treap_t *Create_Node(KEY_TYPE key);
treap_t *Right_turn(treap_t *x);
treap_t *Left_turn(treap_t *x);
treap_t *Insert(KEY_TYPE key, treap_t *root);
void Deleting(char* key, treap_t **Root);
void InOrder(treap_t *root);
void PrintMe (treap_t *Root);	
treap_t *GetValue(char* key, treap_t *root);
#endif
