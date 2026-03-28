#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOYUT 100 // Yýðýt maximum eleman sayýsý (kelime uzunluðuna göre ayarlanabilir)
char Yigit[BOYUT];
int top = -1;

// Dolu Mu fonksiyonu
int isFull() {
    if (top == BOYUT - 1)
        return 1;
    else
        return 0;
}

// Boþ mu fonksiyonu
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Ekleme fonksiyonu (Push)
void Push(char x) {
    if (isFull() == 1) {
        printf("Yigit dolu, karakter eklenemez! '%c'\n", x);
        return;
    }
    top++;
    Yigit[top] = x;
}

// Çýkarma fonksiyonu (Pop)
char Pop() {
    if (isEmpty()) {
        printf("Yigit Bos, karakter cikarilamaz!\n");
        return '\0'; // Null karakter (geçersiz deðer)
    }
    char x = Yigit[top];
    top--;
    return x;
}

int main() {
    char kelime[BOYUT];
    char tersKelime[BOYUT];
    int uzunluk;
    int palindrom = 1; // 1: true, 0: false

    printf("Bir kelime giriniz: ");
    scanf("%s", kelime);

    uzunluk = strlen(kelime);

    // Kelimenin karakterlerini yýðýta ekle (Push)
    for (int i = 0; i < uzunluk; i++) {
        Push(kelime[i]);
    }

    // Yýðýttaki karakterleri çekerek tersten kelimeyi oluþtur
    for (int i = 0; i < uzunluk; i++) {
        tersKelime[i] = Pop();
    }
    tersKelime[uzunluk] = '\0'; // String sonlandýrýcýsýný ekle

    printf("Girilen kelime: %s\n", kelime);
    printf("Kelimenin tersi: %s\n", tersKelime);

    // Orijinal kelime ile ters kelimeyi karþýlaþtýr
    for (int i = 0; i < uzunluk; i++) {
        if (kelime[i] != tersKelime[i]) {
            palindrom = 0; // false
            break;
        }
    }

    if (palindrom == 1) {
        printf("Girilen kelime bir palindromdur.\n");
    } else {
        printf("Girilen kelime bir palindrom deðildir.\n");
    }

    return 0;
}
