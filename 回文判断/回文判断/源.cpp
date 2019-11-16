#include<stdio.h>
#include<Windows.h>
#define Stack_Size 100
typedef struct
{
	char elem[ Stack_Size];
	int top;
}SeqStack;
/*初始化顺序栈*/
void InitSeqStack(SeqStack *S)
{
	S->top = -1;
}
void Push(SeqStack *S, char x)
{
	if (S->top == Stack_Size - 1)
		printf("\n栈已满");
	else
	{
		S->top++;
		S->elem[(S->top)] = x;
	}
}
char* Pop(SeqStack *S, char *x)
{
	if (S->top == -1)
		printf("\n栈已空");
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return x;
	}
	
}
void Ishuiwen()
{
	SeqStack *S;
	char ch,*temp;
	S = (SeqStack*)malloc(sizeof(SeqStack));
	InitSeqStack(S);
	printf("请输入字符序列：\n");
	ch = getchar();
	while (ch != '&')
	{
		Push(S, ch);
		ch = getchar();
	}
	ch = getchar();
	do
	{
		temp = &(S->elem[S->top]);
		temp=Pop(S, temp);
		if (ch != *temp)
		{
			printf("\nNO");
		}
		else
		{
			ch = getchar();
		}
	} while (ch != '@'&& S->top!=-1);
	if (ch == '@ '&& S->top==-1)
	{
		printf("\nYES");
	}
	else
	{
		printf("\nNO");
	}
}
int main()
{
	Ishuiwen();
	system("pause");
	return 0;
}
