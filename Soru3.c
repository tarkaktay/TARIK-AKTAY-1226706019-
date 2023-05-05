#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void yaz(struct node* head) {
    while (head != NULL) {
        printf("%d,", head->data);
        head = head->next;
    }
}

void VeriEkle(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct node* BirlesmisListe(struct node* list1, struct node* list2) {
    struct node* list3 = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            VeriEkle(&list3, list1->data);
            list1 = list1->next;
        }
        else {
            VeriEkle(&list3, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        VeriEkle(&list3, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        VeriEkle(&list3, list2->data);
        list2 = list2->next;
    }

    return list3;
}

int main() {
    struct node* list1 = NULL;
    VeriEkle(&list1, 1);
    VeriEkle(&list1, 3);
    VeriEkle(&list1, 4);
    VeriEkle(&list1, 5);

    struct node* list2 = NULL;
    VeriEkle(&list2, 2);
    VeriEkle(&list2, 4);
    VeriEkle(&list2, 6);
    VeriEkle(&list2, 8);

    printf("List 1: ");
    yaz(list1);
    printf("\nList 2: ");
    yaz(list2);

    struct node* list3 = BirlesmisListe(list1, list2);

    printf("\nList3: ");
    yaz(list3);

    return 0;
}
