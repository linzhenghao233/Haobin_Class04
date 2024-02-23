#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int Data;
	struct Node* pNext;
}Node, * pNode;

typedef struct Stack {
	pNode pTop;
	pNode pBottom;
}Stack, * pStack;

void InitStack(pStack pS);
void PushStack(pStack pS, int val);
void TraverseStack(pStack pS);
bool PopStack(pStack pS, int* pVal);
void ClearStack(pStack pS);

int main(void) {
	Stack S;
	int val;

	InitStack(&S);
	PushStack(&S, 1);
	PushStack(&S, 2);
	PushStack(&S, 3);
	PushStack(&S, 4);
	PushStack(&S, 5);
	PushStack(&S, 6);
	TraverseStack(&S);

	if (PopStack(&S, &val)) {
		TraverseStack(&S);
		printf("��ջ��ֵ�ǣ�%d\n", val);
	}
	else {
		printf("��ջʧ�ܣ�\n");
	}

	ClearStack(&S);


	return 0;
}

void InitStack(pStack pS) {
	pS->pTop = (pNode)malloc(sizeof(Node));
	if (pS->pTop == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pBottom->pNext = NULL;
}

void PushStack(pStack pS, int val) {
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	pNew->Data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

void TraverseStack(pStack pS) {
	pNode Temp = pS->pTop;

	while(Temp != pS->pBottom) {
		printf("%d ", Temp->Data);
		Temp = Temp->pNext;
	}
	printf("\n");
}

bool PopStack(pStack pS, int* pVal) {
	if (pS->pTop == pS->pBottom)
		return false;

	*pVal = pS->pTop->Data;
	pNode pNew = pS->pTop;
	pS->pTop = pS->pTop->pNext;
	free(pNew);
	pNew = NULL;

	return true;
}

void ClearStack(pStack pS) {
	pNode Temp = (pNode)malloc(sizeof(Node));

	while (pS->pTop != pS->pBottom) {
		Temp = pS->pTop;
		pS->pTop = pS->pTop->pNext;
		free(Temp);
		Temp = NULL;
	}
}
