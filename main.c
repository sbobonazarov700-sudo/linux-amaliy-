
#include <stdio.h>

int main() {
    long long n, teskari = 0;
    int raqam, yigindi = 0, soni = 0;

    scanf("%lld", &n);

    long long a = n;

    if (a < 0) {
        a = -a;
    }

    if (a == 0) {
        soni = 1;
    }

    while (a > 0) {
        raqam = a % 10;
        yigindi += raqam;
        soni++;
        teskari = teskari * 10 + raqam;
        a /= 10;
    }

    if (n < 0) {
        teskari = -teskari;
    }

    printf("Raqamlar yig'indisi: %d\n", yigindi);
    printf("Raqamlar soni: %d\n", soni);
    printf("Teskari son: %lld\n", teskari);

    return 0;
}
