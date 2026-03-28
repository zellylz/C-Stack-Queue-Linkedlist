#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 10 // Yýðýt maximum eleman sayýsý (kapasitesi)
int Yigit[BOYUT];
int top = -1;

// Dolu Mu fonksiyonu
int isFull() {
    if (top == BOYUT - 1)
        return 1; // dolu ise 1 (True) döndür
    else
        return 0; // dolu deðilse 0 (False)
}

// Boþ mu fonksiyonu
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Ekleme fonksiyonu
void Push(int x) {
    if (isFull() == 1) { // isFull fonksiyonunu çaðýr
        printf("Yigit dolu, ekleme yapilamaz! \n");
        return;
    }
    top++; // her eklemede top indeksi arttýrýlýr
    Yigit[top] = x;
    printf("%d yigita eklendi.\n", x);
}

// Yýðýttaki tüm deðerleri yazdýran fonksiyon
void Listele() {
    if (isEmpty()) {
        printf("Yigit Bos! \n");
        return;
    }
    printf("\nYýðýt elemanlari (En üstten en alta): ");
    int i;
    for (i = top; i >= 0; i--) { // En üstten baþlayarak yazdýrýyoruz (LIFO)
        printf("%d ", Yigit[i]);
    }
    printf("\n");
}

int main() {
    // Rastgele sayý üretimi için seed ayarla
    srand(time(NULL));

    printf("Rastgele üretilen sayýlar ve yýðýta ekleme iþlemleri:\n");
    // 10 adet rastgele sayý üretip yýðýta ekle
    for (int i = 0; i < 10; i++) {
        int rastgeleSayi = rand() % 100; // 0 ile 99 arasýnda rastgele sayý üret
        Push(rastgeleSayi);
    }

    // Yýðýttaki tüm deðerleri yazdýr
    Listele();

    return 0;
}
