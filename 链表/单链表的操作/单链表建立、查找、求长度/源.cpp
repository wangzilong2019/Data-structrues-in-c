typedef struct Node /*������Ͷ���*/
{
	char data;
	struct Node *next;
}*LinkList,Node;/*LinkListΪ�ṹ��ָ������*/
void InitList(LinkList *L)
{  
	*L = (LinkList)malloc(sizeof(Node));/*����ͷ���*/
	(*L)->next = NULL;/*�����յĵ�����*/
}
/*ͷ�巨��������*/
void CreateFromHead(LinkList L)/*L�Ǵ�ͷ���ĵ�����ͷָ�룬ͨ������������е�Ԫ��ֵ������ͷ�巨��������L*/
{
	Node *s;
	int flag;
	char ch;
	flag = 1;
	while (flag)/*flag��ֵΪ1��������"$"ʱ����flagΪ0���������*/
	{
		ch = getchar();
		if (ch != '$')
		{
			s = (Node*)malloc(sizeof(Node));/*����ͷ���*/
			s->data = ch;
			s->next = L->next;/*��ͷ�������ͷ*/
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}
/*β�巨����������*/
void CreatFromTail(LinkList L)/*L�Ǵ�ͷ���Ŀ������ͷָ�룬ͨ����������Ԫ�أ�����β�巨����������L*/
{
	Node *s,*r;
	char ch;
	int flag = 1;/*����һ����־����ֵΪ1��������"$"ʱ��flag��Ϊ0���������*/
	r = L;/*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
	while (flag)/*ѭ���������Ԫ��ֵ�����������½ڵ�s�����β*/
	{
		ch = getchar();
		if (ch != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = ch;
			L->next = s;
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;/*�����һ������next����Ϊ�գ���ʾ�������*/
		}
	}

}
/*�������в��ҵ�i�����*/
Node* Get(LinkList L,int i)/*��ͷ���ĵ�������ҵ�i��������ҵ���1<=i<=n)���򷵻ظý��Ĵ洢λ�ã����򷵻�NULL*/
{
	int j;
	Node *p;
	if (i <= 0)
	{
		return NULL;
	}
	p = L;/*��ͷ��㿪ʼɨ��*/
	j = 0;
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;/*ɨ����һ�����*/
		j++;/*��֪ɨ����ļ�����*/
	}
	if (i == j) /*�ҵ��˵�i����㣬���ص�ַ*/
		return p;
	else
		return NULL;/*�Ҳ�����i<=0��i>=n*/
}
/*�������в���ֵΪkey�Ľ��*/
Node* Locate(LinkList L, char key)
{/*�ڵ�����L�в���ֵΪ��һ��key�Ľ�㣬���ҵ��򷵻ظý��λ�ã����򷵻ؿ�*/
	Node *p;
	p = L->next;/*�ӵ�����ĵ�һ����㿪ʼ*/
	while (p != NULL) /*��ǰ��δ����*/
	{
		if (p->data != key)
			p = p->next;
		else
		{
			return p;/*�ҵ����ֵkeyʱ�˳�ѭ��*/
			break;
		}
	}
}
int ListLength(LinkList L)
{/*���ͷ���ĵ�����L�ĳ���*/
	Node *p;
	int i;
	i = 0;/*������ŵ�����ĳ���*/
	p = L;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;/*iΪ����ĵ�����ĳ���*/
}
/*������������*/
void InsList(LinkList L, int i, char e)
{/*�ڵ�����L����λ��i������Ԫ��e*/
	Node *s, *pre;
	int k;
	if (i <= 0)
		printf("����λ�ò��Ϸ�");
	pre = L;
	k = 0;/*�ӡ�ͷ����ʼ��Ѱ�ҵ�i-1�����*/
	while (pre != NULL && k < i - 1)/*��δ���꣬���ҵ�i-1�����ʱ�������ҵ�preָ���i-1�����*/
	{
		pre = pre->next;
		k = k + 1;
	}
	if (pre == NULL)
		printf("����λ�ò��Ϸ�");
	s = (Node*)malloc(sizeof(Node));/*������һ�����*/
	s->data = e;/*��ֵ����e��������*/
	s->next = L->next;/*�޸�ָ�룬��ɲ������*/
	pre->next = s;
}
/*������ɾ������*/
void DelList(LinkList L, int i, char *e)
{/*�ڴ�ͷ���ĵ�������ɾ����i��Ԫ�أ��ҽ�ɾ����Ԫ�ر����ڱ���*e��*/
	Node *pre, *r;
	int k;
	pre = L;
	k = 0;
	if (i <= 0)
		printf("ɾ��λ�ò��Ϸ�");
	while (pre->next != NULL && k < i - 1) /*Ѱ�ұ�ɾ���ڵ�ĵ�i-1����㣬��ʹpָ����*/
	{
		pre = pre->next;
		k++;
	}
	if (pre->next == NULL)/*whileѭ������Ϊp->next=NULL,��i<1����������Ϊpre->next��û���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ����λ�ò��Ϸ�*/
		printf("ɾ�����λ�ò��Ϸ�");
	r = pre->next;
	pre->next = r->next;/*�޸�ָ�룬ɾ�����i*/
	*e = r->data;
	free(r);/*�ͷű�ɾ���Ľ����ڴ�ռ�*/
}
/*�ϲ���������ĵ�����*/
LinkList MergeLinkList(LinkList LA, LinkList LB)
{/*����������ĵ�����LA,LB�ϲ���һ�������ĵ�����LC*/
	Node *pa, *pb, *pc,*r;
	LinkList LC;/*��LC��ʼ��Ϊ�ձ�pa��pb�ֱ�ָ������������ĵ�һ����㣬r��ֵΪLC��ʼ��ָ���β*/
	LC->next = NULL;
	pa = LA->next;
	pb = LB->next;
	pc = LC->next;
	r = LC;/*��������δ����ʱ��ѡ��Ƚ�����ѡ����С�Ĵ���LC��*/
	while (pa != NULL && pb != NULL)
	{
		if (pa->data > pb->data)
		{
			r->next = pb;
			r = pb;
			pb = pb->next;
		}
		else
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
		}
		if (pa)/*����LAδ�꣬����LA�к���Ԫ�������±�LCβ*/
			r->next = pa;
		else
			r->next = pb;/*����LB�к���Ԫ������LC��β*/
		free(LB);
		free(LA);
		return LC;
	}
}