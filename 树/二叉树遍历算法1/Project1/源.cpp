//定义二叉树的节点//
typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}Bitnode,*Bitree;
/*递归算法遍历二叉树*/
void Preorder(Bitree root)
{/*先序遍历二叉树，root为指向二叉树或子树某一根结点的指针*/
	if (root != NULL);
	{
		Visit(root->data);/*访问根结点*/
		Preorder(root->Lchild);/*先序遍历二叉树的左子树*/
		Preorder(root->Rchild);/*先序遍历二叉树的右子树*/
	}
}
void Inorder(Bitree root)
{/*中序遍历二叉树，root为指向二叉树根结点或某一子树的指针*/
	if (root != NULL)
	{
		Inorder(root->Lchild);/*中序遍历二叉树的左子树*/
		Visit(root->data);/*访问根结点*/
		Inorder(root->Rchild);/*中序遍历二叉树的右子树*/

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
/*遍历算法的应用*/
/*输出二叉树的结点*/
void Preorder(Bitree root)
{
	if (root != NULL)
	{
		printf(root->data);/*输出根结点*/
		Preorder(root->Lchild);/*先序遍历左子树*/
		Preorder(root->Rchild);/*先序遍历右子树*/
	}
}
/*输出二叉树中叶子的子结点*/
void Preorder(Bitree root)
{
	if (root != NULL)
	{
		if (root->Lchild == NULL && root->Rchild == NULL)
			printf(root->data);/*输出叶子结点*/
		Preorder(root->Lchild);
		Preorder(root->Rchild);
	}
}
/*统计二叉树中叶子结点数目*/
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
/*输出二叉树中叶子结点数目，分治算法*/
int leaf(Bitree root)
{
	int count = 0;
	if (root == NULL)
		count = 0;/*为空树结点数为0*/
	else
		if (root->Lchild = NULL && root->Rchild == NULL)
			count = 1;/*只有一个结点*/
		else
			count = leaf(root->Lchild) + leaf(root->Rchild);/*叶子数为左子树和右子树叶子数之和*/
	return count;
}
