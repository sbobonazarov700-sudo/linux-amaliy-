
#include <stdio.h>

void raqamlar(int n, int *yig, int *soni) {
    int a = n;

    *yig = 0;
    *soni = 0;

    if (a < 0)
        a = -a;

    if (a == 0)
        *soni = 1;

    while (a > 0) {
        *yig += a % 10;
        (*soni)++;
        a /= 10;
    }
}

int main() {
    int n, yig, soni;

    printf("Son kiriting: ");
    scanf("%d", &n);

    raqamlar(n, &yig, &soni);

    printf("Raqamlar yig'indisi: %d\n", yig);
    printf("Raqamlar soni: %d\n", soni);

    return 0;
}
