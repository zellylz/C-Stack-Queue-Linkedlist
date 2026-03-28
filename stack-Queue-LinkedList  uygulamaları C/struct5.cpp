#include <stdio.h>
#include <stdlib.h>

// Zaman bilgilerini tutan struct
struct Zaman {
    int saat;
    int dakika;
    int saniye;
};

// Ýki zaman arasýndaki farký hesaplayan fonksiyon
struct Zaman ZamanFarkiHesaplaKolay(struct Zaman zaman1, struct Zaman zaman2) {
    struct Zaman fark;
    int toplamSaniye1, toplamSaniye2, farkToplamSaniye;

    // Ýlk zamaný toplam saniyeye çevir
    toplamSaniye1 = zaman1.saat * 3600 + zaman1.dakika * 60 + zaman1.saniye;

    // Ýkinci zamaný toplam saniyeye çevir
    toplamSaniye2 = zaman2.saat * 3600 + zaman2.dakika * 60 + zaman2.saniye;

    // Farkýn mutlak deðerini al (hangi zamanýn daha önce olduðu önemli deðil)
    farkToplamSaniye = abs(toplamSaniye1 - toplamSaniye2);

    // Farký tekrar saat, dakika, saniyeye çevir
    fark.saat = farkToplamSaniye / 3600;        // Tam saatler
    fark.dakika = (farkToplamSaniye % 3600) / 60; // Kalan saniyeden dakikalar
    fark.saniye = farkToplamSaniye % 60;         // Kalan saniyeler

    return fark;
}

int main() {
    struct Zaman ilkZaman, ikinciZaman, zamanFarki;

    printf("Ýlk Zamaný Giriniz (saat dakika saniye): ");
    scanf("%d %d %d", &ilkZaman.saat, &ilkZaman.dakika, &ilkZaman.saniye);

    printf("Ýkinci Zamaný Giriniz (saat dakika saniye): ");
    scanf("%d %d %d", &ikinciZaman.saat, &ikinciZaman.dakika, &ikinciZaman.saniye);

    zamanFarki = ZamanFarkiHesaplaKolay(ilkZaman, ikinciZaman);

    printf("\nZaman Farký: %d saat, %d dakika, %d saniye\n", zamanFarki.saat, zamanFarki.dakika, zamanFarki.saniye);

    return 0;
}
