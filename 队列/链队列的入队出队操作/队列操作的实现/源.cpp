#include<stdio.h>
#include<Windows.h>
typedef struct node {
	int data;
	struct node *next;
}LinkQueueNode;
typedef struct {
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;
void InitLinkQueue(LinkQueue *Q) {
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL) {
		Q->rear = Q->front;
		Q->front->next = NULL;
	}
}
void EnterQueue(LinkQueue *Q, int x) {
	LinkQueueNode *s;
	s = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (s != NULL) {
		s->data = x;
		s->next = NULL;
		Q->rear->next = s;
		Q->rear = s;
	}
}
int DeleteQueue(LinkQueue *Q, int *x) {
	LinkQueueNode *p;
	if (Q->front == Q->rear) {
		printf("此队列为空队列");
	}
	p = Q->front->next;
	Q->front->next= p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	return *x = p->data;
}

int main() {
	LinkQueue *Q,Q1;
	Q = &Q1;
	InitLinkQueue(Q);
	int a[5]={1,2,3,4,5};
	for (int i = 0; i < 5; i++) {
		EnterQueue(Q,a[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d", DeleteQueue(Q, &a[i]));;
	}
	system("pause");
	return 0;
}