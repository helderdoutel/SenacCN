#include <stdio.h>
#include "lib.h"

int main(int argc, char *arg[]){
    int temp;
    if(argc < 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
    }else if(argc > 4){
        printf("Execute da seguinte maneira: Executavel <numero a converter> <base> <nova base>\n");
    }else{
        printf("teste %s\n", arg[1]);
        sscanf(arg[1], "%d", &temp);
        printf("convertido %d\n", temp + 10);
        printf("int %d\n", argc);
    }
    
    return 0;
}