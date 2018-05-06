#include <stdio.h>
#include <stdlib.h>
#include "./Merge.h"

Status InitList(SqList* L){
	L->elem = (ElementType *) malloc(LIST_INIT_SIZE * sizeof(ElementType));
	if(! L->elem)
		exit(OVERFLOW);

	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

void ClearList(SqList* L){
	L->length = 0;
}

void DestoryList(SqList* L){
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

Status ListEmpty(SqList L){
	return L.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList L){
	return L.length;
}

Status GetElem(SqList L, int i , ElementType* e){
	if(i<1 || i>L.length)
		return ERROR;
	else
		*e = L.elem[i-1];
	return OK;
}

int LocateElem(SqList L, ElementType e, Status(Compara)(ElementType, ElementType)){
	int i =1;

	while(i<=L.length && !(Compara)(e , L.elem[i-1]))
		i++;

    if(i<=L.length)
		return i;
	else
		return ERROR;

}

Status PriorElem(SqList L,ElementType cur_e, ElementType* e){
	if(cur_e == L.elem[1])
		return ERROR;
	else
		*e = L.elem[cur_e-1];

	return OK;
}

Status NextElem(SqList L, ElementType cur_e, ElementType* e){
	if(cur_e ==L.elem[L.length-1])
		return ERROR;
	else
		*e = L.elem[cur_e+1];

	return OK;
}

Status ListTraver(SqList L, void(Visit)(ElementType)){
	int i;
	for(i =0; i<L.length; i++)
		Visit(L.elem[i]);
	return OK;
}

Status InsertElem(SqList *L, int i , ElementType e){
	ElementType *newbase;
	ElementType *p,*q;
	if(i<1 || i>L->length+1)
		return ERROR;

	if(L->length > L->listsize)
	{
		newbase = (ElementType *) realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(ElementType));
        if(!newbase)
			exit(0);
        L->elem = newbase;
        L ->listsize += LISTINCREMENT;
	}

	p = &L->elem[i-1];
	q = &L->elem[L->length-1];

	for(; q>=p; q--)
		*(q+1)=*q;

	*p = e;
	L->length++;
	return OK;
}

Status DeleteElem(SqList* L,  int i ,ElementType* e){
	ElementType *q, *p;
	if(i<1 || i> L->length)
		return ERROR;

	p = &L->elem[i-1];
	e = p;
	q = L->elem + L->length - 1;

	for(++p; p<=q; ++p)
		*(q-1)=*q;

	L->length--;
	return OK;
}
