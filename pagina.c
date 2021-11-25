#include <stdio.h>
#include <stdlib.h>

#define ordem 4

typedef struct {
    int contaChaves;
    int chaves[ordem - 1];
    int filhos[ordem];
} Pagina;


int main () {
    FILE *arq;
    Pagina page;

    if ((arq = fopen("btree.dat", "wb")) == NULL) {
        printf("Erro na criacao do arquivo --- programa abortado\n");
        exit(1);
    }

    int rrn = 2;
    fwrite(&rrn, sizeof(int), 1, arq);

    Pagina page0;

    page0.contaChaves = 2;
    page0.chaves[0] = 1;
    page0.chaves[1] = 2;
    page0.filhos[0] = -1;
    page0.filhos[1] = -1;
    page0.filhos[2] = -1;
    page0.filhos[2] = -1;

    fwrite(&page0, sizeof(page), 1, arq);

    Pagina page1;

    page1.contaChaves = 1;
    page1.chaves[0] = 4;
    page1.filhos[0] = -1;
    page1.filhos[1] = -1;
    page1.filhos[2] = -1;
    page1.filhos[2] = -1;

    fwrite(&page1, sizeof(page), 1, arq);

    Pagina page2;

    page2.contaChaves = 1;
    page2.chaves[0] = 3;
    page2.filhos[0] = 0;
    page2.filhos[1] = 1;
    page2.filhos[2] = -1;
    page2.filhos[2] = -1;

    fwrite(&page2, sizeof(page), 1, arq);
}

// gcc pagina.c -o createBTree
// .\createBTree.exe

// byteOffset = (raiz*sizeOf(pagina)) + sizeOf(int)
//2212-1-1-1-1-114-1-1-1-1-1-113-1-101-1-1