#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

#include "./Status.h"

typedef int QElemType_L;

typedef struct QNode{
	QElemType_L data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue_L(LinkQueue *Q);

Status QueueEmpty_L(LinkQueue Q);

Status ClearQueue_L(LinkQueue *Q);

Status DestroyQueue_L(LinkQueue *Q);

int QueueLength_L(LinkQueue Q);

Status GetHead_L(LinkQueue Q, QElemType_L *e);

Status EnQueue_L(LinkQueue *Q, QElemType_L e);

Status DeQueue_L(LinkQueue *Q, QElemType_L *e);

Status QueueTraverse_L(LinkQueue Q, void(Visit(QElemType_L e)));




#endif // LINKQUEUE_H_INCLUDED
