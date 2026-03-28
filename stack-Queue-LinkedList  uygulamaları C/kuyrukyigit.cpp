#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sabitler
#define YIGIT_BOYUTU 10
#define KUYRUK_BOYUTU 10

// Yýðýt Veri Yapýsý
int Yigit[YIGIT_BOYUTU];
int top = -1;

int isFull() {
    return top == YIGIT_BOYUTU - 1;
}

int isEmpty() {
    return top == -1;
}

void Push(int x) {
    if (isFull()) {
        printf("Yigit dolu, ekleme yapilamaz! (%d)\n", x);
        return;
    }
    Yigit[++top] = x;
    printf("Yigita eklendi: %d\n", x);
}

int Pop() {
    if (isEmpty()) {
        printf("Yigit bos, cikarma yapilamaz!\n");
        return -1;
    }
    int x = Yigit[top--];
    printf("%d cikarildi.\n", x);
    return x;
}

void YigitListele() {
    if (isEmpty()) {
        printf("Yigit bos.\n");
        return;
    }
    printf("Yigit elemanlari (En ustten alta): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", Yigit[i]);
    }
    printf("\n");
}

// Kuyruk Veri Yapýsý
int Kuyruk[KUYRUK_BOYUTU];
int ilk = -1, son = -1;

int KuyrukDoluMu() {
    return son == KUYRUK_BOYUTU - 1;
}

int KuyrukBosMu() {
    return ilk == -1;
}

void Enqueue(int x) {
    if (KuyrukDoluMu()) {
        printf("Kuyruk dolu, ekleme yapilamaz! (%d)\n", x);
        return;
    }
    if (ilk == -1) {
        ilk = 0;
    }
    Kuyruk[++son] = x;
    printf("Kuyruga eklendi: %d\n", x);
}

void KuyrukListele() {
    if (KuyrukBosMu()) {
        printf("Kuyruk bos.\n");
        return;
    }
    printf("Kuyruk elemanlari (Onden arkaya): ");
    for (int i = ilk; i <= son; i++) {
        printf("%d ", Kuyruk[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    printf("--- Yigita Rastgele Sayilar Ekleniyor ---\n");
    for (int i = 0; i < YIGIT_BOYUTU; i++) {
        Push(rand() % 100);
    }
    printf("\n--- Yigitin Ilk Hali ---\n");
    YigitListele();

    int n;
    printf("\nYigittan kac adet sayi cekilip kuyruga eklenecek (0-%d): ", YIGIT_BOYUTU);
    scanf("%d", &n);

    if (n < 0 || n > YIGIT_BOYUTU) {
        printf("Gecersiz sayi adedi!\n");
        return 1;
    }

    printf("\n--- Yigittan Cekilip Kuyruga Eklenen Sayilar ---\n");
    for (int i = 0; i < n; i++) {
        int cekilenSayi = Pop();
        if (cekilenSayi != -1) {
            Enqueue(cekilenSayi);
        }
    }

    printf("\n--- Yigitin Son Hali ---\n");
    YigitListele();

    printf("\n--- Kuyrugun Son Hali ---\n");
    KuyrukListele();

    return 0;
}
