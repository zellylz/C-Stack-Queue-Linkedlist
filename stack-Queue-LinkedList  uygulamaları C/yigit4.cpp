#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Yýðýtýn maksimum alabileceði kitap sayýsý
#define YIGIT_KAPASITE 5
// Kitap adý ve yazarýnýn maksimum karakter sayýsý
#define METIN_UZUNLUGU 50

// Kitap bilgisini tutan yapý (struct)
typedef struct KitapBilgisi {
    char ad[METIN_UZUNLUGU];
    char yazar[METIN_UZUNLUGU];
    int yil;
} Kitap;

// Kitap yýðýtý (dizi ve tepe noktasý)
Kitap kitapYigiti[YIGIT_KAPASITE];
int yigitTepesi = -1; // -1, yýðýtýn boþ olduðunu gösterir

// Yýðýt dolu mu kontrol eder
int yigitDoluMu() {
    return yigitTepesi == YIGIT_KAPASITE - 1;
}

// Yýðýt boþ mu kontrol eder
int yigitBosMu() {
    return yigitTepesi == -1;
}

// Yýðýta kitap ekler
void kitapEkle() {
    if (yigitDoluMu()) {
        printf("Yýðýt dolu! Yeni kitap eklenemiyor.\n");
        return;
    }

    Kitap yeniKitap;

    printf("Kitap Adý: ");
    scanf(" %[^\n]", yeniKitap.ad); // Boþluk içeren girdiyi okur
    printf("Kitap Yazarý: ");
    scanf(" %[^\n]", yeniKitap.yazar);
    printf("Kitap Yýlý: ");
    scanf("%d", &yeniKitap.yil);

    yigitTepesi++;
    kitapYigiti[yigitTepesi] = yeniKitap;

    printf("'%s' adlý kitap yýðýta eklendi.\n", yeniKitap.ad);
}

// Yýðýttan kitap çýkarýr
void kitapCikar() {
    if (yigitBosMu()) {
        printf("Yýðýt boþ! Çýkarýlacak kitap yok.\n");
        return;
    }

    printf("'%s' adlý kitap yýðýttan çýkarýldý.\n", kitapYigiti[yigitTepesi].ad);
    yigitTepesi--;
}

// Yýðýttaki kitaplarý listeler
void kitaplariListele() {
    if (yigitBosMu()) {
        printf("Yýðýtta hiç kitap yok.\n");
        return;
    }

    printf("\n--- Yýðýttaki Kitaplar (En üstten alta) ---\n");
    for (int i = yigitTepesi; i >= 0; i--) {
        printf("Kitap Adý: %s\n", kitapYigiti[i].ad);
        printf("Yazarý: %s\n", kitapYigiti[i].yazar);
        printf("Yýlý: %d\n", kitapYigiti[i].yil);
        printf("---------------------------------------\n");
    }
}

// Yýðýtýn en üstündeki kitabý gösterir
void enUsttekiKitabiGoster() {
    if (!yigitBosMu()) {
        printf("\n--- En Üstteki Kitap ---\n");
        printf("Kitap Adý: %s\n", kitapYigiti[yigitTepesi].ad);
        printf("Yazarý: %s\n", kitapYigiti[yigitTepesi].yazar);
        printf("Yýlý: %d\n", kitapYigiti[yigitTepesi].yil);
        printf("-------------------------\n");
    } else {
        printf("Yýðýt boþ, en üstte kitap yok!\n");
    }
}

// Yýðýttaki toplam kitap sayýsýný gösterir
void toplamKitapSayisiniGoster() {
    printf("Yýðýttaki toplam kitap sayýsý: %d\n", yigitTepesi + 1);
}

int main() {
    int secim;

    do {
        printf("\n--- Kitap Yýðýtý Menüsü ---\n");
        printf("1. Kitap Ekle\n");
        printf("2. Kitap Çýkar\n");
        printf("3. Kitaplarý Listele\n");
        printf("4. En Üstteki Kitabý Göster\n");
        printf("5. Toplam Kitap Sayýsýný Göster\n");
        printf("6. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);
        getchar(); // Önceki scanf'ten kalan newline karakterini temizle

        switch (secim) {
            case 1:
                kitapEkle();
                break;
            case 2:
                kitapCikar();
                break;
            case 3:
                kitaplariListele();
                break;
            case 4:
                enUsttekiKitabiGoster();
                break;
            case 5:
                toplamKitapSayisiniGoster();
                break;
            case 6:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    } while (secim != 6);

    return 0;
} 
