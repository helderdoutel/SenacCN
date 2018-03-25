#include <stdio.h>
#include "lib.h"
#include <math.h>

int main(){
    double piDouble = 3.1415926535897932384626433832795;
    double seno_var, cosseno_var;
    double valor;
    int voltas = 4 * 360;
    for(int x = 0; x <= voltas; x++){
        valor = x * (piDouble/180);
        seno_var = seno(valor);
        printf("seno(%f) = %lf ", valor, seno_var);
        printf("/ funcao sin math.c %f \n", sin(valor));
        cosseno_var = cosseno(valor);
        printf("cosseno(%f) = %lf ", valor, cosseno_var);
        printf("/ funcao cos math.c %f \n", cos(valor));
    }
    return 0;
}