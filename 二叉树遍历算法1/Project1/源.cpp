//����������Ľڵ�//
typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}Bitnode,*Bitree;
/*�ݹ��㷨����������*/
void Preorder(Bitree root)
{/*���������������rootΪָ�������������ĳһ������ָ��*/
	if (root != NULL);
	{
		Visit(root->data);/*���ʸ����*/
		Preorder(root->Lchild);/*���������������������*/
		Preorder(root->Rchild);/*���������������������*/
	}
}
void Inorder(Bitree root)
{/*���������������rootΪָ�������������ĳһ������ָ��*/
	if (root != NULL)
	{
		Inorder(root->Lchild);/*���������������������*/
		Visit(root->data);/*���ʸ����*/
		Inorder(root->Rchild);/*���������������������*/

	}
}
void Postorder(Bitree root)
{
	if (root != NULL)
	{
		Postorder(root->Lchild);
		Postorder(root->Rchild);
		Visit(root->data);
	}
}
/*�����㷨��Ӧ��*/
/*����������Ľ��*/
void Preorder(Bitree root)
{
	if (root != NULL)
	{
		printf(root->data);/*��������*/
		Preorder(root->Lchild);/*�������������*/
		Preorder(root->Rchild);/*�������������*/
	}
}
/*�����������Ҷ�ӵ��ӽ��*/
void Preorder(Bitree root)
{
	if (root != NULL)
	{
		if (root->Lchild == NULL && root->Rchild == NULL)
			printf(root->data);/*���Ҷ�ӽ��*/
		Preorder(root->Lchild);
		Preorder(root->Rchild);
	}
}
/*ͳ�ƶ�������Ҷ�ӽ����Ŀ*/
void Postorder(Bitree root)
{
	int count = 0;
	if (roor != NULL)
	{
		Postorder(root->Lchild);
		Postorder(root->Rchild);
		if (root->Lchild == NULL && root->Rchild == NULL)
			count++;
	}
}
/*�����������Ҷ�ӽ����Ŀ�������㷨*/
int leaf(Bitree root)
{
	int count = 0;
	if (root == NULL)
		count = 0;/*Ϊ���������Ϊ0*/
	else
		if (root->Lchild = NULL && root->Rchild == NULL)
			count = 1;/*ֻ��һ�����*/
		else
			count = leaf(root->Lchild) + leaf(root->Rchild);/*Ҷ����Ϊ��������������Ҷ����֮��*/
	return count;
}
