/* ÇÝFT YÖNLÜ BAÐLI LÝSTE ile PALÝNDROM KONTROLÜ (tolower yok) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *sonraki;
    struct Node *onceki;
} Node;

Node *ilk = NULL;
Node *son = NULL; // Listenin son düðümünü takip etmek için

Node *DugumOlustur(char veri) {
    Node *yeniDugum = (Node *)malloc(sizeof(Node));
    if (yeniDugum == NULL) {
        printf("Bellek ayýrma hatasý!\n");
        exit(1);
    }
    yeniDugum->data = veri;
    yeniDugum->sonraki = NULL;
    yeniDugum->onceki = NULL;
    return yeniDugum;
}

void SonaEkle(char veri) {
    Node *yeniDugum = DugumOlustur(veri);

    if (ilk == NULL) {
        ilk = yeniDugum;
        son = yeniDugum;
    } else {
        son->sonraki = yeniDugum;
        yeniDugum->onceki = son;
        son = yeniDugum;
    }
}

int PalindromKontrol() {
    if (ilk == NULL || ilk == son) {
        return 1; // Boþ veya tek karakterli kelimeler palindromdur
    }

    Node *baslangic = ilk;
    Node *bitis = son;

    while (baslangic != bitis && baslangic->onceki != bitis) {
        if (baslangic->data != bitis->data) {
            return 0; // Palindrom deðil
        }
        baslangic = baslangic->sonraki;
        bitis = bitis->onceki;
    }

    return 1; // Palindrom
}

void ListeyiYazdir() {
    printf("Baðlý Liste (Kelimedeki Harfler): ");
    Node *gecici = ilk;
    while (gecici != NULL) {
        printf("%c <-> ", gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

void BellekTemizle() {
    Node *gecici = ilk;
    Node *silinecek;
    while (gecici != NULL) {
        silinecek = gecici;
        gecici = gecici->sonraki;
        free(silinecek);
    }
    ilk = NULL;
    son = NULL;
}

int main() {
    char kelime[100];

    printf("Bir kelime girin: ");
    scanf("%s", kelime);

    // Kelimenin her harfini baðlý listeye ekle
    for (int i = 0; kelime[i] != '\0'; i++) {
        SonaEkle(kelime[i]);
    }

    ListeyiYazdir();

    if (PalindromKontrol()) {
        printf("Girilen kelime palindromdur.\n");
    } else {
        printf("Girilen kelime palindrom deðildir.\n");
    }

    BellekTemizle(); // Program bitmeden önce belleði temizle

    return 0;
}
