
#include "SequenceList.h"


Status InitList_Sq(Sqlist *L){
	(*L).elem = (ElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(ElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW); 				//分配内存失败

	(*L).length = 0;					//初始化顺序表长度为0
	(*L).listsize = LIST_INIT_SIZE;		//顺序表初始内存分配量

	return OK;							//初始化成功
}


void ClearList_Sq(Sqlist *L){
    (*L).length = 0;
}

void DestoryList_Sq(Sqlist *L){
    free((*L).elem);

    (*L).elem = NULL;           //释放内存后置空指针
    (*L).length = 0;
    (*L).listsize = 0;
}

Status ListEmpty_Sq(Sqlist *L){
    return (*L).length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(Sqlist *L){
    return (*L).length;
}

Status GetElem_Sq(Sqlist L, int i, ElemType_Sq *e){
    if(i<1 || i>L.length)
        return ERROR;
    else
        *e = L.elem[i-1];

    return OK;
}

int LocateElem_Sq(Sqlist L, ElemType_Sq e, Status(Compare)(ElemType_Sq,ElemType_Sq)){
    int i = 1;

    while(i <=L.length && !Compare(e, L.elem[i-1]))
        ++i;

    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem_Sq(Sqlist L, ElemType_Sq cur_e, ElemType_Sq *pre_e){
    int i =1;

    if(L.elem[0] != cur_e){

        while(i<L.length && L.elem[i] != cur_e)
            ++i;

        if(i<L.length){
            *pre_e = L.elem[i-1];
            return OK;
        }

    }

    return ERROR;
}


Status NextElem_Sq(Sqlist L, ElemType_Sq cur_e, ElemType_Sq *next_e){
    int i = 0;

    while(i<L.length && L.elem[i] != cur_e)
        ++i;

    if(i<L.length-1){
        *next_e = L.elem[i+1];
        return OK;
    }
    return ERROR;
}


Status ListInsert_Sq(Sqlist *L, int i, ElemType_Sq e){
    ElemType_Sq *newbase;
    ElemType_Sq *p ,* q;

    if(i<1 || i>(*L).length+1)
        return ERROR;

    if((*L).length >= (*L).listsize){
        newbase = (ElemType_Sq *) realloc((*L).elem, ((*L)).listsize + LISTINCREMENT);
        if(!newbase)
            exit(OVERFLOW);

        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
        q = &(*L).elem[i-1];

        for(p=&(*L).elem[(*L).length -1]; p>=q; --p)
            *(p+1) = *p;

        *q = e;
        //printf("%d",*q);
        (*L).length++;

    return OK;
}

Status ListDelete_Sq(Sqlist* L, int i, ElemType_Sq *e)
{
    ElemType_Sq *p, *q;
    if(i<1 || i>(*L).length)
        return ERROR;

    p = &(*L).elem[i-1];                           //P is the position of deleted element
    *e = *p;
    q = (*L).elem + (*L).length-1;             // The position of tail


    for(++p; p<=q; ++p)
        *(p-1) = *p;

    (*L).length--;

    return OK;

}

Status ListTraverse_Sq(Sqlist L, void(Visit)(ElemType_Sq))
{
        int i;

        for(i=0;i<L.length;i++)
            Visit (L.elem[i]);

        return OK;

}
