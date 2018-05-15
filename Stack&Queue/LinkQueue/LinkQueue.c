#include "LinkQueue.h"


Status InitQueue_L(LinkQueue *Q){
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
		exit(OVERFLOW);

	Q->front->next = NULL;
	return OK;
}


Status QueueEmpty_L(LinkQueue Q){
    return Q.front == Q.rear ? TRUE : FALSE;
}

Status ClearQueue_L(LinkQueue *Q){
	Q->rear = Q->front->next;
	while(Q->rear){
        Q->front->next = Q->rear->next;
        free(Q->rear);
        Q->rear = Q->front->next;
	}
	Q->rear = Q->front;
	return OK;
}

Status DestroyQueue_L(LinkQueue *Q){
    /*while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }*/
    ClearQueue_L(&Q);
    free(Q->front);
    free(Q->rear);
    return OK;
}

int QueueLength_L(LinkQueue Q){
	int count=0;
    QNode *p;
    p = Q.front;
    while(p->next !=NULL){
		count++;
		p = p->next;
    }
    return count;
}

Status GetHead_L(LinkQueue Q, QElemType_L *e){
    if(Q.front == Q.rear)
		return ERROR;

	*e = Q.front->next->data;
	return OK;
}

Status EnQueue_L(LinkQueue *Q, QElemType_L e){
	QueuePtr p;

	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;

    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue_L(LinkQueue *Q, QElemType_L *e){
	if(Q->front == Q->rear)
		return ERROR;

    QueuePtr p;
    p = Q->front->next;
    *e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p )
		Q->rear = Q->front;
	free(p);

	return OK;
}

Status QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L e)){
    QNode *p;
    p = Q.front->next;
    while(p != NULL){
		Visit(p->data);
		p=p->next;
    }
	return OK;
}
