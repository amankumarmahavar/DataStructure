#include "./StaticLinkedList.h"


void InitSpace(){
	int i;

	for(i=0; i<MAXSIZE-1; i++){
		SPACE[i].cur = i +1;
	}

	SPACE[MAXSIZE - 1].cur = 0;

}

int Malloc(){
    int i;

    i = SPACE[0].cur;

    if(SPACE[0].cur)
	{
		SPACE[0].cur = SPACE[i].cur;
		return i;
	}
	else
		return 0;
}

void Free(int k){
	SPACE[k].cur = SPACE[0].cur;
	SPACE[0].cur = k;
}


Status InitList(SLinkList *H){
	(*H) = Malloc();
	if(!(*H))
		exit(OVERFLOW);

	SPACE[*H].cur = 0;

	return OK;

}

Status ClearList(SLinkList H){

	int p,q;

	if(!H)
		return ERROR;

	p = SPACE[H].cur;

	while(p){
        SPACE[H].cur = SPACE[p].cur;
        Free(p);
        p = SPACE[H].cur;
	}

	return OK;
}

void DestroyList(SLinkList *H){
	ClearList(*H);

	Free(*H);
	*H = 0;
}

Status ListEmpty(SLinkList H){
	return (H && !SPACE[H].cur)? TRUE : FALSE;
}

int ListLength(SLinkList H){
	int count, p;

	if(!H)
		exit(OVERFLOW);

	count = 0;
	p = SPACE[H].cur;

	while(p){
		count++;
		p=SPACE[p].cur;
	}
	return count;
}

Status GetElem(SLinkList H, int i, ElemType *e){
	int count, p;

	if(!H || i<1 || i>MAXSIZE-2)
		exit(OVERFLOW);

	count = 0;
	p = SPACE[H].cur;

	while( p && count < i-1){
		count++;
		p = SPACE[p].cur;
	}

	if(p){
		*e = SPACE[p].data;
		return OK;
	}
	else
		return ERROR;

/*	while(p)
	{
		count++;

		if(count==i)
		{
			*e = SPACE[p].data;
			return OK;
		}

		p = SPACE[p].cur;
	}
*/
}

int LocateElem(SLinkList H, ElemType e){
    int k, count;

    count = 1;
    if(H && SPACE[H].cur){
		k = SPACE[H].cur;

		while(k && SPACE[k].data != e){
			count++;
			k = SPACE[k].cur;
		}

		if(k)
			return count;

    }

    return -1;
}

Status PriorElem(SLinkList H, ElemType cur_e, ElemType *e){
    int p, q;
    if(H){
        p = SPACE[H].cur;

        if(p && SPACE[p].data != cur_e){
				q = SPACE[p].cur;

				while(q && SPACE[q].data != cur_e){
					p = q;
					q = SPACE[q].cur;
				}

				if(q){
					*e = SPACE[p].data;
					return OK;
				}

        }

    }
	return ERROR;
}

Status NextElem(SLinkList H, ElemType cur_e, ElemType *e){
	int p;
	if(H){
		p = SPACE[H].cur;

        while(p && SPACE[p].data!=cur_e)
			p = SPACE[p].cur;

		if(p && SPACE[p].cur){
			p = SPACE[p].cur;
			*e = SPACE[p].data;
			return OK;
		}

	}
	return ERROR;
}

Status ListInsert(SLinkList H, int i, ElemType e){
    int count, k, p;

    if(!H)
		return ERROR;

	if(i>0){
		count = 0;
		k = H;

		while(k && count<i-1){
            count++;
            k = SPACE[k].cur;
		}

		if(k){
			 p = Malloc();
			 if(!p)
				return OVERFLOW;

			 SPACE[p].data = e;
			 SPACE[p].cur = SPACE[k].cur;   // 把K的下一元素赋值给P的下一元素
			 SPACE[k].cur = p;

			 return OK;
		}
	}
	return ERROR;
}

Status ListDelete(SLinkList H, int i ,ElemType *e){
	int count, k, p;

	if(!H)
		return ERROR;

	if(i>0){
		count = 0;
		k = H;

		while(k && count<i-1){
            count++;
            k = SPACE[k].cur;
		}

		if(k && SPACE[k].cur){
            p = SPACE[k].cur;
            *e = SPACE[p].data;
            SPACE[k].cur = SPACE[p].cur;
            Free(p);

            return OK;
		}
	}
	return ERROR;
}

Status ListTraverse(SLinkList H, void(Visit)(ElemType e)){
	int p;

	if(!H)
		return ERROR;

	p = SPACE[H].cur;

	while(p){
        Visit(SPACE[p].data);
        p = SPACE[p].cur;
	}
	return OK;
}


Status GetMidNode(SLinkList H, ElemType *e){
    int f, s, count=1;
    f = s = H;
    s = f  = SPACE[f].cur;
    while(f){
			if((f=SPACE[f].cur,count++) && (f=SPACE[f].cur,count++)){
				s = SPACE[s].cur;
				//count += 2;
			}
			else if(count % 2 != 0){
				//printf("这时候count 的%d",count);
				break;}
			else{
				s = SPACE[s].cur;
				break;
			}
    }
    *e = SPACE[s].data;
	return OK;
}

void difference(SLinkList *S, ElemType A[], int len_a, ElemType B[], int len_b){
	int i, j;
	int r, p, k;
	ElemType b;

	InitSpace();
	*S = Malloc();
	r = *S;
	SPACE[r].cur = 0;

	for(j = 0; j<=len_a; j++){
        i = Malloc();
        SPACE[i].data = A[j];
        SPACE[r].cur = i;
        r = i;
	}
	SPACE[r].cur = 0;

	for(j = 0; j<len_b; j++){
		b = B[j];
		p = *S;
		k = SPACE[*S].cur;
		while(k && SPACE[k].data!=b){
            p = k;
            k = SPACE[k].cur;
		}

		if(!k){
			i = Malloc();
			SPACE[i].data = b;
			SPACE[i].cur = SPACE[r].cur;
			SPACE[r].cur = i;
		}
		else{
            SPACE[p].cur = SPACE[k].cur;
            Free(k);
            if(k == r)
				r = p;
		}
	}

}
