#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDEM 4
#define TRUE 1
#define FALSE 0

typedef struct {
    int conta_chaves;
    int chave[ORDEM - 1];
    int filho[ORDEM];
} Pagina;

int encontrada;
int rrn_encontrado = 0;
int pos_encontrado = 0;

FILE *arq;

Pagina le_pagina(int rrn);
int busca(int, int, int *, int *);
int busca_na_pagina(int, Pagina, int *);
void insere(int, int, int *, int *);


int main(int argc, char *argv[]) {
    if ((arq = fopen("btree.dat", "rb")) == NULL) {
        printf("Erro na abertura do arquivo --- programa abortado\n");
        exit(1);
    }

    int rrn;
    fread(&rrn, sizeof(int), 1, arq);
    printf("rrn: %i\n", rrn);

    if (argc == 3 && strcmp(argv[1], "-b") == 0) {
        busca(rrn, atoi(argv[2]), &rrn_encontrado, &pos_encontrado);
    }

}

int busca( int rrn, int chave, int *rrn_encontrado, int *pos_encontrado) {
    Pagina pag = le_pagina(rrn);
    if (rrn == EOF) {
        return FALSE;
    } else {
        int pos = 0;
        
        encontrada = busca_na_pagina(chave, pag, &pos);
        if (encontrada) {
            *rrn_encontrado = rrn;
            *pos_encontrado = pos;
            printf("Chave encontrada!!!\n");
        } else { 
            return (busca(pag.filho[pos], chave, rrn_encontrado, pos_encontrado));
        }
    }
}

int busca_na_pagina(int chave, Pagina pag, int *pos) {
    int i = 0;
    while (i < pag.conta_chaves && chave > pag.chave[i]) {
        i++;
        *pos = i;
        if (*pos < pag.conta_chaves && chave == pag.chave[*pos]) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
}

void insere(int rrn_atual, int chave, int *filho_d_pro, int *chave_pro) {
   Pagina pag;
    Pagina nova_pag;

    int pos = 0;
    int rrr_pro;
    int chv_pro;

    if (rrn_atual == EOF) {
        *chave_pro = chave;
        *filho_d_pro = -1;
    } else {
        pag = le_pagina(rrn_atual);
        encontrada = busca_na_pagina(chave, pag, &pos);
    }
    

}

Pagina le_pagina(int rrn) {
    Pagina pag;
    int byteOffset = (rrn * sizeof(Pagina)) + sizeof(int);
    fseek(arq, byteOffset, SEEK_SET);
    fread(&pag.conta_chaves, sizeof(int), 1, arq);
    fread(&pag.chave[0], sizeof(int), 1, arq);
    fread(&pag.chave[1], sizeof(int), 1, arq);
    fread(&pag.chave[2], sizeof(int), 1, arq);
    fread(&pag.filho[0], sizeof(int), 1, arq);
    fread(&pag.filho[1], sizeof(int), 1, arq);
    fread(&pag.filho[2], sizeof(int), 1, arq);
    fread(&pag.filho[3], sizeof(int), 1, arq);
    fread(&pag.filho[4], sizeof(int), 1, arq);

    printf("Conta chave: %i\n", pag.conta_chaves);
    printf("Chave 0: %i\n", pag.chave[0]);
    printf("Chave 1: %i\n", pag.chave[1]);
    printf("Chave 2: %i\n", pag.chave[2]);
    printf("Filho 0: %i\n", pag.filho[0]);
    printf("Filho 1: %i\n", pag.filho[1]);
    printf("Filho 2: %i\n", pag.filho[2]);
    printf("Filho 3: %i\n", pag.filho[3]);

    return pag;
}

//gcc btree.c -o btree
//.\btree.exe -b 2