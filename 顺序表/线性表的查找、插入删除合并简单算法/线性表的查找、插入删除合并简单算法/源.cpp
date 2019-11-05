#define MAX 100/*此处宏定义表示线性表的最大长度*/
typedef struct
{
	char data[MAX];/*线性表所占用的数组空间*/
	int last;/*记录线性表中最后一个元素在数组中的下标值，空表置为-1*/
}SeqList;
int Locate(SeqList L,char e)/*在线性表中查找与e相等的元素，若找到返回i+1，否则返回-1*/
{
	int i=0;/*i为计数器，初值为0，则从第一个元素开始比较*/
	while ((i <= L.last) && (L.data[i] != e))/*顺序扫描表，直到找到为e的元素，或扫描到表尾而没找到*/
		i++;
	if (i <= L.last)
		return (i + 1);/*若找到值为e的元素，返回在i+1*/
	else
		return (-1);/*若没有找到，返回空序号*/
	return 0;
}
int InsList(SeqList *L, int i, char e)/*在线性表中第i个元素之前插入e，i的合法取值1<=i<=L->Last+2*/
{
	int k;
	while ((i < 1) || (i > L->last + 2))/*判断插入的位置是否合法*/
		return -1;
	if (L->last >= MAX - 1)/*判断表是否已满*/
		return -1;
	for (k = L->last; k >= i - 1; k--)/*为插入元素而从从后往前移动位置*/
	{
		L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;/*插入元素e*/
	L->last++;

}
int DelList(SeqList *L, int i, char *e)/*在顺序表中低i个位置删除为e的元素*/
{
	int k;
	while ((i < 1) && (i > L->last + 1))/*判断删除位置是否合法*/
	{
		printf("删除位置不合法");
		return -1;
	}
	*e = L->data[i - 1];/*将删除的元素存放到e所指向的变量中*/
	for (k = i; i <= L->last; k++)/*删除完毕将后面的元素依次往前移动，为了保证顺序表的物理地址与逻辑地址一致*/
		L->data[i - 1] = L->data[i];
	L->last--;
	return 1;
}
void MergeList(SeqList *LA, SeqList *LB, SeqList *LC)/*已知顺序表A，B存放数字从小到大排列，将A，AB表合成C，使其也从小到排列*/
{
	int i, k, j;
	i = 0;
	k = 0;
	j = 0;
	while ((i <= LA->last) && (j <= LB->last))
	{
		if ((LA->data[i]) > LB->data[j]) {
			LC->data[k] = LB->data[j];
			j++;
			k++;
		}
		else
		{
			LC->data[k] = LA->data[i];
			k++;
			i++;
		}
	}
	while (i < LA->last)/*当A表有剩余时，将剩余的元素赋给C*/
	{
		LC->data[k] = LA->data[i];
		k++;
		i++;
	}
	while (j < LB->last)/*当B表有剩余时，将剩余的元素赋值给C*/
	{
		LC->data[k] = LB->data[j];
		k++;
		j++;
	}
	LC->last = LA->last + LB->last + 1;
}