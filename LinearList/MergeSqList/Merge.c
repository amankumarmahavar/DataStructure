#include "./SequenceList.c"

void MergeList1(SqList La, SqList Lb, SqList *Lc){
	InitList(Lc);
	int i,j,k;
	i = j = 1, k=0;
	ElementType ai,bj;
	int La_length = ListLength(La);
	int Lb_length = ListLength(Lb);
	while((i<=La_length) &&(i<=Lb_length)){
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);
		if(ai<=bj){
			InsertElem(Lc, ++k, ai);
			++i;
		}
		else{
			InsertElem(Lc,++k, bj);
			++j;
		}
	}

	while(i <= La_length){
		GetElem(La, i++ ,&ai);
		InsertElem(Lc, ++k, ai);
	}
	while(j<=Lb_length){
		GetElem(Lb, j++, &bj);
		InsertElem(Lc, ++k, bj);
	}
}

void MergeList2(SqList La, SqList Lb, SqList *Lc){
	ElementType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize=Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElementType *)malloc(Lc->listsize * sizeof(ElementType));
	if(!pc)
		exit(OVERFLOW);

	pa_last = La.elem + La.length -1;
	pb_last = Lb.elem + Lb.length -1;

	while(pa<=pa_last && pb<=pb_last){
		if(pa<=pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}

	while(pa<=pa_last)
		*pc++ = *pa++;

	while(pb<=pb_last)
		*pc++ = *pb++;
}
