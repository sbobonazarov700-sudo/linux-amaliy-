
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int daraja;
    double *koef;
} Kophad;

int yarat(Kophad *p, int daraja) {
    p->daraja = daraja;
    p->koef = calloc(daraja + 1, sizeof(double));

    if (p->koef == NULL) {
        return 0;
    }

    return 1;
}

void kirit(Kophad *p) {
    for (int i = 0; i <= p->daraja; i++) {
        printf("x^%d koeffitsiyentini kiriting: ", i);
        scanf("%lf", &p->koef[i]);
    }
}

void chiqar(Kophad p) {
    for (int i = p.daraja; i >= 0; i--) {
        printf("%.2lf", p.koef[i]);

        if (i > 0) {
            printf("x^%d", i);
        }

        if (i > 0) {
            printf(" + ");
        }
    }

    printf("\n");
}

Kophad qoshish(Kophad a, Kophad b) {
    int daraja = a.daraja > b.daraja
                 ? a.daraja : b.daraja;

    Kophad natija;

    if (!yarat(&natija, daraja)) {
        natija.koef = NULL;
        return natija;
    }

    for (int i = 0; i <= daraja; i++) {
        double x = i <= a.daraja ? a.koef[i] : 0;
        double y = i <= b.daraja ? b.koef[i] : 0;

        natija.koef[i] = x + y;
    }

    return natija;
}

Kophad kopaytirish(Kophad a, Kophad b) {
    Kophad natija;

    if (!yarat(&natija, a.daraja + b.daraja)) {
        natija.koef = NULL;
        return natija;
    }

    for (int i = 0; i <= a.daraja; i++) {
        for (int j = 0; j <= b.daraja; j++) {
            natija.koef[i + j] +=
                a.koef[i] * b.koef[j];
        }
    }

    return natija;
}

int main(void) {
    Kophad a, b, yigindi, kopaytma;
    int n, m;

    printf("Birinchi kophad darajasini kiriting: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000) {
        printf("Noto'g'ri daraja!\n");
        return 1;
    }

    if (!yarat(&a, n)) {
        printf("Xotira ajratilmadi!\n");
        return 1;
    }

    kirit(&a);

    printf("Ikkinchi kophad darajasini kiriting: ");
    if (scanf("%d", &m) != 1 || m < 0 || m > 1000) {
        printf("Noto'g'ri daraja!\n");
        free(a.koef);
        return 1;
    }

    if (!yarat(&b, m)) {
        printf("Xotira ajratilmadi!\n");
        free(a.koef);
        return 1;
    }

    kirit(&b);

    printf("\nBirinchi kophad: ");
    chiqar(a);

    printf("Ikkinchi kophad: ");
    chiqar(b);

    yigindi = qoshish(a, b);

    if (yigindi.koef == NULL) {
        printf("Yig'indi uchun xotira ajratilmadi!\n");
        free(a.koef);
        free(b.koef);
        return 1;
    }

    printf("Yig'indisi: ");
    chiqar(yigindi);

    kopaytma = kopaytirish(a, b);

    if (kopaytma.koef == NULL) {
        printf("Ko'paytma uchun xotira ajratilmadi!\n");
        free(a.koef);
        free(b.koef);
        free(yigindi.koef);
        return 1;
    }

    printf("Ko'paytmasi: ");
    chiqar(kopaytma);

    free(a.koef);
    free(b.koef);
    free(yigindi.koef);
    free(kopaytma.koef);

    return 0;
}
