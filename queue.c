
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t capacity;
    size_t front;
    size_t size;
} Queue;

int init_queue(Queue *q, size_t capacity) {
    q->data = malloc(capacity * sizeof(int));

    if (q->data == NULL) {
        return 0;
    }

    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    return 1;
}

int enqueue(Queue *q, int value) {
    if (q->size == q->capacity) {
        size_t new_capacity = q->capacity * 2;

        if (new_capacity < q->capacity ||
            new_capacity > (size_t)-1 / sizeof(int)) {
            return 0;
        }

        int *new_data = malloc(new_capacity * sizeof(int));

        if (new_data == NULL) {
            return 0;
        }

        for (size_t i = 0; i < q->size; i++) {
            new_data[i] =
                q->data[(q->front + i) % q->capacity];
        }

        free(q->data);
        q->data = new_data;
        q->capacity = new_capacity;
        q->front = 0;
    }

    size_t rear = (q->front + q->size) % q->capacity;
    q->data[rear] = value;
    q->size++;

    return 1;
}

int dequeue(Queue *q, int *value) {
    if (q->size == 0) {
        return 0;
    }

    *value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return 1;
}

void print_queue(const Queue *q) {
    printf("Navbat: ");

    for (size_t i = 0; i < q->size; i++) {
        printf("%d ", q->data[(q->front + i) % q->capacity]);
    }

    printf("\nHajmi: %zu, elementlar: %zu\n",
           q->capacity, q->size);
}

int main(void) {
    Queue q;
    size_t capacity;
    int choice, value;

    printf("Boshlangich navbat hajmini kiriting: ");

    if (scanf("%zu", &capacity) != 1 ||
        capacity == 0 ||
        capacity > (size_t)-1 / (2 * sizeof(int))) {
        printf("Hajm noto'g'ri!\n");
        return 1;
    }

    if (!init_queue(&q, capacity)) {
        printf("Xotira ajratilmadi!\n");
        return 1;
    }

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Navbatni ko'rsatish\n");
        printf("0. Chiqish\n");
        printf("Tanlov: ");

        if (scanf("%d", &choice) != 1) {
            printf("Noto'g'ri kiritish!\n");
            break;
        }

        if (choice == 1) {
            printf("Qiymat: ");

            if (scanf("%d", &value) != 1) {
                printf("Noto'g'ri qiymat!\n");
                break;
            }

            if (enqueue(&q, value)) {
                printf("Element qo'shildi.\n");
            } else {
                printf("Xotira ajratilmadi yoki hajm oshib ketdi.\n");
            }
        } else if (choice == 2) {
            if (dequeue(&q, &value)) {
                printf("O'chirilgan element: %d\n", value);
            } else {
                printf("Navbat bo'sh!\n");
            }
        } else if (choice == 3) {
            print_queue(&q);
        } else if (choice != 0) {
            printf("Noto'g'ri tanlov!\n");
        }

    } while (choice != 0);

    free(q.data);
    q.data = NULL;

    printf("Xotira bo'shatildi. Dastur tugadi.\n");
    return 0;
}
