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
    int rrn = 2;

    if ((arq = fopen("btree.dat", "wb")) == NULL) {
        printf("Erro na criacao do arquivo --- programa abortado\n");
        exit(1);
    }

    fwrite(&rrn, sizeof(int), 1, arq);

    Pagina page;

    Pagina page0;
    page0.contaChaves = 2;
    page0.chaves[0] = 1;
    page0.chaves[1] = 2;

    fwrite(&page0, sizeof(page), 1, arq);

    Pagina page1;
    page1.contaChaves = 1;
    page1.chaves[0] = 4;

    fwrite(&page1, sizeof(page), 1, arq);

    Pagina page2;
    page2.contaChaves = 1;
    page2.chaves[0] = 3;
    page2.filhos[0] = 0;
    page2.filhos[1] = 1;

    fwrite(&page2, sizeof(page), 1, arq);
}