
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, temp;

    printf("Massiv elementlari sonini kiriting: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Noto'g'ri son!\n");
        return 1;
    }

    int *p = malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Xotira ajratilmadi!\n");
        return 1;
    }

    printf("Massiv elementlarini kiriting:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }

    int *chap = p;
    int *ong = p + n - 1;

    while (chap < ong) {
        temp = *chap;
        *chap = *ong;
        *ong = temp;

        chap++;
        ong--;
    }

    printf("Teskari massiv:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }

    printf("\n");

    free(p);

    return 0;
}
