#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

#include "./Status.h"

typedef  int Element_Type;

typedef struct {
    Element_Type *elem;
    int length;
    int listsize;
}SqList;


Status InitList(SqList* L);

void DestoryList(SqList* L);

void CleanList(SqList* L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i , Element_Type* e);

int LocateElem(SqList L, Element_Type e, Status(Compare)(Element_Type, Element_Type));

Status PriorElem(SqList L , Element_Type cur_e, Element_Type* e);

Status NextElem(SqList L , Element_Type cur_e, Element_Type* e);

Status ListInsert(SqList *L, int i ,Element_Type e);

Status ListDelete(SqList *L, int i, Element_Type* e);

Status ListTravse(SqList L, void(Visit)(Element_Type));










#endif // SEQUENCELIST_H_INCLUDED
