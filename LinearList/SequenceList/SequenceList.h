#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

/* 宏定义 */
#define LIST_INIT_SIZE 100				//顺序表存储空间的初始分配量
#define LISTINCREMENT  10				//顺序表存储空间的分配增量

/* 顺序表类型定义 */
#ifndef ELEMTYPE_SQ
#define ELEMTYPE_SQ
typedef int ElemType_Sq;
#endif

typedef struct{
    ElemType_Sq *elem;          //存储空间基址
    int length;                          //当前顺序表长度
    int listsize;                           //当前分配的存储容量
}Sqlist ;

Status InitList_Sq(Sqlist *L);

void ClearList_Sq(Sqlist *L);

void DestoryList_Sq(Sqlist *L);

Status ListEmpty_Sq(Sqlist *L);

int ListLength_Sq(Sqlist *L);

Status GetElem_Sq(Sqlist L, int i, ElemType_Sq *e);

int LocateElem_Sq(Sqlist L, ElemType_Sq e, Status(Compare)(ElemType_Sq, ElemType_Sq));

Status PriorElem_Sq(Sqlist L, ElemType_Sq cur_e, ElemType_Sq *pre_e);

Status NextElem_Sq(Sqlist L, ElemType_Sq cur_e, ElemType_Sq *next_e);

Status ListInsert_Sq(Sqlist *L, int i , ElemType_Sq e);

Status ListDelete_Sq(Sqlist *L, int i, ElemType_Sq *e);

Status ListTraverse_Sq(Sqlist L, void (Visit)(ElemType_Sq));


#endif // SEQUENCELIST_H_INCLUDED
