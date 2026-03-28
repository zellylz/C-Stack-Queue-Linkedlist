#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOYUT 100 // Ýfade uzunluðu için yeterli bir boyut

char Yigit[BOYUT];
int top = -1;

// Dolu Mu fonksiyonu (Karakter yýðýtý için uygun hale getirildi)
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

// Ekleme fonksiyonu (Push - char tipinde)
void Push(char x) {
    if (isFull() == 1) {
        printf("Yigit dolu, karakter eklenemez! '%c'\n", x);
        return;
    }
    top++;
    Yigit[top] = x;
}

// Çýkarma fonksiyonu (Pop - char tipinde)
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
    char ifade[BOYUT];
    bool hataVar = false;

    printf("Aritmetiksel bir ifade giriniz: ");
    scanf("%s", ifade);

    int uzunluk = strlen(ifade);

    // Ýfadeyi karakter karakter tara
    for (int i = 0; i < uzunluk; i++) {
        if (ifade[i] == '(') {
            Push('('); // Açma parantezini yýðýta ekle
        } else if (ifade[i] == ')') {
            if (!isEmpty()) {
                Pop(); // Kapama parantezi geldiðinde yýðýttan bir açma parantezi çek
            } else {
                hataVar = true; // Karþýlýðý olmayan kapama parantezi
                break;
            }
        }
    }

    // Kontroller
    if (hataVar) {
        printf("Parantez hatasi var: Karsiligi olmayan kapama parantezi.\n");
    } else if (!isEmpty()) {
        printf("Parantez hatasi var: Karsiligi olmayan acma parantezi.\n");
    } else {
        printf("Parantez hatasi yok.\n");
    }

    return 0;
}
