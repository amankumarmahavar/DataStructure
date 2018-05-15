#ifndef CYLSEQQUEUE_H_INCLUDED
#define CYLSEQQUEUE_H_INCLUDED


#define OK 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
typedef int Status;


#define MAXSIZE 100
typedef int QElemType_CSq;

typedef struct{
	QElemType_CSq *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue_CSq(SqQueue *Q);

Status ClearQueue_CSq(SqQueue *Q);

Status DestroyQueue_CSq(SqQueue *Q);

Status QueueEmpty_CSq(SqQueue Q);

int QueueLength_CSq(SqQueue Q);

Status GetHead_CSq(SqQueue Q, QElemType_CSq *e);

Status EnQueue_CSq(SqQueue *Q, QElemType_CSq e);

Status DeQueue_CSq(SqQueue *Q, QElemType_CSq *e);

Status QueueTraverse_CSq(SqQueue Q, void(visit)(QElemType_CSq));
#endif // CYLSEQQUEUE_H_INCLUDED
