#include <stdio.h>
#include "SequenceList.c"

Status CmpGreater(ElemType_Sq e, ElemType_Sq data);

void PrintElem(ElemType_Sq e);

void PrintEmptyLine();

int main()
{
    Sqlist L;
    int i;
    ElemType_Sq e;

    printf("\n1.    InitList_Sq Test\n");
    InitList_Sq(&L);
    PrintEmptyLine();
    PressEnter;


    printf("\n2.    ListEmpty_Sq Test\n");
    ListEmpty_Sq(&L) ? printf("L is NULL\n") : printf("L is not NULL\n");
    PrintEmptyLine();
    PressEnter;

    printf("\n3.    ListInsert_Sq Test\n");
    for(i=1;i<=6;i++){
        printf("Insert No %d as value %d\n",i , 2*i);
        ListInsert_Sq(&L, i , 2*i);
    }
    PrintEmptyLine();
    PressEnter;

    printf("\n4.    ListTraverse_Sq Test\n");
    printf("The Element in L by order is : L = ");
    ListTraverse_Sq(L, PrintElem);
    PrintEmptyLine();
    PressEnter;

    printf("\n5.    ListLength_Sq Test\n");
    i = ListLength_Sq(&L);
    printf("The Length of  L is %d\n",i);
    PressEnter;

    printf("\n.6    ListDelete_Sq\n");
    ListDelete_Sq(&L, 4, &e);
    printf("The deleted element is %d\n",e);
    printf("The current L by order is : L = ");
    ListTraverse_Sq(L, PrintElem);
    PrintEmptyLine();
    PressEnter;

    printf("\n7.     GetElem_Sq Test\n");
    GetElem_Sq(L, 2, &e);
    printf("The value of position 2 is %d",e);
    PrintEmptyLine();
    PressEnter;

    printf("\n8. LocateElem_Sq Test\n");
    i = LocateElem_Sq(L, 7, CmpGreater);
    printf("The element's position of first bigger than value 7 is at %d\n", i);
    PrintEmptyLine();
    PressEnter;

    printf("\n9. PriorElement Test\n");
    PriorElem_Sq(L, 6, &e);
    printf("The Prior element of element 6 is %d\n",e);
    PressEnter;

    printf("\n10. NextElement Test\n");
    NextElem_Sq(L, 6, &e);
    printf("The Next element of element 6 is %d\n",e);
    PressEnter;

    printf("\n11.   ListEmpty_Sq Test\n");
    printf("Before ClearList:");
    ListEmpty_Sq(&L) ? printf("L is NULL\n") : printf("L is not NULL\n");
    ClearList_Sq(&L);
    printf("After ClearList:");
    ListEmpty_Sq(&L) ? printf("L is NULL\n") : printf("L is not NULL\n");
    PressEnter;

    printf("\n12.   DestroyList Test\n");
    printf("Before destroy:");
    L.elem ? printf("L is existing\n") : printf("L is not existing\n");
    DestoryList_Sq(&L);
    printf("After destroy:");
    L.elem ? printf("L is existing\n") : printf("L is not existing\n");
    PressEnter;

    return OK;

}

Status CmpGreater(ElemType_Sq e, ElemType_Sq data){
    return data>e ? TRUE : FALSE;
}

void PrintElem(ElemType_Sq e)
{
    printf("%d ",e);
}

void PrintEmptyLine(){
    printf("\n");
}
