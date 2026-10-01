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

/* Fungsi nomor 9 */
struct Node* reverseAntara(
    struct Node* head,
    int kiri,
    int kanan
) {

    if (head == NULL || kiri == kanan) {
        return head;
    }

    struct Node dummy;

    dummy.next = head;

    struct Node* sebelum = &dummy;

    /* Menuju posisi kiri */
    for (int i = 1; i < kiri; i++) {
        sebelum = sebelum->next;
    }

    /* Membalik bagian list */
    struct Node* sekarang = sebelum->next;

    for (int i = 0; i < kanan - kiri; i++) {

        struct Node* pindah = sekarang->next;

        sekarang->next = pindah->next;

        pindah->next = sebelum->next;

        sebelum->next = pindah;
    }

    return dummy.next;
}

/* Main */
int main() {

    struct Node* head = NULL;

    tambahBelakang(&head, 1);
    tambahBelakang(&head, 5);
    tambahBelakang(&head, 3);
    tambahBelakang(&head, 7);
    tambahBelakang(&head, 5);

    printf("Input  : ");
    tampilkanList(head);

    head = reverseAntara(head, 2, 4);

    printf("Output : ");
    tampilkanList(head);

    return 0;
}