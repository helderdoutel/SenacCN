#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

void euler_float(long double iteracoes){
    FILE * f = fopen("saida.dat","w");
    FILE * gnuplot = popen("gnuplot -persistent","w");
    long double x = 1.0;
    long double i = 1.0;
    long double controle = 100.0;
    float e;
    while(x <= iteracoes){
        e = powf(1.0+(1.0/x),x);
        fprintf(f,"%Lf\t%f\n",x,e);
        // printf("%Lf\t%f\n",x,e);
        if(x >= controle){
            i = i*10;
            controle = controle*10;
        }
        x += i;
        
    }
    fclose(f);
    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set output 'euler_flt.png'\n");
    fprintf(gnuplot,"plot 'saida.dat'\n");

    fprintf(gnuplot,"exit\n");
    pclose(gnuplot);
    remove("saida.dat");
}

void euler_double(long double iteracoes){
    FILE * f = fopen("saida.dat","w");
    FILE * gnuplot = popen("gnuplot -persistent","w");
    long double x = 1.0;
    long double i = 1.0;
    long double controle = 100.0;
    double e;
    while(x <= iteracoes){
        e = pow(1.0+(1.0/x),x);
        fprintf(f,"%Lf\t%f\n",x,e);
        // printf("%Lf\t%f\n",x,e);
        if(x >= controle){
            i = i*10;
            controle = controle*10;
        }
        x += i;
        
    }
    fclose(f);
    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set output 'euler_dbl.png'\n");
    fprintf(gnuplot,"plot 'saida.dat'\n");
    
    fprintf(gnuplot,"exit\n");
    pclose(gnuplot);
    remove("saida.dat");
}

void euler_ldouble(long double iteracoes){
    FILE * f = fopen("saida.dat","w");
    FILE * gnuplot = popen("gnuplot -persistent","w");
    long double x = 1.0;
    long double i = 1.0;
    long double controle = 100.0;
    double e;
    while(x <= iteracoes){
        e = powl(1.0+(1.0/x),x);
        fprintf(f,"%Lf\t%f\n",x,e);
        // printf("%Lf\t%f\n",x,e);
        if(x >= controle){
            i = i*10;
            controle = controle*10;
        }
        x += i;
        
    }
    fclose(f);
    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set output 'euler_ldbl.png'\n");
    fprintf(gnuplot,"plot 'saida.dat'\n");
    
    fprintf(gnuplot,"exit\n");
    pclose(gnuplot);
    remove("saida.dat");
}