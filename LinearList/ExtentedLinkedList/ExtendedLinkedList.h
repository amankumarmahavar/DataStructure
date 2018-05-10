#ifndef EXTENDEDLINKEDLIST_H_INCLUDED
#define EXTENDEDLINKEDLIST_H_INCLUDED

#include "./Status.h"

typedef int ElemType;
typedef struct LNode{
	ElemType      data;
	struct LNode *next;
}LNode, *Link, *Position;

//typedef LNode *Link;
//typedef LNode *Position;
typedef struct{
	Link head, tail;
	int length;
}LinkList;

Status MakeNode(Link *p, ElemType e);

void FreeNode(Link *p);

Status InitList(LinkList *L);

void ClearList(LinkList *L);

void DestrosyList(LinkList *L);

void InsFirst(LinkList *L, Link h, Link s); //h指向L中的头节点将s插入到“第一个结点”之前

Status DelFirst(LinkList *L, Link h, Link *q);

void Append(LinkList *L, Link s);

Status Remove(LinkList *L, Link *q);

void InsBefore(LinkList *L, Link *p, Link s);

void InsAfter(LinkList *L, Link *p, Link s);

ElemType GetCurElem(Link p);

void SetCurElem(Link p, ElemType e);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Position GetHead(LinkList L);

Position GetLast(LinkList L);

Position PriorPos(LinkList L, Link p);

Position NextPos(Link p);

Status LocatePos(LinkList L, int i, Link *p);

Position LocateElem(LinkList L, ElemType e, Status(Comprarr)(ElemType, ElemType));

Status ListInsert(LinkList *L, int i, ElemType e);

Status ListDelete(LinkList *L, int i, ElemType *e);

Status ListTraverse(LinkList L, void(Visit)(ElemType));






#endif // EXTENDEDLINKEDLIST_H_INCLUDED
