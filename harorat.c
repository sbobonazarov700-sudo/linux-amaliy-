
#include <stdio.h>

int main() {
    int tanlov;
    double harorat, selsiy, farengeyt, kelvin;

    printf("=== Harorat konvertori ===\n");
    printf("1. Selsiydan Farengeytga\n");
    printf("2. Selsiydan Kelvinga\n");
    printf("3. Farengeytdan Selsiyga\n");
    printf("4. Farengeytdan Kelvinga\n");
    printf("5. Kelvindan Selsiyga\n");
    printf("6. Kelvindan Farengeytga\n");
    printf("Tanlovingizni kiriting: ");

    if (scanf("%d", &tanlov) != 1) {
        printf("Xato: noto'g'ri kiritish!\n");
        return 1;
    }

    printf("Haroratni kiriting: ");

    if (scanf("%lf", &harorat) != 1) {
        printf("Xato: harorat noto'g'ri kiritildi!\n");
        return 1;
    }

    switch (tanlov) {
        case 1:
            if (harorat < -273.15) {
                printf("Xato: mutlaq noldan past harorat!\n");
            } else {
                farengeyt = harorat * 9.0 / 5.0 + 32;
                printf("Farengeyt: %.2f F\n", farengeyt);
            }
            break;

        case 2:
            if (harorat < -273.15) {
                printf("Xato: mutlaq noldan past harorat!\n");
            } else {
                kelvin = harorat + 273.15;
                printf("Kelvin: %.2f K\n", kelvin);
            }
            break;

        case 3:
            if (harorat < -459.67) {
                printf("Xato: mutlaq noldan past harorat!\n");
            } else {
                selsiy = (harorat - 32) * 5.0 / 9.0;
                printf("Selsiy: %.2f C\n", selsiy);
            }
            break;

        case 4:
            if (harorat < -459.67) {
                printf("Xato: mutlaq noldan past harorat!\n");
            } else {
                kelvin = (harorat - 32) * 5.0 / 9.0 + 273.15;
                printf("Kelvin: %.2f K\n", kelvin);
            }
            break;

        case 5:
            if (harorat < 0) {
                printf("Xato: Kelvin 0 dan kichik bo'lishi mumkin emas!\n");
            } else {
                selsiy = harorat - 273.15;
                printf("Selsiy: %.2f C\n", selsiy);
            }
            break;

        case 6:
            if (harorat < 0) {
                printf("Xato: Kelvin 0 dan kichik bo'lishi mumkin emas!\n");
            } else {
                farengeyt = (harorat - 273.15) * 9.0 / 5.0 + 32;
                printf("Farengeyt: %.2f F\n", farengeyt);
            }
            break;

        default:
            printf("Xato: menyudan 1 dan 6 gacha tanlang!\n");
    }

    return 0;
}
