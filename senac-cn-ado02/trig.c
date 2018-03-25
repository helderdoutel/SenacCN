#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

int main(){
    double piDouble = 3.1415926535897932384626433832795;
    double seno_var, cosseno_var, cos_c, sin_c;
    double valor;
    int voltas = 2 * 360;
    double erro_abs_s, erro_abs_c;
    double erro_rel_s, erro_rel_c;
    FILE *arquivo_seno = fopen("seno.dat", "w");
    FILE *arquivo_cosseno = fopen("cosseno.dat", "w");
    FILE *plot = popen("gnuplot", "w");
    for(int x = 0; x <= voltas; x++){
        valor = x * (piDouble/180);
        seno_var = seno(valor);
        sin_c = sin(valor);
        erro_abs_s = sin_c - seno_var;
        erro_rel_s = erro_abs_s/sin_c;
        fprintf(arquivo_seno, "%lf\t%lf\t%lf\t%lf\n", valor, seno_var, erro_abs_s, erro_rel_s);
        // cosseno
        cosseno_var = cosseno(valor);
        cos_c = cos(valor);
        erro_abs_c = cos_c - cosseno_var;
        erro_rel_c = erro_abs_c/cos_c;
        fprintf(arquivo_cosseno, "%lf\t%lf\t%lf\t%lf\n", valor, cosseno_var, erro_abs_c, erro_rel_c);
    }
    fclose(arquivo_seno);
    fclose(arquivo_cosseno);

    fprintf(plot, "set terminal png\n");
    fprintf(plot, "set output 'seno.png'\n");
    fprintf(plot, "plot 'seno.dat'\n");
    fprintf(plot, "set output 'cosseno.png'\n");
    fprintf(plot, "plot 'cosseno.dat'\n");
    fprintf(plot,"exit\n");
    pclose(plot);
    return 0;
}