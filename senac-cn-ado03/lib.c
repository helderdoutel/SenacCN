#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

void euler_float(long double iteracoes){
    FILE * f = fopen("output_l.dat","w");
    FILE * gnuplot = popen("gnuplot -persistent","w");
    long double x = 1.0;
    float e;
    while(x <= iteracoes){
        e = powf(1.0+(1.0/x),x);
        fprintf(f,"%Lf\t%f\n",x,e);
        // printf("%Lf\t%f\n",x,e);

        x+=100;

    }
    fclose(f);
    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set output 'euler_flt.png'\n");
    fprintf(gnuplot,"plot 'output_l.dat'\n");
    
    fflush(gnuplot);
    fprintf(gnuplot,"exit\n");
    pclose(gnuplot);
    pclose(gnuplot);
    remove("output_l.dat");
}

// void euler_double(long double iteracoes){
//     FILE * f = fopen("output_d.dat","w");
//     FILE * gnuplot = popen("gnuplot -persistent","w");
// }

// void euler_ldouble(long double iteracoes){
//     FILE * f = fopen("output_ld.dat","w");
//     FILE * gnuplot = popen("gnuplot -persistent","w");
// }