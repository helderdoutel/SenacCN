#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>

int main(int argc, char *arg[]){
    int valor;
    int base_atual;
    int base_nova;
    if(argc < 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
        return 1;
    }else if(argc > 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
        return 1;
    }else{
        for(int x=0; x < (int) strlen(arg[2]); x++){
            if(!(arg[2][x] >= '0' && arg[2][x] <= '9')){
                printf("Base atual incorreta (use valores de 2 a 32)\n");
                return 1;
            }
        }
        base_atual = atoi(arg[2]);
        if(base_atual < 2 || base_atual > 32){
            printf("Base atual incorreta (use valores de 2 a 32)\n");
            return 1;
        }

        for(int x=0; x < (int) strlen(arg[3]); x++){
            if(!(arg[3][x] >= '0' && arg[3][x] <= '9')){
                printf("Base nova incorreta (use valores de 2 a 32)\n");
                return 1;
            }
        }
        base_nova = atoi(arg[3]);
        if(base_nova < 2 || base_nova > 32){
            printf("Base nova incorreta (use valores de 2 a 32)\n");
            return 1;
        }

        if(base_nova == 10){
            printf("%d\n", para_base10(base_atual, arg[1]));
        }else if(base_atual == 10){
            char resp[100];
            printf("%s\n", de_base10(resp, base_nova, atoi(arg[1])));
        }else{
            char resp[100];
            valor = para_base10(base_atual, arg[1]);
            printf("%s\n", de_base10(resp, base_nova, valor));
        }
    }
    return 0;
}