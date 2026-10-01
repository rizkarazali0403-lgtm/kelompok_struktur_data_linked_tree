#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* hapusDariAkhir(struct Node* head, int n) {
    struct Node dummy;
    dummy.next = head;

    struct Node* fast = &dummy;
    struct Node* slow = &dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node* temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}

struct Node* buatNode(int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->nilai = nilai;
    baru->next = NULL;
    return baru;
}

void tampilkan(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->nilai);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = buatNode(1);
    head->next = buatNode(2);
    head->next->next = buatNode(3);
    head->next->next->next = buatNode(4);
    head->next->next->next->next = buatNode(5);

    int n = 2;

    printf("Sebelum: ");
    tampilkan(head);

    head = hapusDariAkhir(head, n);

    printf("Sesudah: ");
    tampilkan(head);

    return 0;
}