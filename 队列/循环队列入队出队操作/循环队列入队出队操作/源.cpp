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
		printf("�˶�������");
	}
	Q->elem[Q->rear] = x;
	//�������ö�βָ��
	Q->rear = (Q->rear + 1) % MAX;
}
int DeleteQueue(SeqQueue *Q, int *x) {
	if (Q->front == Q->rear) {
		printf("�˶���Ϊ�ն���");
	}
	*x = Q->elem[Q->front];
	//�������ö�ͷָ��
	Q->front = (Q->front + 1) % MAX;
	return *x;
}
int main() {
	SeqQueue *Q,Q1;
	Q = &Q1;
	InitQueue(Q);
	int a[5] = { 1,2,3,4,5 };
	//ע�⣺��Ҫ��5��Ԫ��ȫ����ӳ��ӣ������ʾ���������Ϳն���
	for (int i = 0; i < 4; i++) {
		EnterQueue(Q, a[i]);
	}
	for (int i = 0; i < 4; i++) {
		printf("%d", DeleteQueue(Q,&a[i]));
	}
	system("pause");
	return 0;
}