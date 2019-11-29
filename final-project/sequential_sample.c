#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mede_time.h"

#define SIZE 10000 
#define TRUE 0
#define FALSE 1

int main(int argc, char *argv[])
{
    char buff[SIZE];
    char palavra[SIZE];
    char arquivo[SIZE];
    int ocorrencias = 0;
    int i, j;
    int achou;
    FILE *f;

    TIMER_CLEAR;
    TIMER_START;

    // Abrir o arquivo e pegar a palavra
    if (argc == 3){
    	f = fopen(argv[1], "r");
    	strcpy(palavra,argv[2]);
    }

    else{
    	printf("Digite o nome do arquivo: ");
    	scanf("%s",&arquivo);
    	f = fopen(arquivo, "r");

    	printf("Digite a palavra a ser buscada: ");
    	scanf("%s",&palavra);
    }

    // Verificacao do nome do arquivo
    if(f == NULL){
    	printf("Arquivo nao encontrado\n");
    	exit(1);
    }

    //printf("palavra = %s\n",palavra);
    //printf("len = %d\n\n",strlen(palavra));

    // Leitura do arquivo linha por linha e busca pela palavra
    while(!feof(f)){
    	// Leitura de uma linha
    	fgets(buff, SIZE, f);
    	//printf("String read: %s", buff);
    	//printf("len = %d\n\n",strlen(buff));

    	// Busca pela palavra
    	if(strlen(buff) >= strlen(palavra)){
	    	for(i = 0; i < strlen(buff) - strlen(palavra); i++){
	    		achou = TRUE;

	    		// Comparacao da posicao da linha com a palavra
	    		for(j = 0; j < strlen(palavra); j++){
	    			if(palavra[j] != buff[i+j]){
	    				achou = FALSE;
	    				break;
	    			}
	    		}

	    		if (achou == TRUE){
	    	    	//printf("Achei!\n");
	    			ocorrencias++;
	    		}

	    	}
	    }
    }

    printf("=======================================\n");
    printf("Total de ocorrencias = %d\n",ocorrencias);
    printf("=======================================\n");

    // Fecha o arquivo
    fclose(f);

    TIMER_STOP;
    printf("Tempo: %f \n", TIMER_ELAPSED);
    
    return 0;
    
}