#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* buatNode(int nilai) {
    struct Node* nodeBaru = (struct Node*)malloc(sizeof(struct Node));
    nodeBaru->nilai = nilai;
    nodeBaru->next = NULL;
    return nodeBaru;
}

void cetakList(struct Node* head) {
    struct Node* curr = head;
    printf("[");
    while (curr != NULL) {
        printf("%d", curr->nilai);
        if (curr->next != NULL) printf(",");
        curr = curr->next;
    }
    printf("]\n");
}

struct Node* buatListDariArray(int arr[], int size) {
    if (size == 0) return NULL;
    struct Node* head = buatNode(arr[0]);
    struct Node* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = buatNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void reorderList(struct Node* head) {
    if (head == NULL || head->next == NULL) return;
    struct Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *prev = NULL, *curr = slow->next, *nextTemp;
    while (curr != NULL) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    slow->next = NULL;
    struct Node *first = head;
    struct Node *second = prev;
    while (second != NULL) {
        struct Node *temp1 = first->next;
        struct Node *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct Node* list = buatListDariArray(arr, 5);
    printf("Input: ");
    cetakList(list);
    reorderList(list);
    printf("Output: ");
    cetakList(list);
    return 0;
}