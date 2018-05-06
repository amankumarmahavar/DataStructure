#include <stdio.h>
#include <stdlib.h>
#include "./SequenceList.h"

Status InitList(SqList* L){
    (*L).elem = (Element_Type *)malloc(LIST_INIT_SIZE * sizeof(Element_Type));
    if(! (*L).elem) exit(ERROR);
    (*L).length = 0;
    (*L).listsize = LIST_INCREMENT;
    return OK;
}


void DestoryList(SqList* L){
    free((*L).elem);

    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}

void CleamList(SqList* L){
    (*L).length = 0;
}

Status ListEmpty(SqList L){
    return L.length != 0 ? FALSE :TRUE;
}

int ListLength(SqList L){
    return L.length;
}

Status GetElem(SqList L, int i, Element_Type *e){
    if(i<1 || i>L.length)
        return ERROR;
    else
        *e = L.elem[i-1];

    return OK;
}

int LocateElem(SqList L, Element_Type e, Status(Compare)(Element_Type, Element_Type)){
    int i = 1;

    while(i <= L.length && !Compare(e, L.elem[i-1])) // 一定要注意i的界限
        ++i;

    if(i <=L.length)
        return i;
    else
        return ERROR;

}

Status PriorElem(SqList L, Element_Type cur_e, Element_Type* e){
    int i ;
    if(L.elem[0] == cur_e)
        return ERROR;
    else{
        for(i = 1; i<L.length; i++){
                if(L.elem[i] == cur_e)
                    *e = L.elem[i-1];
                    return OK;
        }
    }
    return ERROR;
}

Status NextElem(SqList L, Element_Type cur_e, Element_Type *e){
    int i = 0;
    while(i<L.length && L.elem[i] != cur_e)
        ++i;

    if(i<L.length-1){
        *e = L.elem[i+1];
        return OK;
    }
    return ERROR;
}

Status ListInsert(SqList* L, int i, Element_Type e){
    Element_Type *newbase;
    Element_Type *p, *q;

    if(i<1 || i>(*L).length+1)
        return ERROR;

    if((*L).length >= (*L).listsize){
        newbase = (Element_Type *)realloc((*L).elem,((*L).listsize+LIST_INCREMENT) *sizeof(Element_Type));
        //newbase = (ElemType_Sq *) realloc((*L).elem, ((*L)).listsize + LISTINCREMENT);
        if(!newbase)
            exit(ERROR);

        (*L).elem = newbase;
        (*L).listsize += LIST_INCREMENT;
    }

    q = &(*L).elem[i-1];

    for(p=&(*L).elem[(*L).length-1]; p>=q; p--)
        *(p+1) = *p;

    *q = e;
    ++(*L).length;

    return OK;
}

Status ListDelete(SqList* L, int i, Element_Type* e){
    Element_Type *q, *p;
    if(i<1 || i>(*L).length)
        return ERROR;

    q = &(*L).elem[i-1];
    *e = *q;
    p = (*L).elem + (*L).listsize -1;

    for(++q;q<=p; ++q)
        *(p-1) = *p;

    (*L).length--;
    return OK;

}

Status ListTravse(SqList L, void(Visit)(Element_Type)){
    int i;
   for(i =0; i<L.length; i++)
        Visit(L.elem[i]);

   return OK;
}

