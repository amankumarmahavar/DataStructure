#include "./Union.h"

void Union(SqList* La, SqList Lb){
    int La_length = ListLength(*La);
    int Lb_length = ListLength(Lb);
    //printf("%d",La_length);
    //printf("%d",Lb_length);
    int i;
    Element_Type e;
    for(i = 1; i<=Lb_length ; i++){
       GetElem(Lb, i, &e);
        if( !LocateElem(*La, e, equal))
               // printf("%d ",e);
                ListInsert(La,++La_length, e);
    }
}

Status equal(Element_Type e1, Element_Type e2){
    return e1==e2? TRUE : FALSE;
}
