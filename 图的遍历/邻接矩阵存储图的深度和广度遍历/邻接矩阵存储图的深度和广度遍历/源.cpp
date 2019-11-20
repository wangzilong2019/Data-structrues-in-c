#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_VERTAX_SIZE 20

typedef char VerElemType;
typedef char ElemType;
typedef int Status;

typedef struct Graph {
	VerElemType VertaxMatrix[MAX_VERTAX_SIZE];
	int AdjacentMatrix[MAX_VERTAX_SIZE][MAX_VERTAX_SIZE];
	int VertaxNum;
	int EageNum;
}Graph;

//队列，在图的广度优先遍历中使用
typedef struct QueueNode {
	ElemType data;
	struct QueueNode* next;
}QueueNode, *QueueNodePtr;
typedef struct Queue {
	QueueNodePtr front;
	QueueNodePtr rear;
}Queue;

Status InitQueue(Queue* q) {
	(*q).front = (QueueNodePtr)malloc(sizeof(struct QueueNode));
	(*q).rear = (*q).front;
	(*q).rear->next = NULL;
	return OK;
}
Status EnterQueue(Queue* q, ElemType e) {
	QueueNodePtr n;
	n = (QueueNode*)malloc(sizeof(struct QueueNode));
	n->data = e;
	n->next = q->rear->next;
	q->rear->next = n;
	q->rear = n;
	return OK;
}
Status DeleteQueue(Queue* q, ElemType* e) {
	QueueNodePtr p;
	if (q->front == q->rear) {
		printf("Empty\n");
		return ERROR;
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	free(p);
	if (p == q->rear)
		q->rear = q->front;
	return OK;
}
Status IsQueueEmpty(Queue q) {
	return q.front == q.rear ? OK : ERROR;
}

//定位某个顶点的下标
int LocateVertax(Graph G, VerElemType ver) {
	int i;
	for (i = 0; i < G.VertaxNum; i++) {
		if (G.VertaxMatrix[i] == ver)
			return i;
	}
	return -1;
}
//创建无向图
Status CreateUDG(Graph* G) {
	int i, j, k;
	VerElemType x, y;
	printf(" Create Undigraph.\n");
	printf("Please enter the number of Vertax and Eage: \n");
	scanf_s("%d %d%*c", &(*G).VertaxNum, &(G->EageNum));	//%*c吃掉回车

	printf("ok, please input value of %d Vertax.\n", G->VertaxNum);
	for (i = 0; i < G->VertaxNum; i++) {		//初始化顶点数组
		scanf_s("%c%*c", &(G->VertaxMatrix[i]));
	}

	for (i = 0; i < G->VertaxNum; i++)		//初始化邻接表
		for (j = 0; j < G->VertaxNum; j++)
			G->AdjacentMatrix[i][j] = 0;
	//for( i = 0; i < G->VertaxNum; i++ ){	//初始化邻接表
	//	for( j = 0; j < G->VertaxNum; j++ )
	//		printf("%d ", G->AdjacentMatrix[i][j]);
	//	printf("\n");	
	//}

	for (k = 0; k < G->EageNum; k++) {
		printf("ok, please input two Vertax of Eage: %d,separated by Spaces.\n", k + 1);
		scanf_s("%c %c%*c", &x, &y);
		i = LocateVertax(*G, x);
		j = LocateVertax(*G, y);
		G->AdjacentMatrix[i][j] = G->AdjacentMatrix[j][i] = 1;
	}
	return OK;
}
//打印邻接矩阵
Status PrintAdjacentMatrix(Graph G) {
	int i, j;
	printf("    Adjacent Matrix\n");
	for (i = 0; i < G.VertaxNum; i++) {
		for (j = 0; j < G.VertaxNum; j++) {
			printf("%3d", G.AdjacentMatrix[i][j]);
		}
		printf("\n");
	}
	return OK;
}

//图的深度优先遍历
//返回v的第一个邻接顶点，若没有邻接顶点，返回-1
int FirstAdjacentVertax(Graph G, VerElemType v) {
	int index_v = LocateVertax(G, v);
	int i;
	for (i = 0; i < G.VertaxNum; i++) {
		if (G.AdjacentMatrix[index_v][i] == 1)
			return i;
	}
	return -1;
}
//w是v的邻接点，返回v的除了w(从w开始)的下一个邻接顶点，没有则返回-1
int NextAdjacentVertax(Graph G, VerElemType v, VerElemType w) {
	int index_v = LocateVertax(G, v);
	int index_w = LocateVertax(G, w);
	int i;
	for (i = index_w + 1; i < G.VertaxNum; i++) {
		if (G.AdjacentMatrix[index_v][i] == 1)
			return i;
	}
	return -1;
}
//DFS的递归思想： 	访问v，
//			从v的第一邻接点开始深度优先遍历，
//			然后从v的第二邻接开始深度优先遍历。直到没有邻接点

int visitedArray[MAX_VERTAX_SIZE];
void visit(VerElemType c) {
	printf("%c ", c);
}
VerElemType GetVertaxValue(Graph G, int position) {
	return G.VertaxMatrix[position];
}
Status DFS(Graph G, VerElemType v) {		//Depth First Search
	VerElemType w;
	visit(v);
	visitedArray[LocateVertax(G, v)] = 1;

	for (w = GetVertaxValue(G, FirstAdjacentVertax(G, v)); LocateVertax(G, w) != -1; w = GetVertaxValue(G, NextAdjacentVertax(G, v, w))) {
		if (visitedArray[LocateVertax(G, w)] != 1)
			DFS(G, w);
	}
	return OK;
}
Status DFSTraverse(Graph G) {
	int i;
	for (i = 0; i < G.VertaxNum; i++) {
		visitedArray[i] = 0;
	}
	for (i = 0; i < G.VertaxNum; i++) {
		if (visitedArray[i] == 0) {
			DFS(G, GetVertaxValue(G, i));
		}
	}
	return OK;
}
//BFS(广度优先遍历)：利用队列和树的层次遍历相似
//思想：将第一个顶点入队，将对中的元素出队，如果没有访问过，则调用visit访问，将其所有的邻接顶点入队
Status BFSTraverse(Graph G) {
	ElemType c;
	Queue q;
	InitQueue(&q);
	int i, j;
	for (i = 0; i < G.VertaxNum; i++)
		visitedArray[i] = 0;

	for (i = 0; i < G.VertaxNum; i++) {
		if (visitedArray[i] == 0) {
			EnterQueue(&q, G.VertaxMatrix[i]);
			visitedArray[i] = 1;
			while (IsQueueEmpty(q) != OK) {
				DeleteQueue(&q, &c);			//进到队里的都是编辑为访问过，这样队里不会有重复的点进来
				visit(c);
				for (j = FirstAdjacentVertax(G, c); j != -1; j = NextAdjacentVertax(G, c, GetVertaxValue(G, j))) {
					if (visitedArray[j] == 0) {
						EnterQueue(&q, GetVertaxValue(G, j));
						visitedArray[j] = 1;	//进到队里的都是编辑为访问过，这样队里不会有重复的点进来
					}
				}
			}
		}
	}

}

int main() {
	Graph G;
	CreateUDG(&G);
	PrintAdjacentMatrix(G);
	printf("the Result of DFS(Depth First Search) is: ");
	DFSTraverse(G);
	printf("\nthe REsult of BFS(Breadth First Srarch) is: ");
	BFSTraverse(G);
	system("pause");
	return 0;
}