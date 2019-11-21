/** �ڽӱ�������ȱ����͹�����ȱ��� **/
#include<stdio.h>  
#include<stdlib.h>

#define MaxVex 255 
#define TRUE   1  
#define FALSE  0

typedef int VertexType;  //��������
typedef int Bool;
Bool visited[MaxVex];  //ȫ������,��¼ͼ�нڵ����״̬

typedef struct EdgeNode { //�߱�ڵ�  
	int adjvex;    //���ڽӵ��ڶ��������е��±�  
	struct EdgeNode *next;   //���� ָ����һ���ڽӵ�  
}EdgeNode;

typedef struct VertexNode { //ͷ�ڵ�
	VertexType data;  //������Ϣ
	EdgeNode *firstedge;  //�߱�ͷָ��(ָ���һ�������ڸö���Ļ���ָ��) 
}VertexNode, AdjList[MaxVex]; //��������(�ṹ������)   

typedef struct Graph {
	AdjList adjList;
	int numVertexes, numEdges;  //ͼ�е�ǰ�Ľ�����Լ�����  
}Graph, *GraphAdjList;


/** ���ж��弰��ز���(��ȱ������õ���ѭ������) **/
typedef struct LoopQueue {
	int data[MaxVex];
	int front, rear;
}LoopQueue, *Queue; //���нṹ

void initQueue(Queue &Q) {
	Q->front = Q->rear = 0;
}

Bool QueueEmpty(Queue &Q) {
	if (Q->front == Q->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Bool QueueFull(Queue &Q) {
	if ((Q->rear + 1) % MaxVex == Q->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/**
 * ��β����Ԫ��
 */
void EnQueue(Queue &Q, int e) {
	if (!QueueFull(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxVex;
	}
}

/**
 * ��ͷɾ��Ԫ��
 */
void DeQueue(Queue &Q, int *e) {
	if (!QueueEmpty(Q)) {
		*e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxVex;
	}
}
/*************************************************/


/**
 * ����ͼ���ڽӱ�ṹ(�˴�������ͼΪ��)
 */
void CreateALGraph(GraphAdjList &G) {
	int i, j, k;
	if (G == NULL) {
		G = (GraphAdjList)malloc(sizeof(Graph));
	}

	printf("Please input the number of node: ");
	scanf_s("%d", &G->numVertexes);
	printf("Please input the number of edge: ");
	scanf_s("%d", &G->numEdges);
	fflush(stdin);

	// printf("===========================\n");
	printf("Please input datas of each node:\n");
	for (i = 0; i < G->numVertexes; ++i) {
		printf("vertex%d: ", i + 1);
		scanf_s("%d", &(G->adjList[i].data));
		G->adjList[i].firstedge = NULL;
		fflush(stdin);
	}

	printf("\nPlease input endpoints of edge\n");
	for (k = 0; k < G->numEdges; ++k) {
		printf("Edge %d��", k + 1);
		scanf_s("%d%d", &i, &j);

		EdgeNode *ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
		ptrEdgeNode->adjvex = j;
		ptrEdgeNode->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = ptrEdgeNode;

		ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
		ptrEdgeNode->adjvex = i;
		ptrEdgeNode->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = ptrEdgeNode;
	}
}

void DFS(GraphAdjList &G, int i) {
	visited[i] = TRUE;
	printf("%d ", G->adjList[i].data);

	EdgeNode *p = G->adjList[i].firstedge;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(G, p->adjvex); //�ݹ���ȱ���
		}
		p = p->next;
	}
}


/**
 * ������ȱ���
 */
void DFSTraverse(GraphAdjList &G) {
	int i;
	for (i = 0; i < G->numVertexes; ++i) {
		visited[i] = FALSE;  //��ʼ����������visited��Ԫ��ֵΪfalse
	}
	for (i = 0; i < G->numVertexes; ++i) {
		if (!visited[i]) { //�ڵ���δ����
			DFS(G, i);
		}
	}
}


/**
 * ͼ�Ĺ�����ȱ���
 */
void BFSTraverse(GraphAdjList &G) {
	int i;
	Queue Q = (Queue)malloc(sizeof(LoopQueue));

	for (i = 0; i < G->numVertexes; ++i) {
		visited[i] = FALSE;
	}
	initQueue(Q);

	for (i = 0; i < G->numVertexes; ++i) {
		if (!visited[i]) {
			visited[i] = TRUE;
			printf("%d ", G->adjList[i].data);
			EnQueue(Q, i);

			while (!QueueEmpty(Q)) {
				DeQueue(Q, &i);
				EdgeNode *p = G->adjList[i].firstedge;
				while (p) {
					if (!visited[p->adjvex]) {
						visited[p->adjvex] = TRUE;
						printf("%d ", G->adjList[p->adjvex].data);
						EnQueue(Q, p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}

/**
 * �������
 */
int main() {
	GraphAdjList G = NULL;

	CreateALGraph(G);

	printf("\ndepth-first traversal: ");
	DFSTraverse(G);

	printf("\nbreadth-first traversal: ");
	BFSTraverse(G);

	printf("\n");
	system("pause");
	return 0;
}