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

    printf("Bir kelime giriniz: ");
    scanf("%s", kelime);

    int uzunluk = strlen(kelime);

    // Kelimenin karakterlerini yýðýta ekle (Push)
    for (int i = 0; i < uzunluk; i++) {
        Push(kelime[i]);
    }

    printf("Kelimenin tersten yazýlýþý: ");

    // Yýðýttaki karakterleri çekerek (Pop) ekrana yazdýr
    while (!isEmpty()) {
        printf("%c", Pop());
    }
    printf("\n");

    return 0;
}
