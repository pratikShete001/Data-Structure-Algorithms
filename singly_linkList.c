#include <stdio.h>
#include <stdlib.h>  // Needed for malloc and free

// Self-referential structure
struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *createNode() {
    struct node *n1;
    n1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &n1->data);
    n1->next = NULL;
    return n1;
}

void insertStart() {
    struct node *b1 = createNode();
    if (start == NULL) {
        start = b1;
    } else {
        b1->next = start;
        start = b1;
    }
}

void insertMiddle() {
    struct node *b1 = createNode();
    if (start == NULL) {
        start = b1;
    } else {
        int d;
        printf("Enter a data where you want to store: ");
        scanf("%d", &d);

        struct node *b2 = start;
        while (b2 != NULL && b2->data != d) {
            b2 = b2->next;
        }

        if (b2 == NULL) {
            printf("Data not found\n");
            free(b1);
            return;
        }

        b1->next = b2->next;
        b2->next = b1;
    }
}

void insertEnd() {
    struct node *x = createNode();
    if (start == NULL) {
        start = x;
    } else {
        struct node *d = start;
        while (d->next != NULL) {
            d = d->next;
        }
        d->next = x;
        printf("Inserted successfully at last\n");
    }
}

void deleteStart() {
    if (start == NULL) {
        printf("There is no node to delete\n");
    } else {
        struct node *d = start;
        start = start->next;
        free(d);
    }
}

void deleteEnd() {
    if (start == NULL) {
        printf("There is no node to delete\n");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        struct node *d = start;
        while (d->next->next != NULL) {
            d = d->next;
        }
        free(d->next);
        d->next = NULL;
    }
    printf("Delete successfully\n");
}

void deleteMiddle() {
    if (start == NULL) {
        printf("There is no node to delete\n");
        return;
    }

    int d;
    printf("Enter data to delete: ");
    scanf("%d", &d);

    struct node *n = start;
    while (n->next != NULL && n->next->data != d) {
        n = n->next;
    }

    if (n->next == NULL) {
        printf("Data not found\n");
        return;
    }

    struct node *p = n->next;
    n->next = p->next;
    free(p);
}

void display() {
    if (start == NULL) {
        printf("No node to display\n");
    } else {
        struct node *d = start;
        while (d != NULL) {
            printf("%d ", d->data);
            d = d->next;
        }
        printf("\n");
    }
}

int main() {
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
