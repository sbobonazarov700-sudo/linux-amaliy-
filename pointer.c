
#include <stdio.h>

void almashtir(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int N, a[100];

    printf("N ni kiriting (1-100): ");
    scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("N noto'g'ri kiritildi!\n");
        return 1;
    }

    printf("%d ta element kiriting:\n", N);

    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (*(a + j) > *(a + j + 1)) {
                almashtir(a + j, a + j + 1);
            }
        }
    }

    printf("Saralangan massiv: ");

    for (int i = 0; i < N; i++) {
        printf("%d ", *(a + i));
    }

    printf("\n");

    return 0;
}
