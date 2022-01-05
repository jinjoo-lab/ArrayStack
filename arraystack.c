#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
}Node;
typedef struct Arraystack
{
	int capacity; // 스택의 용량
	int top; // 최상위 노드 ( 스택에서의 연산은 최상위 노드를 기준으로 수행)
	Node* node; // 포인터를 사용해 배열로 접근
}Stack;
void createStack(Stack* pstack,int capacity)
{
	pstack->node=(Node*)malloc(sizeof(Node)*capacity); // 주어진 용량만큼의 배열 생성
	pstack->capacity=capacity; 
	pstack->top=-1; // 처음 생성하면 데이터가 아무것도 없기 때문에 -1로 위치 고정
} // 스택 생성 함수
int isEmpty(Stack* pstack) // stack이 비어있는지 확인
{
	if(pstack->top==-1) // top의 위치가 -1이면 스택에 데이터가 저장되지 않은 상태
		return -1;
	else
		return 1;
}
void push(Stack* pstack,int data) // push 연산
{
	if(pstack->capacity==pstack->top+1) // 해당 용량에 데이터가 꽉 찬 경우
	{
		Node* newnode=(Node*)malloc(sizeof(Node)*(pstack->capacity*1.3));// 용량을 30% 늘린 배열 생성
		int i=0;
		for(i=0;i<pstack->capacity;i++)
		{
			newnode[i].data=pstack->node[i].data;
		} // 복사 작업 진행 
		pstack->node=newnode; // 배열 교체
		pstack->capacity=pstack->capacity*1.3;
	}
	pstack->top++; // 데이터 저장시 top의 위치 증가
	pstack->node[pstack->top].data=data; // 데이터 저장
}
int pop(Stack* pstack) // pop 연산
{
	int re;
	if(isEmpty(pstack)==-1) // 스택이 비어있는 경우 삭제 불가
		return -1;
	if(pstack->top+1<pstack->capacity*0.7) // 스택의 사용량이 용량의 70%인경우
	{
		Node* newnode=(Node*)malloc(sizeof(Node)*(pstack->capacity*0.7)); // 용량을 줄인 배열 생성
		int i=0;
		for(i=0;i<pstack->top;i++)
		{
			newnode[i].data=pstack->node[i].data;
		} // 복사 작업 진행
		pstack->node=newnode; // 배열 교체
		pstack->capacity=pstack->capacity*0.7;
	}
	re=pstack->node[pstack->top].data; // 반환할 데이터값 저장
	pstack->top--; // top의 위치 조정

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