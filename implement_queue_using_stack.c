#include<stdio.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;

void push1(int data)
{
	if(top1==N-1)
	{
		printf("Stack is overflow");
	}
	else
	{
		top1++;
		s1[top1]=data;
	}
}

int pop1()
{
	int data= s1[top1];
	top1--;
	return data;
}

void push2(int data)
{
	if(top2==N-1)
	{
		printf("Stack is overflow");
	}
	else
	{
		top2++;
		s2[top2]=data;
	}
}
int pop2()
{
	int data=s2[top2];
	top2--;
	return data;
}

void enqueue(int x)
{
	push1(x);
	count++;
}
void dequeue()
{
	if(top1==-1 && top2==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		int i;
		for(i=0; i<count; i++)
		{
			int data=pop1();
			push2(data);
		}
		int b=pop2();
		printf("Dequed element is %d ",b);
		count--;
		int j=0;
		while(j<=count)
		{
			int data=pop2();
			push1(data);
			j++;
		}
	}
}

void display()
{
	int i=0;
	for(i=0; i<=top1; i++)
	{
		printf("%d ",s1[i]);
	}
}

void peek()
{
	if(top1==-1 && top2==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		int i=0;
		printf("%d",s1[i]);
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
