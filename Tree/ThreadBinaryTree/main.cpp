#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

typedef enum{Link, Thread} PointerTag;
typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree;

BiThrTree pre;



void CreateBiThrTree(BiThrTree *T){

	char ch;

	cin>>ch;
	if(ch == '^')
		*T = NULL;
	else{
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        if(!(*T))
			exit(0);
		(*T)->data = ch;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
		}
}

void InThreading(BiThrTree T){
	if(T){
		InThreading(T->lchild);
		if(!T->lchild){
			T->ltag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild){
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

void InOrderThreading(BiThrTree *p, BiThrTree T){
	*p = (BiThrNode *) malloc(sizeof(BiThrNode));
	(*p)->ltag =Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(!T){
		(*p)->lchild = *p;
	}
	else{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void visit(char c){
	cout<<c<<endl;
}

void InOrderTraverse(BiThrTree T){
	BiThrTree p;
	p = T->lchild;
	while(p!=T){
		while(p->ltag==Link){
			p = p->lchild;
		}
		visit(p->data);
		while(p->rtag == Thread && p->rchild !=T){
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}



int main()
{
		BiThrTree p,T=NULL;
		CreateBiThrTree(&T);
		InOrderThreading(&p,T);
		cout<<"中序遍历的结果为："<<endl;
		InOrderTraverse(p);
		cout<<endl;
		return 0;
}
