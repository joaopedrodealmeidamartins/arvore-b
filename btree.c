#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "util.h"

#define ORDEM 5
#define DELIM_STR "|"
#define TAM_MAX_REG 256

void criacao(char *);
void imprimeInfo();
void imprimeInfoDec();
void limpa_buffer(char *, int);

int main(int argc, char *argv[])
{
    char *nome_arq;

    if (argc == 3 && strcmp(argv[1], "-c") == 0)
    {
        printf("Modo de criacao ativado ... nome do arquivo = %s\n", argv[2]);
        criacao(argv[2]);
    }
    /*else if (argc == 2 && strcmp(argv[1], "-p") == 0)
    {
        printf("Modo de impressao das informacoes ativado ... );
        imprimeInfo();
    }
    else if (argc == 2 && strcmp(argv[1], "-k") == 0)
    {
        printf("Modo de impressao das informacoes ordenadas ativado ...);
        //imprimeInfoDec();
    }
    else
    {
        fprintf(stderr, "Argumentos incorretos!\n");
        fprintf(stderr, "Modo de uso:\n");
        fprintf(stderr, "$ %s (-i|-e) nome_arquivo\n", argv[0]);
        fprintf(stderr, "$ %s -p\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;*/
}

void criacao(char *arq_read)
{
    typedef struct pagina
    {
        int chave[ORDEM - 1];
        int filhos[ORDEM];

    } pagina;
    int rrn;
    int chave;
    FILE *arq;
    FILE *arqDados;
    char buffer[TAM_MAX_REG];

    if ((arq = fopen(arq_read, "r")) != NULL)
    {
        if ((arqDados = fopen("btree.dat", "wb")) != NULL)
        {
            limpa_buffer(buffer, TAM_MAX_REG);
            //fwrite();
        }
    }

    fseek(arq, 0, SEEK_SET);
    fread(&arqDados, sizeof(int), 1, arq);
    input(arq, TAM_MAX_REG);
    limpa_buffer(buffer, TAM_MAX_REG);
}