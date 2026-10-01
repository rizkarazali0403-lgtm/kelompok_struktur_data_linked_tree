#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* ganjilGenapList(struct Node* head) {
    struct Node *ganjilHead = NULL;
    struct Node *ganjilTail = NULL;
    struct Node *genapHead = NULL;
    struct Node *genapTail = NULL;

    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;
        current->next = NULL;

        if (current->nilai % 2 != 0) {
            if (ganjilHead == NULL) {
                ganjilHead = current;
                ganjilTail = current;
            } else {
                ganjilTail->next = current;
                ganjilTail = current;
            }
        } else {
            if (genapHead == NULL) {
                genapHead = current;
                genapTail = current;
            } else {
                genapTail->next = current;
                genapTail = current;
            }
        }

        current = next;
    }

    if (ganjilHead == NULL)
        return genapHead;

    ganjilTail->next = genapHead;

    return ganjilHead;
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

    printf("Sebelum: ");
    tampilkan(head);

    head = ganjilGenapList(head);

    printf("Sesudah: ");
    tampilkan(head);

    return 0;
}