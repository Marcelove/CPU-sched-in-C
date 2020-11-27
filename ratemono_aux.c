#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mono.h"

//RMS

int insertion(int *bursts, int *tempos, int tamanho)
{  
        int cont=1, a, tmp1, tmp2;
        while (cont < tamanho) {
                a = cont;
                cont++;
                
                while (a > 0 && tempos[a - 1] > tempos[a]) {
                        tmp1 = tempos[a];
                        tmp2 = bursts[a];
                        tempos[a] = tempos[a - 1];
                        tempos[a - 1] = tmp1;
                        bursts[a] = bursts[a - 1];
                        bursts[a - 1] = tmp2;
                        a--;
                } 
        }
        
        cont=0;
        while(cont<tamanho){
                printf("[%d %d] ", tempos[cont], bursts[cont]);
                cont++;
        }

        printf("\n");
                    
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