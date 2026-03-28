#include <stdio.h>

// Karmaþýk sayýlarý temsil eden yapý tanýmý
struct KarmasikSayi {
    float gercek;     // Gerçek kýsým
    float sanal;      // Sanal kýsým
};

// Ýki karmaþýk sayýyý toplayan fonksiyon
struct KarmasikSayi KarmasikSayiTopla(struct KarmasikSayi sayi1, struct KarmasikSayi sayi2) {
    struct KarmasikSayi toplam;
    toplam.gercek = sayi1.gercek + sayi2.gercek;
    toplam.sanal = sayi1.sanal + sayi2.sanal;
    return toplam;
}

int main() {
    struct KarmasikSayi karmasik1, karmasik2, sonuc;

    // Birinci karmaþýk sayýnýn deðerlerini kullanýcýdan al
    printf("Birinci karmaþýk sayýnýn gerçek kýsmýný giriniz: ");
    scanf("%f", &karmasik1.gercek);
    printf("Birinci karmaþýk sayýnýn sanal kýsmýný giriniz: ");
    scanf("%f", &karmasik1.sanal);

    // Ýkinci karmaþýk sayýnýn deðerlerini kullanýcýdan al
    printf("\nÝkinci karmaþýk sayýnýn gerçek kýsmýný giriniz: ");
    scanf("%f", &karmasik2.gercek);
    printf("Ýkinci karmaþýk sayýnýn sanal kýsmýný giriniz: ");
    scanf("%f", &karmasik2.sanal);

    // Karmaþýk sayýlarý topla
    sonuc = KarmasikSayiTopla(karmasik1, karmasik2);

    // Toplam sonucunu ekrana yazdýr
    printf("\nToplam: %.2f + %.2fi\n", sonuc.gercek, sonuc.sanal);

    return 0;
}
