#define MAX 100/*�˴��궨���ʾ���Ա����󳤶�*/
typedef struct
{
	char data[MAX];/*���Ա���ռ�õ�����ռ�*/
	int last;/*��¼���Ա������һ��Ԫ���������е��±�ֵ���ձ���Ϊ-1*/
}SeqList;
int Locate(SeqList L,char e)/*�����Ա��в�����e��ȵ�Ԫ�أ����ҵ�����i+1�����򷵻�-1*/
{
	int i=0;/*iΪ����������ֵΪ0����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i <= L.last) && (L.data[i] != e))/*˳��ɨ���ֱ���ҵ�Ϊe��Ԫ�أ���ɨ�赽��β��û�ҵ�*/
		i++;
	if (i <= L.last)
		return (i + 1);/*���ҵ�ֵΪe��Ԫ�أ�������i+1*/
	else
		return (-1);/*��û���ҵ������ؿ����*/
	return 0;
}
int InsList(SeqList *L, int i, char e)/*�����Ա��е�i��Ԫ��֮ǰ����e��i�ĺϷ�ȡֵ1<=i<=L->Last+2*/
{
	int k;
	while ((i < 1) || (i > L->last + 2))/*�жϲ����λ���Ƿ�Ϸ�*/
		return -1;
	if (L->last >= MAX - 1)/*�жϱ��Ƿ�����*/
		return -1;
	for (k = L->last; k >= i - 1; k--)/*Ϊ����Ԫ�ض��ӴӺ���ǰ�ƶ�λ��*/
	{
		L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;/*����Ԫ��e*/
	L->last++;

}
int DelList(SeqList *L, int i, char *e)/*��˳����е�i��λ��ɾ��Ϊe��Ԫ��*/
{
	int k;
	while ((i < 1) && (i > L->last + 1))/*�ж�ɾ��λ���Ƿ�Ϸ�*/
	{
		printf("ɾ��λ�ò��Ϸ�");
		return -1;
	}
	*e = L->data[i - 1];/*��ɾ����Ԫ�ش�ŵ�e��ָ��ı�����*/
	for (k = i; i <= L->last; k++)/*ɾ����Ͻ������Ԫ��������ǰ�ƶ���Ϊ�˱�֤˳���������ַ���߼���ַһ��*/
		L->data[i - 1] = L->data[i];
	L->last--;
	return 1;
}
void MergeList(SeqList *LA, SeqList *LB, SeqList *LC)/*��֪˳���A��B������ִ�С�������У���A��AB��ϳ�C��ʹ��Ҳ��С������*/
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
	while (i < LA->last)/*��A����ʣ��ʱ����ʣ���Ԫ�ظ���C*/
	{
		LC->data[k] = LA->data[i];
		k++;
		i++;
	}
	while (j < LB->last)/*��B����ʣ��ʱ����ʣ���Ԫ�ظ�ֵ��C*/
	{
		LC->data[k] = LB->data[j];
		k++;
		j++;
	}
	LC->last = LA->last + LB->last + 1;
}