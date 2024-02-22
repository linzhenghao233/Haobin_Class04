#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
	Stack S;

	InitStack(&S);
	PushStack(&S, 1);
	PushStack(&S, 2);
	TraverseStack(&S);

	return 0;
}

void InitStack(pStack pS) {
	pS->pTop = (pNode)malloc(sizeof(Node));
	if (pS->pTop == NULL) {
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pBottom->pNext = NULL;
}

void PushStack(pStack pS, int val) {
	pS->pTop->Data = val;
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(-1);
	}
	pNew->pNext = NULL;
	pS->pTop->pNext = pNew;
}

void TraverseStack(pStack pS) {
	pStack pTemp = pS;

	while (pTemp->pBottom->pNext != NULL) {
		printf("%d", pTemp->pBottom->pNext->Data);
		pTemp->pBottom = pTemp->pBottom->pNext;
	}
}
