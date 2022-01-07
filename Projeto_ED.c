/*
	FEITO NO PRIMEIRO SEMESTRE DE 2018 (3° Período)
Este programa deve processar o texto de "arquivo.txt" e salvar os resultados das
palavras, separadas e sem letras maiúsiculas, em "palavras.dat"
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


typedef struct PALAVRA{
    char palavra[50];
    int vez;
    struct PALAVRA *prox;
}Palav;

typedef struct HASH{
    struct PALAVRA *prox;
}Hash;

int inserir( Hash *tabelaPos, char *palavra );
void leitura( FILE *f, Hash *h );
void gravar( Hash *tabela );
void lerBin();

int main( int argc, char *argv[ ] ){
    int i;
    Hash vetorAZ[26];
    FILE *file;

    for( i = 0; i < 26; i++ )
        vetorAZ[i].prox = NULL;

    printf("%s\n",argv[1]);

    if( ( file = fopen("arquivo.txt","r") ) == NULL  ){
        printf("Impossivel abrir o arquivo!!\n");
        exit(0);
    }

    leitura(file,vetorAZ);
    printf("\n\nArquivo Lido!!\n");
    fclose(file);

    gravar( vetorAZ );
    printf("Aruivo gravado!!\n");


return 0;
}

void gravar( Hash *tabela ){
    int i;
    FILE *file;
    Palav *aux;

    if( (file = fopen("palavras.dat","w+b")) == NULL ){
        printf("\n\nImpossivel abrir o arquivo!!\n\n"); fclose(file); return;
    }

    for( i = 0; i < 26; i++ ){
        aux = tabela[i].prox;

        while( aux != NULL ){
            fwrite(aux,sizeof(Palav),1,file);
           // printf("palavra : %s\n",aux->palavra);
            aux = aux->prox;
        }
    }
    fclose(file);
}

int inserir( Hash *tabelaPos, char *palavra ){

    Palav *novo = (Palav *) malloc( sizeof(Palav) );
    strcpy(novo->palavra,palavra);
    novo->vez = 1;

    if( tabelaPos->prox == NULL ){
        tabelaPos->prox = novo;
        novo->prox = NULL;
    }
    else{
        Palav *aux = tabelaPos->prox;

        while( aux != NULL ){
            if( strcmp(aux->palavra,palavra) == 0 ){
                aux->vez++;
                free(novo);
                return 0;
            }
            aux = aux->prox;
        }

        aux = tabelaPos->prox;
        tabelaPos->prox = novo;
        novo->prox = aux;

    }

return 0;
}

void leitura( FILE *f, Hash *h ){
    char caracteresIgn[34] = "!$.,;:*()\"“[]/?-_'@&—1234567890";
    char palavra[50] = "\0";
    int i = 0, j, flag = 1;


    while( fread(&palavra[i],1,1,f) ){

        for( j = 0; j < 34; j++ ){
            if( palavra[i] == ' ' ){
                while( fread(&palavra[i],1,1,f) && palavra[i] == ' ' );
                if( feof(f) ) return;
                fseek(f,-1,SEEK_CUR);
                flag = 0;
            }
            else if( palavra[i] == caracteresIgn[j] || palavra[i] == '\n' || palavra[i] == '\r' ){ flag = 0; break; }
        }
        if( flag == 0) break;
        i++;
    };

    palavra[i] = '\0';

    if( strcmp(palavra,"\0") != 0 && strcmp(palavra," ") ){ inserir(&h[ tolower(palavra[0]) % 26 ],palavra); }

    if( !feof(f) ) leitura(f,h);
}
