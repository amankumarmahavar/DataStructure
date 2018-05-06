#include "./DoubleLinkedList.h"

Status InitList(DLinkedList *L){
    *L = (DLinkedList)malloc(sizeof(DLinkedList));
    if(!*L)
		return OVERFLOW;
	(*L)->next = (*L)->prior =*L;
	return OK;
}

Status ClearList(DLinkedList L){
    DLinkedList p, q;

    p = L->next;
    while(p != L){
        q = p->next;
        free(p);
        p = q;
    }

    L->next = L->prior = L;
    return OK;
}

void DestroyList(DLinkedList *L){
	ClearList(*L);

	free(*L);

	*L = NULL;
}


Status ListEmpty(DLinkedList L){
    return (L && L->next == L && L->prior == L )? TRUE : FALSE;
}

int ListLength(DLinkedList L){
	if(!L)
		return ERROR;

    DLinkedList p;
	int count = 0;
    p = L;

    while(p->next != L){
        count++;
        p = p->next;
    }
    return count;
}

Status GetElem(DLinkedList L, int i, ElemType *e){
	if(!L)
		return ERROR;

    DLinkedList p;
    int count = 1;
    p = L->next;

    while(p != L && count<i){
		count++;
		p = p->next;
    }
    if(p != L){
		*e = p->data;
		return OK;
    }
	return FALSE;
}

int LocateElem(DLinkedList L, ElemType e, Status(Compara)(ElemType, ElemType)){
	if(!L)
		return ERROR;
	DLinkedList p;
	int count = 1;
    p = L->next;

    while(p!=L && !Compara(e, p->data)){
		count++;
		p = p->next;
    }

    if(p != L)
		return count;

	return 0;
}

Status PriorElem(DLinkedList L, ElemType cur_e, ElemType *e){
    DLinkedList p ;
    if(L){
        p = L->next;

        while(p!=L && p->data != cur_e)
			p = p->next;

        if(p != L && p->prior != L)
			*e = p->prior->data;
		return OK;
    }
    return ERROR;
}

Status NextElem(DLinkedList L, ElemType cur_e, ElemType *e){
    DLinkedList p ;
    if(L){
        p = L->next;

        while(p!=L && p->data != cur_e)
			p = p->next;

        if(p != L && p->next != L)
			*e = p->next->data;
		return OK;
    }
    return ERROR;

}

DLinkedList GetElemPtr(DLinkedList L, int i){
    DLinkedList p;
    int count;
    if(L){
		p = L->next;
		count = 1;

		while(p!=L && count < i){
			count++;
			p = p->next;
		}
		if(p!=L)
			return p;
    }
	return NULL;
}

Status ListInsert(DLinkedList L, int i, ElemType e){
	DLinkedList p, s;
	if(i<1 || i>ListLength(L)+1)
		return ERROR;
	p =GetElemPtr(L, i);
	if(!p)
		p = L;
    s = (DLinkedList)malloc(sizeof(DLinkedList));
    if(!s)
		exit(OVERFLOW);
	s->data = e;

	s->prior = p->prior;
	s->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

Status ListDelete(DLinkedList L, int i, ElemType *e){
	DLinkedList p;
	if(!(p = GetElemPtr(L, i)))
		return ERROR;

	*e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    return OK;
}

Status ListTraverse(DLinkedList L, void(Visit)(ElemType)){
	DLinkedList p;
	p = L->next;
	while(p!=L){
		Visit(p->data);
		p = p->next;
	}
	return OK;
}
