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

void InitStack();

int main(void) {
	Stack S;

	InitStack();
	PushStack();
	PushStack();
	TraverseStack();

	return 0;
}