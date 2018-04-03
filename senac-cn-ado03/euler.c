#include <stdio.h>
#include "lib.h"

int main(){
    long double iteracoes = 100000000000000000000.0;
    euler_float(iteracoes);
    euler_double(iteracoes);
    euler_ldouble(iteracoes);
    return 0;
}