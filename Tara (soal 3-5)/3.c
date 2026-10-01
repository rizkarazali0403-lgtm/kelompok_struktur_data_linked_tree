#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* hapusDuplikasi(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->nilai == current->next->nilai) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
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
    head->next = buatNode(1);
    head->next->next = buatNode(2);
    head->next->next->next = buatNode(3);
    head->next->next->next->next = buatNode(3);

    printf("Sebelum: ");
    tampilkan(head);

    head = hapusDuplikasi(head);

    printf("Sesudah: ");
    tampilkan(head);

    return 0;
}