#include "./Merge.c"

void PrintElem(ElementType e);

int main()
{
	SqList La, Lb, Lc1, Lc2;
	ElementType a[4] = {3, 5, 8, 11};
	ElementType b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;
	InitList(&La);
	for(i=1; i<=4; i++)
		InsertElem(&La, i, a[i-1]);
	InitList(&Lb);
	for(i=1; i<=7; i++)
		InsertElem(&Lb, i, b[i-1]);

	printf("La = ");
	ListTraver(La, PrintElem);
	printf("\n");
	printf("Lb = ");
	ListTraver(Lb, PrintElem);
	printf("\n\n");

	MergeList1(La, Lb, &Lc1);
	printf("La Merge Lb= ");
	ListTraver(Lc1, PrintElem);
	printf("\n\n");

	MergeList2(La, Lb, &Lc2);
	printf("La Merge Lb= ");
	ListTraver(Lc1, PrintElem);
	printf("\n\n");


	return 0;
}


void PrintElem(ElementType e)
{
	printf("%d ", e);
}
