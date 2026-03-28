#include <stdio.h>
#include <stdlib.h>

// Tarih bilgilerini tutan struct
struct Tarih {
    int gun;
    int ay;
    int yil;
};

// Yaþý gün, ay, yýl olarak hesaplayan fonksiyon
struct Tarih YasHesapla(struct Tarih dogum, struct Tarih bugun) {
    struct Tarih yas;
    yas.yil = bugun.yil - dogum.yil;
    yas.ay = bugun.ay - dogum.ay;
    yas.gun = bugun.gun - dogum.gun;

    // Ay ve gün düzeltmeleri
    if (yas.gun < 0) {
        yas.ay--;
        // Bir önceki ayýn gün sayýsýný bulma (basit bir yaklaþýmla)
        int oncekiAyGunSayisi = 30; // Ortalama bir deðer alýyoruz, gerçekte daha karmaþýk
        if (dogum.ay == 1 || dogum.ay == 3 || dogum.ay == 5 || dogum.ay == 7 || dogum.ay == 8 || dogum.ay == 10 || dogum.ay == 12) {
            oncekiAyGunSayisi = 31;
        } else if (dogum.ay == 2) {
            // Basitçe artýk yýl kontrolü yapmýyoruz, 28 veya 29 alabiliriz
            oncekiAyGunSayisi = 28;
        }
        yas.gun += oncekiAyGunSayisi;
    }

    if (yas.ay < 0) {
        yas.yil--;
        yas.ay += 12;
    }

    return yas;
}

int main() {
    struct Tarih dogumTarihi, bugunTarihi, kullaniciYasi;

    printf("Doðum Tarihinizi Giriniz (gün ay yýl): ");
    scanf("%d %d %d", &dogumTarihi.gun, &dogumTarihi.ay, &dogumTarihi.yil);

    printf("Þimdiki Tarihi Giriniz (gün ay yýl): ");
    scanf("%d %d %d", &bugunTarihi.gun, &bugunTarihi.ay, &bugunTarihi.yil);

    kullaniciYasi = YasHesapla(dogumTarihi, bugunTarihi);

    printf("\nYaþýnýz: %d yýl, %d ay, %d gün\n", kullaniciYasi.yil, kullaniciYasi.ay, kullaniciYasi.gun);

    return 0;
 }
