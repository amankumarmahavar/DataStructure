#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "./Status.h"
#include "./Scanf.c"
#include "../../Stack&Queue/SequenceStack/SequenceStack.h"
typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode;


typedef BiTNode* BiTree;
typedef BiTree Elemtype;

typedef struct{
	BiTree left;
	BiTree right;
	int n;
}Node;




#endif // BINARYTREE_H_INCLUDED
