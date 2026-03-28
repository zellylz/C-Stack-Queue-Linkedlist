#include <stdio.h>
#include <stdlib.h>

#define BOYUT 100 // Kuyruk maximum eleman sayýsý (kapasitesi)
int Kuyruk[BOYUT];
int ilk = -1, son = -1; // front, rear

int DoluMu() {
    if (son == BOYUT - 1)
        return 1;
    return 0;
}

int BosMu() {
    if (ilk == -1)
        return 1;
    return 0;
}

void Enqueue(int x) {
    if (DoluMu() == 1) {
        printf("Kuyruk dolu, eleman eklenemez!\n");
        return;
    }
    if (ilk == -1) {
        ilk = 0;
    }
    son++;
    Kuyruk[son] = x;
    printf("%d kuyruða eklendi.\n", x);
}

int main() {
    int sayi;
    printf("Kuyruða eklemek istediðiniz sayýlarý girin (çýkmak için -1):\n");

    while (1) {
        scanf("%d", &sayi);
        if (sayi == -1) {
            break;
        }
        Enqueue(sayi);
    }

    int toplam = 0;
    int enBuyuk = -2147483648; // Integer'ýn alabileceði en küçük deðer

    if (!BosMu()) {
        printf("\nKuyruktaki sayýlar: ");
        for (int i = ilk; i <= son; i++) {
            printf("%d ", Kuyruk[i]);
            toplam += Kuyruk[i];
            if (Kuyruk[i] > enBuyuk) {
                enBuyuk = Kuyruk[i];
            }
        }
        printf("\nKuyruktaki sayýlarýn toplamý: %d\n", toplam);
        printf("Kuyruktaki en büyük sayý: %d\n", enBuyuk);
    } else {
        printf("\nKuyruk boþ.\n");
    }

    return 0;
}
