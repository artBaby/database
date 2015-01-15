#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


typedef int KEY_TYPE;

typedef struct treap_t
{
	KEY_TYPE key;
	int priority;
	struct treap_t* leftChild;
	struct treap_t* rightChild;
} treap_t;

treap_t *Create_Node(KEY_TYPE key)
{
	treap_t *p_node = (treap_t *)malloc(sizeof(treap_t));
	if(!p_node)
	{
		fprintf(stderr, "Memory error!\n");
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	p_node->key = key;	
	p_node->priority = 0 + rand() %100;	
	p_node->rightChild = p_node->leftChild = NULL;

	return p_node;
}

treap_t *Right_turn(treap_t *x)
{
	treap_t *y = x->leftChild;
	x->leftChild = y->rightChild;
	y->rightChild = x;
	return y;
}

treap_t *Left_turn(treap_t *x)
{
	treap_t *y = x->rightChild;
	x->rightChild = y->leftChild;
	y->leftChild = x;
	return y;
}

treap_t *Insert(KEY_TYPE key, treap_t *root)
{
	treap_t *p_node = Create_Node(key);
	if(!root)
	{
		return (root = p_node);
	}
	if(key <= root->key)
	{
		root->leftChild = Insert(key, root->leftChild);
		if(root->leftChild->priority < root->priority)
		{
			root = Right_turn(root);
		}
	}
	else
	{
		root->rightChild = Insert(key, root->rightChild);
		if(root->rightChild->priority < root->priority)
		{
			root = Left_turn(root);
		}
	}
	return root;
}

void Deleting(KEY_TYPE key, treap_t *&Root)
{
	treap_t *father = NULL;
	treap_t *root = Root;
	if(!root)
	{
		printf("Deleting error. Treap is empty.\n");
		return;
	}
	while(root)
	{
		if(key < root->key)
		{
			father = root;
			root = root->leftChild;
		}
		else if(key > root->key)
		{
			father = root;
			root = root->rightChild;
		}
		else
		{
			if(!root->leftChild)  // root's left child is empty
			{
				if(!father)
				{
					Root = root->rightChild;
				}
				else
				{
					if(father->leftChild == root)
					{
						father->leftChild = root->rightChild;
					}
					else
					{
						father->rightChild = root->rightChild;
					}
				}
			}
			else if(!root->rightChild)   
			{
				if(!father)
				{
					Root = root->leftChild;
				}
				else
				{
					if(father->leftChild == root)
					{
						father->leftChild = root->leftChild;
					}
					else
					{
						father->rightChild = root->leftChild;
					}
				}
			}
			else 
			{
				while(root->leftChild && root->rightChild)
				{
					if(root->leftChild->priority < root->rightChild->priority)
					{
						if(!father)
						{
							Root = Right_turn(root);
							father = Root;
						}
						else
						{
							if(father->leftChild == root)
							{
								father->leftChild = Right_turn(root);
								father = father->leftChild;
							}
							else
							{
								father->rightChild = Right_turn(root);
								father = father->rightChild;
							}
						}
					}
					else
					{
						if(!father)
						{
							Root = Left_turn(root);
							father = Root;
						}
						else
						{
							if(father->leftChild == root)
							{
								father->leftChild = Left_turn(root);
								father = father->leftChild;
							}
							else
							{
								father->rightChild = Left_turn(root);
								father = father->rightChild;
							}
						}
					}
				}
				if(!root->leftChild)
				{
					if(father->leftChild == root)
					{
						father->leftChild = root->rightChild;
					}
					else
					{
						father->rightChild = root->rightChild;
					}
				}
				else   // root правый ребенок = null
				{
					if(father->leftChild == root)
					{
						father->leftChild = root->leftChild;
					}
					else
					{
						father->rightChild = root->leftChild;
					}
				}
			}
			free(root);
			return;
		}
	}
	printf("Invalid key\n");
}
