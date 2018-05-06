#include "./SinglyLinkedList.h"


Status InitList(LinkList* L){
	(*L)= (LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(OVERFLOW);
	//(*L)->next = NULL;
	(**L).next=NULL;
	return OK;
}



Status ClearList(LinkList L){
	LinkList pre, p;

	if(!L)
		return ERROR;

	pre = L->next;
	while(pre){
		p = pre->next;
		free(pre);
		pre = p;
	}

	L->next = NULL;

	return OK;
}

Status DestoryList(LinkList *L){
	LinkList p = *L;

	while(p){
		p = (*L)->next;
		free(L);
		(*L) = p;
	}
	return OK;
}

Status ListEmpty(LinkList L){
	return (L!=NULL && L->next==NULL) ? TRUE :FALSE;
}

int ListLength(LinkList L){
	LinkList p;
	int i;
	if(L){
			i = 0;
			p=L->next;
			while(p){
				i++;
				p=p->next;
			}

	}
	return i;
}

Status GetElem(LinkList L, int i,ElemType* e){
	int j = 1;
	LinkList p =L->next;

	while(p && j<i){
		j++;
		p=p->next;
	}

	if(!p || j>i)
		return ERROR;

	*e = p->data;

	return OK;

}

Status NextElem(LinkList L, ElemType cur_e, ElemType* e){
	//LinkList p = L->next;
	//while(p->next != NULL && p->next ->data!= cur_e){
	//	p=p->next;
	//}
	//if(p->next==NULL)
    //    return ERROR;

	//*e = p->next->data;
	//return OK;

	LinkList p,suc;
	if(L){
		p = L->next;

		while(p && p->next){
			suc = p->next;

			if(suc && p->data == cur_e){
				*e = suc->data;
				return OK;
			}

			if(suc)
				p = suc;
			else
				break;
		}
	}
	return ERROR;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType* e){
	LinkList p,suc;

	if(L){
		p = L->next;

		if(p->data != cur_e){
			while(p->next){
				suc = p->next;
				if(suc->data == cur_e){
						*e = p->data;
						return OK;
				}
				p=suc;
			}
		}
	}
	return ERROR;
}

int LocateElem(LinkList L, ElemType e, Status(Compara)(ElemType,ElemType)){
	int i;
	LinkList p;
	i=-1;

	if(L){
		i=0;
		p=L->next;

		while(p){
			i++;
			if(!Compara(e, p->data)){
				p = p->next;
				if(p==NULL){
						i++;
				}
			}
			else
				break;
		}
	}
	return i;
}

Status ListInsert(LinkList L, int i,ElemType e){
	LinkList p,s;
	int j;

	p = L;
	j  = 0;

	while(p && j<i-1){
		p=p->next;
		++j;
	}

	if(!p || j>i-1)
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		return ERROR;
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status ListDelete(LinkList L, int i, ElemType* e){
    LinkList p, s;
    int j =0;
    p=L;

    while(p && j<i-1){
		p = p->next;
		j++;
    }
	s = p->next;

    if(!p->next || j>i-1)
		exit(ERROR);

	*e = s->data;
	p->next = s->next;
	free(s);
	return OK;
}

Status ListTarverse(LinkList L, void(Visit)(ElemType)){
    LinkList p;
    if(!L)
		return ERROR;
	else
		p = L->next;

	while(p){
		Visit(p->data);
		p = p->next;
	}
	return OK;
}

Status CreateList_h(LinkList *L, int n){
	int i;
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for(i=0; i<n; i++){
        p = (LinkList)malloc(sizeof(LNode));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next  = p;
	}
	return OK;
}

Status CreateList_t(LinkList*L, int n){
	int i;
	LinkList p,q;
	srand(time(0));
	q = *L = (LinkList)malloc(sizeof(LNode));
	for(i=0; i<n;i++){
		p = (LinkList)malloc(sizeof(LNode));
		p->data = rand()%100 +1;
		q->next = p;
        q=q->next;
	}
	q->next =NULL;
	return OK;
}

Status GetMiddleNode(LinkList L,ElemType *e){
	LinkList Search, Mid;
	Mid = Search = L;
	while(Search->next != NULL){
		if(Search->next->next != NULL){
			Search = Search->next->next;
			Mid = Mid->next;
		}
		else{
			Search = Search ->next;
			Mid = Mid->next;
		}
	}
		*e = Mid->data;
		return OK;
}

