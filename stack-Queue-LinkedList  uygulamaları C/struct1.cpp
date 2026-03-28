#include <stdio.h>

// Dikdörtgenin kenar bilgilerini tutan struct tanýmý
struct Dikdortgen {
    int uzunKenar;
    int kisaKenar;
};

// Dikdörtgenin alanýný hesaplayan fonksiyon
int alanHesapla(struct Dikdortgen d) {
    return d.uzunKenar * d.kisaKenar;
}

// Dikdörtgenin çevresini hesaplayan fonksiyon
int cevreHesapla(struct Dikdortgen d) {
    return 2 * (d.uzunKenar + d.kisaKenar);
}

int main() {
    struct Dikdortgen benimDikdortgen;

    // Kullanýcýdan kenar deðerlerini al
    printf("Dikdortgenin uzun kenarini giriniz: ");
    scanf("%d", &benimDikdortgen.uzunKenar);

    printf("Dikdortgenin kisa kenarini giriniz: ");
    scanf("%d", &benimDikdortgen.kisaKenar);

    // Alaný hesapla ve ekrana yazdýr
    int alan = alanHesapla(benimDikdortgen);
    printf("Dikdortgenin alani: %d\n", alan);

    // Çevreyi hesapla ve ekrana yazdýr
    int cevre = cevreHesapla(benimDikdortgen);
    printf("Dikdortgenin cevresi: %d\n", cevre);

    return 0;
}
