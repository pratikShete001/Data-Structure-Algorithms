#include<stdio.h>
# define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
	if(rear==N-1)
	{
		printf("Queue is full");
	}
	else if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		queue[rear]=x;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty can't delete");
	}
	else if(front==rear)// only one element left in queue 
	{
		front=rear=-1;
	}
	else
	{
		printf("Dequed element from queue is %d",queue[front]);
		front++;
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
		while(i<rear+1)
		{
			printf("%d ",queue[i]);
			i++;
		}
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
		printf("%d ",queue[front]);
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
