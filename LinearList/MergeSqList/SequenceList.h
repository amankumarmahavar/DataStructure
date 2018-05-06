#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "./Status.h"

typedef int ElementType;

typedef struct{
	ElementType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList* L);

void DestoryList(SqList* L);

void ClearList(SqList* L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i , ElementType* e);

int LocateElem(SqList L,ElementType e, Status(compara)(ElementType, ElementType));

Status PriorElem(SqList L, ElementType cur_e, ElementType* e);

Status NextElem(SqList L, ElementType cur_e, ElementType* e);

Status InsertElem(SqList* L, int i, ElementType e);

Status DeleteElem(SqList* L,  int i ,ElementType* e);

Status ListTraver(SqList L,  void(Visit)(ElementType));




#endif // SEQUENCELIST_H_INCLUDED
