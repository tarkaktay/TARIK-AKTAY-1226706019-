#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


struct Queue {
    char data[MAX_SIZE];
    int front, rear;
};


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}


void enqueue(struct Queue* q, char c) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Kuyruk dolu!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = c;
    if (q->front == -1) {
        q->front = 0;
    }
}


char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Kuyruk boþ!\n");
        return '\0';
    }
    char c = q->data[q->front];
    q->front++;
    return c;
}


void removeDuplicates(char* str) {
    int n = strlen(str);
    struct Queue* q = createQueue();
    int i = 0;
    while (i < n) {
        
        if (isEmpty(q) || str[i] != q->data[q->rear]) {
            enqueue(q, str[i]);
            i++;
        }
        else {
            
            while (i < n && str[i] == q->data[q->rear]) {
                i++;
            }
            q->rear--;
        }
    }

    i = q->front;
    while (i <= q->rear) {
        str[i - q->front] = q->data[i];
        i++;
    }
    str[i - q->front] = '\0';
    free(q);
}


int main() {
    char str[MAX_SIZE];
    printf("Dizi girin: ");
    scanf("%s", str);
    removeDuplicates(str);
    printf("Sonuç: %s\n", str);
    return 0;
}
