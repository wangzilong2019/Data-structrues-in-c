#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* LChild;
	struct Node* RChild;
	char data;
}Tree, *Ptree;

void Creat(Ptree *r)
{
	char ch;
	ch = getchar();
	if (ch != '#')
	{
		(*r) = (Ptree)malloc(sizeof(Tree));
		(*r)->data = ch;
		Creat(&((*r)->LChild));
		Creat(&((*r)->RChild));
	}
	else
		(*r) = NULL;

}
void postOrder(Ptree p)
{
	if (p != NULL)
	{
		postOrder(p->LChild);
		printf("%c", p->data);
		postOrder(p->RChild);
	}
}
int main()
{
	Ptree tree;
	Creat(&tree);
	postOrder(tree);
	system("pause");
	return 0;
}