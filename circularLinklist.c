#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};
struct node*head;
struct node *createNode()
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter a data");
	scanf("%d",&newNode->data);
	newNode->next = head;
	return newNode;
}

void insertStart()
{
	struct node*current, *newNode ;
	newNode = createNode();
	if(head == NULL)
	{
		head = newNode;
		newNode->next = head; 
	}
	else
	
	{	
		newNode->next = head;
		current = head;
		while(current->next != head)
		{
			current = current->next;
		}
	
		current->next = newNode;
		head = newNode;
	}
}
void insertEnd()
{
	struct node *newNode;
	newNode =createNode();
	struct node *current;
	current = head;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		while(current->next != head)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next = head;
	}
}
void insertMiddle()
{
	struct node *j1,*j2;
	j1 = createNode();
	if(head == NULL)
	{
		head = j1;
	}
	else
	{
		j2 = head;
		int d;
		printf("Enter where you want to insert:");
		scanf("%d",&d);
		int i;
		for(i=0; i<1; i++)
		{
			j2 = j2->next;
		}
			
	}
}
void deleteStart()
{
	struct node *x;

	if(head == NULL)
	{
		printf("No node to delete");
	}
	else
	{
		x = head;
		while(x->next != head)
		{
			x = x->next;
		}
		x->next = head->next;
		x= head;
		head = head->next;
		x->next = NULL;
		free(x);
	}
}
void deleteEnd(){
	struct node *current,*x;
	current = head;
	if(head == NULL)
	{
		printf("There is no node to delete");
	}
	else
	{
		while(current->next->next != head )
		{
			current = current->next;
		}
		x=current->next;
		current->next = head;
		x->next = NULL;
		free(x);
	}
}
void deleteMiddle()
{
	int data;
	printf("Enter a data to delete");
	scanf("%d",&data);
	struct node *current,*x;
	current = head;
	x = head;
	if(head == NULL)
	{
		printf("There is no node to delete");
	}
	else
	{
		while(current->next->data != data)
		{
			current = current->next;
		}
		x = current->next;
		current->next =x->next;
		x->next = NULL;
		free(x);
		
	}	
}
void display(){
	if(head == NULL)
	{
		printf("no data");
	}else{
		struct node *current;
		current = head;
		while(current->next != head )
		{
			printf("%d ",current->data);
			current = current->next;
		}
		printf("%d ",current->data);
	}
	
}
int main()
{
	int choice;
	while(1)
	{
		
        printf("\n1. Insert from start\n");
        printf("2. Insert from end\n");
        printf("3. Insert from middle\n");
        printf("4. Delete from start\n");
        printf("5. Delete from end\n");
        printf("6. Delete from middle\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1: insertStart(); break;
            case 2: insertEnd(); break;
            case 3: insertMiddle(); break;
            case 4: deleteStart(); break;
            case 5: deleteEnd(); break;
            case 6: deleteMiddle(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid Input\n");
        }
    }
}
