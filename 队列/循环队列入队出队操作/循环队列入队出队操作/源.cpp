#include<stdio.h>
#include<Windows.h>
#define MAX 5
typedef struct {
	int elem[MAX];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue *Q) {
	Q->front = Q->rear = 0;
}
void EnterQueue(SeqQueue *Q,int x) {
	if ((Q->rear + 1) % MAX == Q->front) {
		printf("此队列已满");
	}
	Q->elem[Q->rear] = x;
	//重新设置队尾指针
	Q->rear = (Q->rear + 1) % MAX;
}
int DeleteQueue(SeqQueue *Q, int *x) {
	if (Q->front == Q->rear) {
		printf("此队列为空队列");
	}
	*x = Q->elem[Q->front];
	//重新设置对头指针
	Q->front = (Q->front + 1) % MAX;
	return *x;
}
int main() {
	SeqQueue *Q,Q1;
	Q = &Q1;
	InitQueue(Q);
	int a[5] = { 1,2,3,4,5 };
	//注意：若要将5个元素全部入队出队，则会提示队列已满和空队列
	for (int i = 0; i < 4; i++) {
		EnterQueue(Q, a[i]);
	}
	for (int i = 0; i < 4; i++) {
		printf("%d", DeleteQueue(Q,&a[i]));
	}
	system("pause");
	return 0;
}