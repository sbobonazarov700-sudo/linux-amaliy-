
#include <stdio.h>

double c_to_f(double c) {
    return c * 9.0 / 5.0 + 32;
}

double c_to_k(double c) {
    return c + 273.15;
}

double f_to_c(double f) {
    return (f - 32) * 5.0 / 9.0;
}

double f_to_k(double f) {
    return (f - 32) * 5.0 / 9.0 + 273.15;
}

double k_to_c(double k) {
    return k - 273.15;
}

double k_to_f(double k) {
    return (k - 273.15) * 9.0 / 5.0 + 32;
}

int main(void) {
    double (*f[6])(double) = {
        c_to_f, c_to_k, f_to_c,
        f_to_k, k_to_c, k_to_f
    };

    const char *menu[6] = {
        "Selsiydan Farengeytga (C -> F)",
        "Selsiydan Kelvinga (C -> K)",
        "Farengeytdan Selsiyga (F -> C)",
        "Farengeytdan Kelvinga (F -> K)",
        "Kelvindan Selsiyga (K -> C)",
        "Kelvindan Farengeytga (K -> F)"
    };

    int tanlov;
    double harorat, natija;

    printf("=== Harorat konvertori ===\n");

    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i, menu[i]);
    }

    printf("Tanlovni kiriting (0-5): ");

    if (scanf("%d", &tanlov) != 1 ||
        tanlov < 0 || tanlov > 5) {
        printf("Xato: tanlov 0 dan 5 gacha bo'lishi kerak!\n");
        return 1;
    }

    printf("Haroratni kiriting: ");

    if (scanf("%lf", &harorat) != 1) {
        printf("Xato: harorat noto'g'ri kiritildi!\n");
        return 1;
    }

    /* Mutlaq noldan past haroratni tekshirish */
    if ((tanlov == 0 || tanlov == 1) && harorat < -273.15) {
        printf("Xato: harorat mutlaq noldan past!\n");
        return 1;
    }

    if ((tanlov == 2 || tanlov == 3) && harorat < -459.67) {
        printf("Xato: harorat mutlaq noldan past!\n");
        return 1;
    }

    if ((tanlov == 4 || tanlov == 5) && harorat < 0) {
        printf("Xato: Kelvin 0 dan kichik bo'lishi mumkin emas!\n");
        return 1;
    }

    /* Tanlangan funksiya pointeri orqali hisoblash */
    natija = f[tanlov](harorat);

    printf("Natija: %.2f\n", natija);

    return 0;
}
