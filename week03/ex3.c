#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertNode(struct Node *head, int value) {
    struct Node *newNode = malloc(sizeof *newNode);
    newNode->data = value;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        struct Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr -> next = newNode;
    }
}

void printList(struct Node *head) {
    if (head->next == NULL) {
        printf("There are no elements in the Linked List\n");
        return;
    }

    printf("Elements in the Linked List: ");
    struct Node *ptr = head;
    do {
        ptr = ptr->next;
        printf("%d ", ptr->data);
    } while (ptr->next != NULL);
    printf("\n");
}

void deleteNode(struct Node *head, int value) {
    if (head->next == NULL) {
        printf("There are no elements in the Linked List\n");
        return;
    }


    if (head->next->data == value) {
        head->next = head->next->next;
        return;
    }

    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1 -> next;

    if (ptr2->next == NULL)
        return;

    do {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr2->data == value) {
            ptr1->next = ptr2->next;
            break;
        }

    } while (ptr2->next != NULL);
}




int main() {
    struct Node *linkedList = malloc(sizeof *linkedList); // head
    linkedList->next = NULL;

    insertNode(linkedList, 2);
    insertNode(linkedList, 3);
    insertNode(linkedList, 5);

    printList(linkedList);

    deleteNode(linkedList, 2);

    printList(linkedList);

    deleteNode(linkedList, 3);

    printList(linkedList);

    deleteNode(linkedList, 5);

    printList(linkedList);

    return 0;
}
