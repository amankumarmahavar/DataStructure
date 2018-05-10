#ifndef SEQUENCESTACK_H_INCLUDED
#define SEQUENCESTACK_H_INCLUDED
#include "./Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack_Sq(SqStack *S){
        S ->base = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));
        if(!S->base)
			exit(OVERFLOW);
		S->top = S->base;
		S->stacksize = STACK_INIT_SIZE;

		return OK;
}

Status StackEmpty_Sq(SqStack S){
	return S.top == S.base ? TRUE :FALSE;
}

Status ClearStack_Sq(SqStack *S){
    S->top = S->base;
	return OK;
}

Status DestroyStack_Sq(SqStack *S){
    ClearStack_Sq(S);
    free(S->base);
    S->base = NULL;
    return OK;
}

int StackLength_Sq(SqStack S){
	return S.top - S.base;
}

Status Push_Sq(SqStack *S, ElemType e){
	if(S->top - S->base >= S->stacksize){
        S->base = (ElemType *) realloc(S->base,(S->stacksize +STACKINCREMENT)*sizeof(ElemType));
        if(!S->base)
			exit(OVERFLOW);

		S->top =S->base+S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top = e;
	S->top ++;
	return OK;
}

Status Pop_Sq(SqStack *S, ElemType *e){
	while(S->base == S->top)
		exit(ERROR);
    --S->top ;
    *e = *(S->top);
    return OK;
}

Status GetTop_Sq(SqStack S, ElemType *e){
	if(S.base == S.top)
		return ERROR;
    *e = *(S.top - 1);
    return OK;
}



Status StackTraverse_Sq(SqStack S, void(Visit)(ElemType)){
	ElemType *e = S.base;
	while(e<S.top){
        Visit(*e);
        *e++;
	}
	return OK;
}



#endif // SEQUENCESTACK_H_INCLUDED
