#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node * prev;
	int info;
	struct node *next;
};
struct node *head = NULL;
struct node *createNode()
{
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&n->info);
	n->prev = NULL;
	n->next = NULL;
	return n;
}
void insertStart(){
	struct node *s;
	s = createNode();
	if(head == NULL)
	{
		head = s;
	}
	else
	{
		s->next = head;
		head->prev = s;
		head = s;
	}
}
void insertEnd(){	
	struct node *d,*b;
	b = head;
	d = createNode();
	if(head == NULL)
	{
		head = d;
	}
	else
	{
		while(b->next != NULL)
		{
			b = b->next;
		}
		d->prev = b;
		b->next = d;
	}
}
void insertMiddle(){
	int data;
	struct node *newNode = createNode();
	struct node *current = head;
	printf("Where you want to insert");
	scanf("%d",&data);
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		while(current->info !=data && current != NULL)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		newNode->prev = current->next->prev;
		current->next->prev = newNode;
	}
}
void deleteStart()
{
	struct node *d;
	d = head;
	
	if(head == NULL)
	{
		printf("There is no node to delete");
	}
	else
	{
		head= head->next;
		head->prev=NULL;
		d->next = NULL;
		free(d);
	}
}
void deleteEnd(){
	struct node *current = head;
	if(head == NULL)
	{
		printf("There is no any node to delete");
	}
	else
	{
	
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	current->prev = NULL;
	free(current);
	}
}
void deleteMiddle(){
	
	struct node *current;
	current = head;
	int data;
	printf("Which data that you want to delete");
	scanf("%d",&data);
	if(current == NULL)
	{
		printf("There is no node to delete");
	
	}
	else
	{
		while(current != NULL && current->info != data)
		{
			current = current ->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current->prev = NULL;
		current->next = NULL;
		free(current);
	}
}
void display(){
	if(head == NULL)
	{
		printf("There is no any node to display");
	}
	else
	{
		struct node *b1;
		b1 = head;
		while(b1!=NULL)
		{
			printf("%d ",b1->info);
			b1= b1->next;
		}
	}
}

int main()
{
	while (1) {
        int choice;
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

        switch (choice) {
            case 1: insertStart(); break;
            case 2: insertEnd(); break;
            case 3: insertMiddle(); break;
            case 4: deleteStart(); break;
            case 5: deleteEnd(); break;
            case 6: deleteMiddle(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Invalid Input\n");
        }
    }
}
