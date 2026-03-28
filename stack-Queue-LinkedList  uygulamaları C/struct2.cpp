#include <stdio.h>

// Öðrenci bilgilerini tutan struct tanýmý
struct Ogrenci {
    int ogrenciNo;
    int vizeNotu;
    int finalNotu;
    float ortalama;
};

// Öðrencilerin notlarýný hesaplayan ve sýnýf ortalamasýný bulan fonksiyon
void NotHesapla(struct Ogrenci ogrenciler[], int size) {
    float genelOrtalamaToplam = 0;
    printf("\n--- Öðrenci Notlarý ve Ortalamalarý ---\n");
    for (int i = 0; i < size; i++) {
        ogrenciler[i].ortalama = (ogrenciler[i].vizeNotu * 0.4) + (ogrenciler[i].finalNotu * 0.6);
        printf("Öðrenci No: %d, Ortalama: %.2f\n", ogrenciler[i].ogrenciNo, ogrenciler[i].ortalama);
        genelOrtalamaToplam += ogrenciler[i].ortalama;
    }

    float genelOrtalama = genelOrtalamaToplam / size;
    printf("\nSýnýfýn Genel Not Ortalamasý: %.2f\n", genelOrtalama);
}

int main() {
    struct Ogrenci sinif[10];
    int ogrenciSayisi = 10;

    printf("--- Öðrenci Bilgilerini Giriniz ---\n");
    for (int i = 0; i < ogrenciSayisi; i++) {
        printf("%d. Öðrencinin Numarasýný Giriniz: ", i + 1);
        scanf("%d", &sinif[i].ogrenciNo);

        printf("%d. Öðrencinin Vize Notunu Giriniz: ", i + 1);
        scanf("%d", &sinif[i].vizeNotu);

        printf("%d. Öðrencinin Final Notunu Giriniz: ", i + 1);
        scanf("%d", &sinif[i].finalNotu);
        printf("\n");
    }

    // Notlarý hesaplamak ve yazdýrmak için NotHesapla fonksiyonunu çaðýr
    NotHesapla(sinif, ogrenciSayisi);

    return 0;
}
