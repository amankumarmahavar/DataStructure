#ifndef STATICLINKEDLIST_H_INCLUDED
#define STATICLINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

#define MAXSIZE 100


typedef int SLinkList;
typedef int ElemType;
typedef struct{
	ElemType data;
	int cur;						//Set a cursor as pointer
}Component[MAXSIZE];

Component SPACE;

void InitSpace();

int Malloc();

void Free(int k);

Status InitList(SLinkList *H);

Status ClearList(SLinkList H);

void DestroyList(SLinkList *H);

Status ListEmpty(SLinkList H);

int ListLength(SLinkList H);

Status GetElem(SLinkList H, int i, ElemType *e);

int LocateElem(SLinkList H, ElemType e);

Status PriorElem(SLinkList H, ElemType cur_e, ElemType *e);

Status NextElem(SLinkList H, ElemType cur_e, ElemType *e);

Status ListInsert(SLinkList H, int i, ElemType e);

Status ListDelete(SLinkList H, int i ,ElemType *e);

Status ListTraverse(SLinkList H, void(Visit)(ElemType e));

Status GetMidNode(SLinkList H, ElemType *e);

void difference(SLinkList *S, ElemType A[], int len_a, ElemType B[], int len_b);
#endif // STATICLINKEDLIST_H_INCLUDED
