#include "./MergeList.h"


void MergeList(LinkList *La, LinkList *Lb, LinkList *Lc){
	LinkList pa=*La, pb=*Lb, pc =*La;

	pa = pa->next;
	pb = pb->next;
	*Lc = pc;  //pc is only a head pointer pointing to La.

	while(pa && pb){
        if(pa->data <= pb->data){

			pc->next = pa;
			pc = pa;
			pa = pa->next;

        }
        else{
			pc ->next =pb;
			pc = pb;
			pb = pb->next;
        }

	}
	pc->next = pa ? pa : pb;

	free(*Lb);
	*Lb = NULL;
}
