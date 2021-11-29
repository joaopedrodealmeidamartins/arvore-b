#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDEM 4

typedef struct {
    int conta_chaves;
    int chave[ORDEM - 1];
    int filho[ORDEM];
} Pagina;

int busca(FILE *, int);
int busca_na_pagina(int, Pagina, int);
Pagina pagina(FILE *, Pagina);


int main(int argc, char *argv[]) {
    FILE *arq;

    if ((arq = fopen("btree.dat", "rb")) == NULL) {
        printf("Erro na abertura do arquivo --- programa abortado\n");
        exit(1);
    }

    if (argc == 3 && strcmp(argv[1], "-b") == 0) {
        busca(arq, atoi(argv[2]));
    }

}

int busca(FILE *arq, int chave) {
    int pos;
    int rrn;
    int raiz = 1;
    int contaChaves;
    Pagina pag;

    int byteOffsetRaiz = (raiz * sizeof(Pagina)) + sizeof(int);
    fseek(arq, byteOffsetRaiz, SEEK_SET);
    
    pagina(arq, pag);
    if (chave == busca_na_pagina(chave, pag, pos)) {
        printf("Chave encontrada!!!\n");
    } else if (chave == -1) { 
        printf("Chave não encontrada!!!\n");
    }
}

int busca_na_pagina(int chave, Pagina pag, int pos) {
    int i = 0;
    while (i < pag.conta_chaves && chave > pag.chave[i]) {
        i++;
        pos = i;
        if (pos < pag.conta_chaves && chave == pag.chave[pos]) {
            return chave;
        } else {
            return -1;
        }
    }
}

Pagina pagina(FILE *arq, Pagina pag) {
    fread(&pag.conta_chaves, sizeof(int), 1, arq);
    fread(&pag.chave[0], sizeof(int), 1, arq);
    fread(&pag.chave[1], sizeof(int), 1, arq);
    fread(&pag.chave[2], sizeof(int), 1, arq);
    fread(&pag.filho[0], sizeof(int), 1, arq);
    fread(&pag.filho[1], sizeof(int), 1, arq);
    fread(&pag.filho[2], sizeof(int), 1, arq);
    fread(&pag.filho[3], sizeof(int), 1, arq);
    fread(&pag.filho[4], sizeof(int), 1, arq);
}
//gcc btree.c -o btree
//.\btree.exe -b 2