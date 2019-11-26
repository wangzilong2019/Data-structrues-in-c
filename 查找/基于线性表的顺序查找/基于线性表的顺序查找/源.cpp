#include<stdio.h>
#define MAX 20
typedef struct {
	int key;
	char ch;
}Recodtype;
typedef struct {
	Recodtype r[MAX];
	int length;
}Recodlist;
void Creat(Recodlist L,int n) {
	int i;
	for (i = 0; i < n; i++) {
		L.length++;
		printf("请输入序号");
		scanf_s("%d",&(L.r[i].key));
		printf("请输入字母");
		scanf_s("%c",&(L.r[i].ch));

	}
}
int SeqSearch(Recodlist L, int k) {
	int i;
	L.r[0].key = k;
	i = L.length;
	while (L.r[i].key!= k) {
		i--;
	}
	return i;
	
}
int main(){
	Recodlist L;
	L.length = 0;
	int n,k;
	printf("请输入学生人数");
	scanf_s("%d",&n);
	Creat(L,n);
	printf("请输入所要查找的序号");
	scanf_s("%d",&k);
	printf("%d", SeqSearch(L, k));
	return 0;
}