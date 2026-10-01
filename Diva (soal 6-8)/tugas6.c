#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool apaPalindrom(struct Node* head) {
    if (head == NULL || head->next == NULL) return true;
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
    struct Node *p1 = head, *p2 = prev;
    bool hasil = true;
    while (p2 != NULL) {
        if (p1->nilai != p2->nilai) {
            hasil = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return hasil;
}

int main() {
    int arr1[] = {1, 2, 2, 1};
    struct Node* list1 = buatListDariArray(arr1, 4);
    printf("Input: ");
    cetakList(list1);
    printf("Output: %s\n\n", apaPalindrom(list1) ? "true" : "false");

    int arr2[] = {1, 2};
    struct Node* list2 = buatListDariArray(arr2, 2);
    printf("Input: ");
    cetakList(list2);
    printf("Output: %s\n", apaPalindrom(list2) ? "true" : "false");
    return 0;
}