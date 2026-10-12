#include<stdio.h>
#include<stdlib.h>
#define N 5

int deque[N];
int front=-1, rear=-1;

void enqueFront() {
    int x;
    printf("Enter value to insert at front: ");
    scanf("%d",&x);

    if((front==0 && rear==N-1) || (front==rear+1)) {
        printf("Queue is full\n");
    } else if(front==-1) {
        front=rear=0;
        deque[front]=x;
    } else if(front==0) {
        front=N-1;
        deque[front]=x;
    } else {
        front--;
        deque[front]=x;
    }
}

void enqueRear() {
    int x;
    printf("Enter value to insert at rear: ");
    scanf("%d",&x);

    if((front==0 && rear==N-1) || (front==rear+1)) {
        printf("Queue is full\n");
    } else if(front==-1) {
        front=rear=0;
        deque[rear]=x;
    } else if(rear==N-1) {
        rear=0;
        deque[rear]=x;
    } else {
        rear++;
        deque[rear]=x;
    }
}

void display() {
    if(front==-1) {
        printf("Queue is empty\n");
        return;
    }
    int i=front;
    printf("Deque elements: ");
    while(i!=rear) {
        printf("%d ",deque[i]);
        i=(i+1)%N;
    }
    printf("%d\n",deque[rear]);
}

void getFront() {
    if(front==-1) printf("Queue is empty\n");
    else printf("Front element: %d\n",deque[front]);
}

void getRear() {
    if(rear==-1) printf("Queue is empty\n");
    else printf("Rear element: %d\n",deque[rear]);
}

void dequeFront() {
    if(front==-1) {
        printf("Queue is empty\n");
    } else if(front==rear) {
        printf("Deleted: %d\n",deque[front]);
        front=rear=-1;
    } else if(front==N-1) {
        printf("Deleted: %d\n",deque[front]);
        front=0;
    } else {
        printf("Deleted: %d\n",deque[front]);
        front++;
    }
}

void dequeRear() {
    if(front==-1) {
        printf("Queue is empty\n");
    } else if(front==rear) {
        printf("Deleted: %d\n",deque[rear]);
        front=rear=-1;
    } else if(rear==0) {
        printf("Deleted: %d\n",deque[rear]);
        rear=N-1;
    } else {
        printf("Deleted: %d\n",deque[rear]);
        rear--;
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Enqueue Front\n2.Enqueue Rear\n3.Display\n4.Dequeue Front\n5.Dequeue Rear\n6.Get Front\n7.Get Rear\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: enqueFront(); break;
            case 2: enqueRear(); break;
            case 3: display(); break;
            case 4: dequeFront(); break;
            case 5: dequeRear(); break;
            case 6: getFront(); break;
            case 7: getRear(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
