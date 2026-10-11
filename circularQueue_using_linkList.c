#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front = NULL;
struct node * rear = NULL;
struct node *createNode()
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter a data: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return newNode;
}
void enqueue()
{
	struct node *newNode;
	newNode=createNode();
	if(front== NULL & rear == NULL)
	{
		front=rear=newNode;
	}
	else
	{
		rear->next=newNode;
		rear=newNode;
	}
}
void display()
{
	struct node *temp;
	if(front==NULL && rear==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		temp=front;
		while(temp != NULL)
		{
		printf("%d ",temp->data);
		temp=temp->next;
		}
	}
	
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("dequed element is %d",front->data);
		front=front->next;
		free(temp);
	}
}
void peek()
{
	if(front==NULL && rear==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("peek element is %d",front->data);	
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
				enqueue();
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
