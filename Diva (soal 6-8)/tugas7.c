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

struct Node* hapusNilai(struct Node* head, int x) {
    struct Node dummy;
    dummy.next = head;
    struct Node *curr = &dummy;
    while (curr->next != NULL) {
        if (curr->next->nilai == x) {
            struct Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return dummy.next;
}

int main() {
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    struct Node* list = buatListDariArray(arr, 7);
    printf("Input: ");
    cetakList(list);
    printf("Hapus nilai 6\n");
    list = hapusNilai(list, 6);
    printf("Output: ");
    cetakList(list);
    return 0;
}