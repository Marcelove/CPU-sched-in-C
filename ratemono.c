#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mono.h"

//RMS

int main(int argc, char * argv[])
{

        if (argc != 2){
                printf("Erro no número de argumentos passados.");
                return 0;
        }

        int passada = 0, ativo = 0;
        int a, b, temporario = 0, quantidade = 0;
        char linha[20];
        char lixo[10];

        char stringFalsa[2];

        int bursts[10];
        int tempos[10];

        int  tempoLimite;

        FILE * fp = fopen(argv[1], "r");
        FILE * fp2 = fopen("rate_mlaj.out", "w");

        if (fp == NULL){
                printf("\nErro ao abrir o arquivo.\n");
                return 0;
        }

        for (a=0; ;a++){

                if (a == 0){
                        if ((fgets(linha, sizeof(linha), fp)) != NULL) 
                                tempoLimite = atoi(linha); // tempo limite é o primeiro número da linha
                }
                else {
                        if ((fgets(linha, sizeof(linha), fp)) == NULL) {
                                break;
                        }

                        for(b=0; b < sizeof(linha); b++){
                                if ((linha[b] == '0') || (linha[b] == '1') ||(linha[b] == '2') ||(linha[b] == '3') 
                                        ||(linha[b] == '4') ||(linha[b] == '5') ||(linha[b] == '6') ||(linha[b] == '7') 
                                        ||(linha[b] == '8') ||(linha[b] == '9')){

                                        ativo = 1;

                                        stringFalsa[0] = linha[b];

                                        temporario = (temporario*10) + atoi(stringFalsa);

                                }

                                else{
                                        if ((ativo == 1) && (passada == 0)){
                                                tempos[a-1] = temporario;
                                                temporario = 0;
                                                ativo = 0;
                                                passada = 1;
                                        }

                                        else if ((ativo == 1) && (passada == 1)){
                                                bursts[a-1] = temporario;
                                                temporario = 0;
                                                ativo = 0;
                                        }
                                }
                        }

                        quantidade++;
                }

        }

        fclose(fp);

        int tempoatual = 0;

        insertion(bursts, tempos, quantidade);

        for(a=0; a < quantidade; a++){

                tempoatual+=bursts[a];

                if (tempoatual > tempoLimite){
                        printf("\nTempo estourado.");
                        return 0;
                }

                //printf("[T%d] for %d units. current time is %d\n", a+1, bursts[a], tempoatual);
                fprintf (fp2, "[T%d] for %d units - F\n", a+1, bursts[a]);
        }

         fclose(fp2);

        return 0;
}               


/*
12 3
6 7
90 100
80 5
2 3
 5 6
1 2
8 0
9 7
6 7
*/