#include <stdio.h>
#include <stdlib.h>

// Müþteri hesap bilgilerini tutan yapý
struct MusteriHesap {
    char ad[50];
    double bakiye;
};

// Bankadaki müþterilerin adýný ve bakiyesini listeleyen fonksiyon
void HesapListele(struct MusteriHesap *musteriler, int musteriSayisi) {
    printf("\n--- Müþteri Hesap Listesi ---\n");
    for (int i = 0; i < musteriSayisi; i++) {
        printf("%d. Müþteri Adý: %s, Bakiyesi: %.2f TL\n", i + 1, musteriler[i].ad, musteriler[i].bakiye);
    }
}

int main() {
    int musteriSayisi;

    printf("Kaç adet müþteri oluþturmak istiyorsunuz: ");
    scanf("%d", &musteriSayisi);

    // Müþteri hesaplarý için dinamik dizi oluþtur
    struct MusteriHesap *musteriler = (struct MusteriHesap *)malloc(musteriSayisi * sizeof(struct MusteriHesap));

    if (musteriler == NULL) {
        fprintf(stderr, "Bellek ayrýlamadý!\n");
        return 1;
    }

    // Her müþteri için bilgi al
    for (int i = 0; i < musteriSayisi; i++) {
        printf("\n%d. Müþterinin Adýný Giriniz: ", i + 1);
        scanf("%s", musteriler[i].ad);

        printf("%d. Müþterinin Bakiyesini Giriniz: ", i + 1);
        scanf("%lf", &musteriler[i].bakiye);
    }

    // Müþteri hesaplarýný listele
    HesapListele(musteriler, musteriSayisi);

    // Tüm müþterilerin toplam bakiyesini hesapla
    double toplamBakiye = 0;
    for (int i = 0; i < musteriSayisi; i++) {
        toplamBakiye += musteriler[i].bakiye;
    }

    printf("\nTüm Müþterilerin Toplam Bakiyesi: %.2f TL\n", toplamBakiye);

    // Belleði serbest býrak
    free(musteriler);

    return 0;
}
