#include <stdio.h>
#include <stdlib.h>
#define QSIZE 2

int r = -1, f = 0, count = 0;
char task[QSIZE];
void Add()
{
    if (count == QSIZE)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the item to be added\n");
    char item;
    scanf(" %c", &item);
    r = (r + 1) % QSIZE;
    task[r] = item;
    count++;
}

void display(int front)
{
    int i;
    if (count == 0)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("\n Contents of the queue\n");
    for (i = 0; i < count; i++)
    {
        printf("%c ", task[(front + i) % QSIZE]);
    }
    printf("\n");
}
void Process()
{  
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The item deleted is: %c\n", task[f]);
    f = (f + 1) % QSIZE;
    count--;
}
void main()
{  
    int choice;
    do
    {
        printf("\nCircular Queue Operations\n");
        printf("Add\n");
        printf("Process\n");
        printf("Display\n");
        printf("Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: Add();
            break;
        case 2:Process();
            break;
        case 3:display(f);
            break;
        case 4:
               exit(0);
        default:   printf("Invalid choice\n");
        }
    } while (choice != 4);
}