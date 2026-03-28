#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AD_UZUNLUK 50
#define PERSONEL_SAYISI 5
#define GUNCEL_YIL 2025 // Þu anki yýlý sabit olarak tanýmlýyoruz

// Doðum tarihi bilgisini tutan struct
struct DogumTarihi {
    int yil;
    int ay;
    int gun;
};

// Personel bilgisini tutan struct (içinde DogumTarihi struct'ý var)
struct Personel {
    char adSoyad[AD_UZUNLUK];
    double maas;
    struct DogumTarihi dogumTarihi;
    int yas; // Yaþý hesaplayýp saklayacaðýz
};

// Yaþý hesaplayan basit düzey fonksiyon (mevcut yýlý sabit kabul eder)
int basitYasHesapla(int dogumYili) {
    return GUNCEL_YIL - dogumYili;
}

int main() {
    struct Personel personeller[PERSONEL_SAYISI];

    // Personel bilgilerini al
    printf("--- Personel Bilgilerini Girin ---\n");
    for (int i = 0; i < PERSONEL_SAYISI; i++) {
        printf("\n%d. Personel:\n", i + 1);
        printf("Ad Soyad: ");
        scanf(" %[^\n]", personeller[i].adSoyad);
        printf("Maaþý: ");
        scanf("%lf", &personeller[i].maas);
        printf("Doðum Yýlý: ");
        scanf("%d", &personeller[i].dogumTarihi.yil);
        printf("Doðum Ayý (1-12): ");
        scanf("%d", &personeller[i].dogumTarihi.ay);
        printf("Doðum Günü (1-31): ");
        scanf("%d", &personeller[i].dogumTarihi.gun);

        // Yaþý basit düzeyde hesapla ve struct'a kaydet
        personeller[i].yas = basitYasHesapla(personeller[i].dogumTarihi.yil);
    }

    // Yaþý 25-40 arasý olan personelleri listele
    printf("\n--- Yaþý 25-40 Arasý Olan Personeller ---\n");
    int bulunanPersonel = 0;
    for (int i = 0; i < PERSONEL_SAYISI; i++) {
        if (personeller[i].yas >= 25 && personeller[i].yas <= 40) {
            printf("Ad Soyad: %s\n", personeller[i].adSoyad);
            printf("Maaþý: %.2f TL\n", personeller[i].maas);
            printf("Yaþý: %d\n", personeller[i].yas);
            printf("-------------------------\n");
            bulunanPersonel++;
        }
    }

    if (bulunanPersonel == 0) {
        printf("Yaþý 25-40 arasýnda olan personel bulunmamaktadýr.\n");
    }

    return 0;
}
