#include "./Union.c"

void printElem(Element_Type e);

int main()
{
    SqList La, Lb;
    int i;
	Element_Type a[5] = {5, 2, 1, 3, 9};
	Element_Type b[7] = {7, 2, 6, 9, 11, 3, 10};

    InitList(&La);
    for(i=1; i<=5; i++)
        ListInsert(&La, i, a[i-1]);
    InitList(&Lb);
    for(i=1; i<=7; i++)
        ListInsert(&Lb, i, b[i-1]);

    printf("La = ");
    ListTravse(La, printElem);
    printf("\n");
    printf("Lb = ");
    ListTravse(Lb, printElem);
    printf("\n");
    printf("La = La U Lb = ");
    Union(&La, Lb);
    ListTravse(La,printElem);

    return OK;
}


void printElem(Element_Type e){
    printf("%d ", e);
}
