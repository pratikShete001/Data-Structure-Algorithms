#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else if(((rear+1)%N)==front) // if N=5 and rear=4 & front=0 in this case queue is full;
	{
		printf("Queue is full");
	}
	else
	{
		rear = (rear+1)%N;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		printf("Queue is empty");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		printf("\ndequed element is %d",queue[front]);
		front=(front+1)%N;
	}
}
void display()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		int i=front;
		while (i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%N;
		}
		printf("%d ",queue[rear]);
	}
}
void peek()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("%d",queue[front]);
	}
}
void main()
{
	int x;
	while(1)
	{
		printf("\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.display\n");
		printf("4.peek\n");
		printf("5.exit\n");
		int choice;
		printf("Enter you choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter Element to insert\n");
				scanf("%d",&x);
				enqueue(x);
				break;
			}
			case 2:	dequeue();break;
			case 3: display();break;
			case 4: peek();break;
			case 5: exit(0);break;
			default:printf("plz enter valid choice\n");break;
		}
	}
}
