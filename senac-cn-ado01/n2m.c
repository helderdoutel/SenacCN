#include <stdio.h>
#include "lib.h"

int main(int argc, char *arg[]){
    int numero;
    int base_atual;
    int base_nova;
    if(argc < 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
    }else if(argc > 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
    }else{
        numero = atoi(arg[1]);
        base_atual = atoi(arg[2]);
        base_nova = atoi(arg[3]);
        printf("numero: %d\n", numero);
        printf("base atual: %d\n", base_atual);
        printf("base nova: %d\n", base_nova);
    }
    
    return 0;
}