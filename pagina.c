#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int contaChaves;
    char chaves[3];
    int filhos[4];
} Pagina;


int main () {
    FILE *arq;

    if ((arq = fopen("teste.txt", "w")) == NULL) {
        printf("Erro na criacao do arquivo --- programa abortado\n");
        exit(1);
    }

    fseek(arq,1,SEEK_END);
    Pagina page;

    page.contaChaves = 2;
    page.chaves[0] = 'I';
    page.chaves[1] = 'J';
    page.chaves[2] = 'T';
    page.filhos[0] = 0;
    page.filhos[1] = 2;
    page.filhos[2] = 3;
    page.filhos[2] = 6;

    fwrite(&page, sizeof(page), 1, arq);
}