#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int data[MAX];
int priority[MAX];
int size = 0;

void insert(int newData, int newPriority) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    int i = size - 1;
    while (i >= 0 && priority[i] > newPriority) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    data[i + 1] = newData;
    priority[i + 1] = newPriority;
    size++;
    printf("Inserted successfully.\n");
}

void removeElement() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Removed: %d (priority %d)\n", data[0], priority[0]);

    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\n%-10s %-10s\n", "Data", "Priority");
    printf("----------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-10d %-10d\n", data[i], priority[i]);
    }
}

int main() {
    int choice, newData, newPriority;

    while (1) {
        printf("\n===== Priority Queue Menu =====\n");
        printf("1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &newData);
                printf("Enter priority (1 is highest): ");
                scanf("%d", &newPriority);
                insert(newData, newPriority);
                break;
            case 2:
                removeElement();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}