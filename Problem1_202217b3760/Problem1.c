#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int a, b[MAX], n, p, e, f, i, pos;

void main() {
    //clrscr(); // Assuming this is a non-standard function
    int ch;
    char g = 'y';

    do {
        printf("\n main Menu");
        printf("\n 1.Create \n 2.Delete \n 3.Search \n 4.Insert \n 5.Display \n 6. Exit \n");
        printf("\n Enter your choice");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf(" \n Enter the correct choice: ");
        }

        printf("\n Do u want to continue:::");
        scanf(" %c", &g); // Consume extra newline

    } while (g == 'y' || g == 'Y');

    // getch(); // Assuming this is a non-standard function
}

void create() {
    printf("\n Enter the number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: Maximum nodes exceeded.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n Enter the Element:", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position u want to delete::");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\n Invalid position::");
        return;
    }

    // Shift elements to the left
    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\n The Elements after deletion");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    printf("\n Enter the Element to be searched:");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d Position", i);
            return;
        }
    }

    printf("Value %d is not in the list::", e);
}

void insert() {
    printf("\n Enter the position u need to insert::");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\n Invalid position::");
        return;
    }

    if (n >= MAX) {
        printf("\n Array is full::");
        return;
    }

    // Shift elements to the right
    for (i = n - 1; i >= pos; i--) {
        b[i + 1] = b[i];
    }

    printf("\n Enter the element to insert::\n");
    scanf("%d", &p);

    b[pos] = p;
    n++;

    printf("\n The list after insertion::\n");
    display();
}

void display() {
    printf("\n The Elements of the list ADT are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}