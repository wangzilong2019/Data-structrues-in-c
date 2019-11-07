typedef struct Node /*结点类型定义*/
{
	char data;
	struct Node *next;
}*LinkList,Node;/*LinkList为结构体指针类型*/
void InitList(LinkList *L)
{  
	*L = (LinkList)malloc(sizeof(Node));/*建立头结点*/
	(*L)->next = NULL;/*建立空的单链表*/
}
/*头插法建单链表*/
void CreateFromHead(LinkList L)/*L是带头结点的单链表头指针，通过键盘输入表中的元素值，利用头插法建单链表L*/
{
	Node *s;
	int flag;
	char ch;
	flag = 1;
	while (flag)/*flag初值为1，当输入"$"时，置flag为0，建表结束*/
	{
		ch = getchar();
		if (ch != '$')
		{
			s = (Node*)malloc(sizeof(Node));/*建立头结点*/
			s->data = ch;
			s->next = L->next;/*将头结点插入表头*/
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}
/*尾插法建立单链表*/
void CreatFromTail(LinkList L)/*L是带头结点的空链表的头指针，通过键盘输入元素，利用尾插法建立单链表L*/
{
	Node *s,*r;
	char ch;
	int flag = 1;/*设置一个标志，初值为1，当输入"$"时，flag置为0，建表结束*/
	r = L;/*r指针动态指向但链表的当前表尾，以便于做尾插入，其初值指向头结点*/
	while (flag)/*循环输入表中元素值，将建立的新节点s插入表尾*/
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
			r->next = NULL;/*将最后一个结点的next域置为空，表示链表结束*/
		}
	}

}
/*单链表中查找第i个结点*/
Node* Get(LinkList L,int i)/*带头结点的单链表查找第i个结点若找到（1<=i<=n)，则返回该结点的存储位置，否则返回NULL*/
{
	int j;
	Node *p;
	if (i <= 0)
	{
		return NULL;
	}
	p = L;/*从头结点开始扫描*/
	j = 0;
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;/*扫描下一个结点*/
		j++;/*已知扫描结点的计数器*/
	}
	if (i == j) /*找到了第i个结点，返回地址*/
		return p;
	else
		return NULL;/*找不到，i<=0或i>=n*/
}
/*单链表中查找值为key的结点*/
Node* Locate(LinkList L, char key)
{/*在单链表L中查找值为第一个key的结点，若找到则返回该结点位置，否则返回空*/
	Node *p;
	p = L->next;/*从单链表的第一个结点开始*/
	while (p != NULL) /*当前表未查完*/
	{
		if (p->data != key)
			p = p->next;
		else
		{
			return p;/*找到结点值key时退出循环*/
			break;
		}
	}
}
int ListLength(LinkList L)
{/*求带头结点的单链表L的长度*/
	Node *p;
	int i;
	i = 0;/*用来存放单链表的长度*/
	p = L;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;/*i为所求的单链表的长度*/
}
/*单链表插入操作*/
void InsList(LinkList L, int i, char e)
{/*在单链表L中在位置i处插入元素e*/
	Node *s, *pre;
	int k;
	if (i <= 0)
		printf("插入位置不合法");
	pre = L;
	k = 0;/*从“头”开始，寻找第i-1个结点*/
	while (pre != NULL && k < i - 1)/*表未查完，或找到i-1个结点时结束，找到pre指向第i-1个结点*/
	{
		pre = pre->next;
		k = k + 1;
	}
	if (pre == NULL)
		printf("插入位置不合法");
	s = (Node*)malloc(sizeof(Node));/*新申请一个结点*/
	s->data = e;/*将值插入e的数据域*/
	s->next = L->next;/*修改指针，完成插入操作*/
	pre->next = s;
}
/*单链表删除操作*/
void DelList(LinkList L, int i, char *e)
{/*在带头结点的单链表中删除第i个元素，且将删除的元素保存在变量*e中*/
	Node *pre, *r;
	int k;
	pre = L;
	k = 0;
	if (i <= 0)
		printf("删除位置不合法");
	while (pre->next != NULL && k < i - 1) /*寻找被删除节点的第i-1个结点，并使p指向它*/
	{
		pre = pre->next;
		k++;
	}
	if (pre->next == NULL)/*while循环是因为p->next=NULL,或i<1而跳出，因为pre->next，没有找到合法的前驱位置，说明删除的位置不合法*/
		printf("删除结点位置不合法");
	r = pre->next;
	pre->next = r->next;/*修改指针，删除结点i*/
	*e = r->data;
	free(r);/*释放被删除的结点的内存空间*/
}
/*合并俩个有序的单链表*/
LinkList MergeLinkList(LinkList LA, LinkList LB)
{/*将有序递增的单链表LA,LB合并成一个递增的单链表LC*/
	Node *pa, *pb, *pc,*r;
	LinkList LC;/*将LC初始置为空表，pa，pb分别指向俩个单链表的第一个结点，r初值为LC，始终指向表尾*/
	LC->next = NULL;
	pa = LA->next;
	pb = LB->next;
	pc = LC->next;
	r = LC;/*当俩个表未处理时，选择比较俩个选择最小的存入LC中*/
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
		if (pa)/*若表LA未完，将表LA中后序元素链到新表LC尾*/
			r->next = pa;
		else
			r->next = pb;/*否则将LB中后序元素链到LC表尾*/
		free(LB);
		free(LA);
		return LC;
	}
}