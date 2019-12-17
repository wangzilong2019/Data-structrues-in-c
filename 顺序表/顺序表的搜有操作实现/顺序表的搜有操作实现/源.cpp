#include<stdio.h>
#include<Windows.h>
#define MAX 10
typedef struct {
	int data[MAX];
	int last;
}SeqList;
int Locate(SeqList *L, int e) {
	int i = 0;
	while ((i <= L->last) && (L->data[i] != e)) {
		i++;
	}
	if (i <= L->last) {
		return (i + 1);
	}
	else {
		return -1;
	}
}
void InsList(SeqList *L, int i, int e) {
	if (i<1 || i>L->last + 2) {
		printf("插入位置不合法");
	}
	if (L->last == MAX - 1) {
		printf("表已满无法插入");
	}
	for (int k = L->last; k >= i - 1; k--) {
		L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->last++;
	for (i = 0; i <= L->last; i++) {
		printf("%d ", L->data[i]);
	}
}
void DelList(SeqList *L, int i) {
	//int *e;
	if (i<1 || i>L->last + 1) {
		printf("删除位置不合法");
	}
	//*e = L->data[i - 1];
	for (int k = i; k <= L->last; k++) {
		L->data[i - 1] = L->data[i];
	}
	L->last--;
	for (i = 0; i <= L->last; i++) {
		printf("%d ", L->data[i]);
	}
}
void MergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
	int i = 0;
	int j = 0;
	int k = 0;
	while ((i <= LA->last) && (j <= LB->last)) {
		if (LA->data[i] < LB->data[j]) {
			LC->data[k] = LA->data[i];
			i++;
			k++;
		}
		else {
			LC->data[k] = LB->data[j];
			k++;
			j++;
		}
	}
	while (i < LA->last) {
		LC->data[k] = LA->data[i];
		i++;
		k++;
	}
	while (j < LB->last) {
		LC->data[k] = LB->data[j];
		j++;
		k++;
	}
	for (i = 0; i < k; i++) {
		printf("%d->", LC->data[i]);
	}
}
int main() {
	SeqList *LA, *LB, *LC, L1, L2, L3;
	int i, j;
	LA = &L1;
	LB = &L2;
	LC = &L3;
	LA->last = 4;
	LB->last = 2;
	for (i = 0; i < 5; i++) {
		scanf_s("%d", &LA->data[i]);
	}

	for (j = 0; j < 3; j++) {
		scanf_s("%d", &LB->data[j]);
	}
	//printf("%d", Locate(LA, 3));
	//InsList(LA, 2, 9);
	//DelList(LA, 2);
	MergeList(LA, LB, LC);
	system("pause");
	return 0;
}