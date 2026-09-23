#include<stdlib.h>
#include<stdio.h>
struct stack{
	int top;
	int cap;
	int *arr;
};

struct stack *st;
struct stack *createStack(int size)
{
	st = (struct stack *)malloc(sizeof(struct stack));
	st->top = -1;
	st->cap = size;
	st->arr = (int *)calloc(st->cap,sizeof(int));
	return st;
}

void push()
{
	if(!isFull())
	{
		st->top++;
		printf("Enter a data");
		scanf("%d",&st->arr[st->top]);
		printf("Push successful");
	}
	else
	{
		printf("Stack is full");
	}
}
void pop()
{
	if(!isEmpty())
	{
		printf("Popped element is %d",st->arr[st->top]);
		st->top--;
	}
	else
	{
		printf("Stack is Empty");
	}
}
void peek()
{
	
}
int isEmpty()
{
	if(st->top == -1)
	{
		return 1;	
	}
	else
	{
		return 0;
	}	
}
int isFull()
{
	if(st->top == st->cap-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int size,choice;
	printf("Enter a size of array");
	scanf("%d",&size);
	st = createStack(size);
	while(1)
	{
	printf("\n1.push \n2.pop \n3.exit");
	printf("\nEnter you choice: ");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3: exit(0);break;
			default: printf("plz enter valid choice");
		}
	}
	return 0;
}
