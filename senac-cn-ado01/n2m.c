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
    }else if(argc > 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
    }else{
        base_atual = atoi(arg[2]);
        base_nova = atoi(arg[3]);
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