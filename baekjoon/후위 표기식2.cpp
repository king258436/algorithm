#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE	1
#define FALSE	0

typedef double Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	Node* head;
} ListStack;


typedef ListStack Stack;
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(0);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(0);
	}

	return pstack->head->data;
}

double EvalRPNExp(char exp[],int arr[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	int tok;
	double  op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (tok>64&&tok<91)
		{
			SPush(&stack, (double)arr[tok-65]);
		}
		else
		{
			op2 = SPop(&stack);     // 먼저 꺼낸 값이 두 번째 피연산자!
			op1 = SPop(&stack);

			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);
}

int main(void)
{
	int operatredNum,i,len;
	char postfix[200];
	int alphaNum[30];
	scanf("%d", &operatredNum);
	scanf("%s", postfix);
	len = strlen(postfix);
	for (i = 0; i < operatredNum; i++) {
		scanf("%d", &alphaNum[i]);
	}
	printf("%.2lf", EvalRPNExp(postfix,alphaNum));
	return 0;
}