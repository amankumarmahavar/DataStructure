#include "./ExtendedLinkedList.h"



Status MakeNode(Link *p, ElemType e){
	*p = (Link)malloc(sizeof(LNode));
	while(!(*p))
		exit(OVERFLOW);

	//(**p).data = e;
	(*p)->data = e;
	(*p)->next = NULL;

	return OK;
}

void FreeNode(Link *p){
		free(*p);
		*p = NULL;
}

Status InitList(LinkList *L){
    Link p;
    p = (Link)malloc(sizeof(LNode));
    if(!p)
		exit(OVERFLOW);

	L->head = L->tail = p;
	L->length = 0;
	return OK;
}

void ClearList(LinkList *L){
	Link p, q;

	p = L->head->next;

	while(p){
		q = p->next;
		free(p);
		p = q;
	}

	L->head->next = NULL;
	L->tail = L->head;
	L->length = 0;

}

void DestrosyList(LinkList *L){
    ClearList(L);
    free(L->head);
    L->head = L->tail = NULL;
}


void InsFirst(LinkList *L, Link h, Link s){//h指向L中的头节点将s插入到“第一个结点”之前
	s->next = h->next;
	h->next =s;

	if(h == L->tail)
		L->tail = h->next;

	L->length++;
}

Status DelFirst(LinkList *L, Link h, Link *q){
	*q = h->next;

	if(*q){
        h->next = (*q)->next;
		if(!h->next)
			L->tail = h;

		L->length --;
		return OK;
	}
	return ERROR;
}

void Append(LinkList *L, Link s){
	int count = 0;

	L->tail->next = s;

	while(s){
        L->tail =s;
        s = s->next;
        count ++;
	}
	L->length += count;
}

Status Remove(LinkList *L, Link *q){
	Link p;
	while(!L->length){
        *q = NULL;
        return ERROR;
	}

	*q = L->tail;

	p = L->head;
	while(p->next!=L->tail)   //寻找尾节点的前驱
		p = p->next;
	L->tail = p;

	L->length --;
	return OK;
}

void InsBefore(LinkList *L, Link *p, Link s){
    Link q;

    q = PriorPos(*L, *p);
    if(!q)
		q = L->head;

	s->next = *p;
	q->next = s;
	*p = s; //

	L->length++;

}

void InsAfter(LinkList *L, Link *p, Link s){
	if(*p == L->tail)
		L->tail = s;

    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;

    L->length++;
}

ElemType GetCurElem(Link p){
	return p->data;
}

void SetCurElem(Link p, ElemType e){
	p->data = e;

}

Status ListEmpty(LinkList L){
		return L.length ? FALSE : TRUE;
}

int ListLength(LinkList L){
	return L.length;
}

Position GetHead(LinkList L){
	return L.head;
}

Position GetLast(LinkList L){
	return L.tail;
}

Position PriorPos(LinkList L, Link p){
	Link q;
	q = L.head->next;
	if(p == q)
		return NULL;
	else{
		while(q->next != p)
			q = q->next;
		return q;
	}
}

Position NextPos(Link p){
	return p->next;
}

Status LocatePos(LinkList L, int i, Link *p){
    int count = 0;
    *p = L.head;
    if(i<0 || i>L.length)
		return ERROR;

	while(count<i){
        count ++;
       *p = (*p)->next;
	}
	return OK;
}

Position LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)){
	Link p = L.head->next;

	while(p && !(Compare(e, p->data)))
		p = p->next;

	return p;
}

Status ListInsert(LinkList *L, int i, ElemType e){
	Link h, s;
	if(!LocatePos(*L ,i-1, &h))
		return ERROR;

	if(!MakeNode(&s, e))
		return ERROR;

	InsFirst(L, h, s);
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e){
	Link p ,q ;

	if(i<1 && i>L->length)
		return ERROR;

	LocatePos(*L, i-1, &p);
	DelFirst(L, p ,&q);

	*e = q->data;
	free(q);
	q = NULL;
	return OK;
}

Status ListTraverse(LinkList L, void(Visit)(ElemType)){
	Link p;
	int j;
	p = L.head->next;

	for(j = 1; j<= L.length; j++){
        Visit(p->data);
        p =p->next;
	}
	return OK;
}
