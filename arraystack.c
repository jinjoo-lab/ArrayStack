#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
}Node;
typedef struct Arraystack
{
	int capacity; // ������ �뷮
	int top; // �ֻ��� ��� ( ���ÿ����� ������ �ֻ��� ��带 �������� ����)
	Node* node; // �����͸� ����� �迭�� ����
}Stack;
void createStack(Stack* pstack,int capacity)
{
	pstack->node=(Node*)malloc(sizeof(Node)*capacity); // �־��� �뷮��ŭ�� �迭 ����
	pstack->capacity=capacity; 
	pstack->top=-1; // ó�� �����ϸ� �����Ͱ� �ƹ��͵� ���� ������ -1�� ��ġ ����
} // ���� ���� �Լ�
int isEmpty(Stack* pstack) // stack�� ����ִ��� Ȯ��
{
	if(pstack->top==-1) // top�� ��ġ�� -1�̸� ���ÿ� �����Ͱ� ������� ���� ����
		return -1;
	else
		return 1;
}
void push(Stack* pstack,int data) // push ����
{
	if(pstack->capacity==pstack->top+1) // �ش� �뷮�� �����Ͱ� �� �� ���
	{
		Node* newnode=(Node*)malloc(sizeof(Node)*(pstack->capacity*1.3));// �뷮�� 30% �ø� �迭 ����
		int i=0;
		for(i=0;i<pstack->capacity;i++)
		{
			newnode[i].data=pstack->node[i].data;
		} // ���� �۾� ���� 
		pstack->node=newnode; // �迭 ��ü
		pstack->capacity=pstack->capacity*1.3;
	}
	pstack->top++; // ������ ����� top�� ��ġ ����
	pstack->node[pstack->top].data=data; // ������ ����
}
int pop(Stack* pstack) // pop ����
{
	int re;
	if(isEmpty(pstack)==-1) // ������ ����ִ� ��� ���� �Ұ�
		return -1;
	if(pstack->top+1<pstack->capacity*0.7) // ������ ��뷮�� �뷮�� 70%�ΰ��
	{
		Node* newnode=(Node*)malloc(sizeof(Node)*(pstack->capacity*0.7)); // �뷮�� ���� �迭 ����
		int i=0;
		for(i=0;i<pstack->top;i++)
		{
			newnode[i].data=pstack->node[i].data;
		} // ���� �۾� ����
		pstack->node=newnode; // �迭 ��ü
		pstack->capacity=pstack->capacity*0.7;
	}
	re=pstack->node[pstack->top].data; // ��ȯ�� �����Ͱ� ����
	pstack->top--; // top�� ��ġ ����

	return re;
}
void print(Stack* pstack)
{
	int i;
	for(i=0;i<=pstack->top;i++)
	{
		printf("%d ",pstack->node[i].data);
	}printf("\n");
}
int main(void)
{
	Stack stack;
	createStack(&stack,10);
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	push(&stack,4);
	push(&stack,5);
	push(&stack,6);
	push(&stack,7);
	push(&stack,8);
	push(&stack,9);
	push(&stack,10);
	print(&stack);
	push(&stack,11);
	printf("capacity: %d\n",stack.capacity);
	print(&stack);
	pop(&stack);
	print(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	print(&stack);
	printf("capacity: %d\n",stack.capacity);
} 