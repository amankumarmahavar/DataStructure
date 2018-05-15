#include "./CylSeqQueue.h"

Status InitQueue_CSq(SqQueue *Q){
    Q->base = (QElemType_CSq *)malloc(sizeof(QElemType_CSq));
    while(!Q->base)
		exit(OVERFLOW);

	Q->front = Q->rear = 0;
	return OK;
}

Status ClearQueue_CSq(SqQueue *Q){
    Q->front = Q->rear = 0;
    return OK;
}

Status DestroyQueue_CSq(SqQueue *Q){
	if(Q->base)
		free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0;
    return OK;
}

Status QueueEmpty_CSq(SqQueue Q){
    return Q.rear == Q.front ? TRUE : FALSE;
}

int QueueLength_CSq(SqQueue Q){
	return ( Q.rear - Q.front  + MAXSIZE ) %MAXSIZE;
}

Status GetHead_CSq(SqQueue Q, QElemType_CSq *e){
	if(Q.front == Q.rear)
		return ERROR;
	*e = Q.base[Q.front];
	return OK;
}

Status EnQueue_CSq(SqQueue *Q, QElemType_CSq e){
	if((Q->rear+1)%MAXSIZE == Q->front) return OVERFLOW;

	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) %MAXSIZE;

	return OK;
}

Status DeQueue_CSq(SqQueue *Q, QElemType_CSq *e){
	if(Q->rear == Q->front)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front +1) %MAXSIZE;
	return OK;
}

Status QueueTraverse_CSq(SqQueue Q, void(visit)(QElemType_CSq)){
	int i;
	int length = QueueLength_CSq(Q);
	for(i=0; i<length;i++ )
		visit(Q.base[i]);
    return OK;
}
