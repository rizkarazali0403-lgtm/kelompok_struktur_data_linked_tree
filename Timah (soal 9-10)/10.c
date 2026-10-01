#include <stdio.h>
#include <stdlib.h>

/* Definisi Node */
struct Node {
    int nilai;
    struct Node *next;
};

/* Membuat Node */
struct Node* buatNode(int nilai) {

    struct Node* baru = malloc(sizeof(struct Node));

    baru->nilai = nilai;
    baru->next = NULL;

    return baru;
}

/* Menambahkan Node */
void tambahBelakang(struct Node** head, int nilai) {

    struct Node* baru = buatNode(nilai);

    if (*head == NULL) {
        *head = baru;
        return;
    }

    struct Node* bantu = *head;

    while (bantu->next != NULL) {
        bantu = bantu->next;
    }

    bantu->next = baru;
}

/* Menampilkan list */
void tampilkanList(struct Node* head) {

    printf("[");

    while (head != NULL) {

        printf("%d", head->nilai);

        if (head->next != NULL) {
            printf(", ");
        }

        head = head->next;
    }

    printf("]\n");
}

/* Mengecek apakah nilai ada di array */
int adaDiArray(
    int nilai,
    int* num,
    int numSize
) {

    for (int i = 0; i < numSize; i++) {

        if (num[i] == nilai) {
            return 1;
        }
    }

    return 0;
}

/* Fungsi nomor 10 */
struct Node* modifiedList(
    int* num,
    int numSize,
    struct Node* head
) {

    /* Menghapus Node dari awal */
    while (
        head != NULL &&
        adaDiArray(
            head->nilai,
            num,
            numSize
        )
    ) {

        struct Node* hapus = head;

        head = head->next;

        free(hapus);
    }

    if (head == NULL) {
        return NULL;
    }

    /* Menghapus Node berikutnya */
    struct Node* bantu = head;

    while (bantu->next != NULL) {

        if (
            adaDiArray(
                bantu->next->nilai,
                num,
                numSize
            )
        ) {

            struct Node* hapus = bantu->next;

            bantu->next = hapus->next;

            free(hapus);

        } else {

            bantu = bantu->next;
        }
    }

    return head;
}

/* Main */
int main() {

    struct Node* head = NULL;

    tambahBelakang(&head, 1);
    tambahBelakang(&head, 2);
    tambahBelakang(&head, 3);
    tambahBelakang(&head, 4);
    tambahBelakang(&head, 5);

    int num[] = {1, 2, 3};

    printf("Input  : ");
    tampilkanList(head);

    head = modifiedList(
        num,
        3,
        head
    );

    printf("Output : ");
    tampilkanList(head);

    return 0;
}