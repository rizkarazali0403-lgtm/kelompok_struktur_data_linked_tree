#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* buatNode(int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));

    baru->nilai = nilai;
    baru->next = NULL;

    return baru;
}

void tampilList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->nilai);
        head = head->next;
    }

    printf("\n");
}

/* SOAL 2 */

struct Node* partisiList(struct Node* head, int x) {

    struct Node* kecil = NULL;
    struct Node* kecilTail = NULL;

    struct Node* besar = NULL;
    struct Node* besarTail = NULL;

    struct Node* current = head;

    while (current != NULL) {

        struct Node* baru = buatNode(current->nilai);

        if (current->nilai < x) {

            if (kecil == NULL) {
                kecil = baru;
                kecilTail = baru;
            } else {
                kecilTail->next = baru;
                kecilTail = baru;
            }

        } else {

            if (besar == NULL) {
                besar = baru;
                besarTail = baru;
            } else {
                besarTail->next = baru;
                besarTail = baru;
            }
        }

        current = current->next;
    }

    if (kecil == NULL) {
        return besar;
    }

    kecilTail->next = besar;

    return kecil;
}

int main() {

    /* DATA SOAL 2 */

    struct Node* data2 = buatNode(1);
    data2->next = buatNode(4);
    data2->next->next = buatNode(3);
    data2->next->next->next = buatNode(2);
    data2->next->next->next->next = buatNode(5);
    data2->next->next->next->next->next = buatNode(2);

    struct Node* hasil2 = partisiList(data2, 3);

    printf("Hasil Soal 2:\n");
    tampilList(hasil2);

    return 0;
}