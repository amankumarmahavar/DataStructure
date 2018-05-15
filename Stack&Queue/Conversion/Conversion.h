#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#include "./Status.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);

Status Push(SqStack *S, ElemType e);

Status Pop(SqStack *S, ElemType *e);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

void Bin2Hex();

void Bin2Oct();

void Bin2Dec();



#endif // CONVERSION_H_INCLUDED
