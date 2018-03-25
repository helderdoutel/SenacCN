#include <stdio.h>
#include <math.h>

double f(double i){
   if(i <= 1) {
      return 1;
   }
   return i * f(i - 1);
}

double seno(double x){
    double a = 0;
    int y;
    for(y=0; y<50; y++){
        // printf("%f ", pow(x, ((2 * y) + 1)));
        // printf("/ %f\n", f((2 * y) + 1));
        a += (pow(-1, y) * (pow(x, ((2 * y) + 1))/f((2 * y) + 1)));
    }
    return a;
}

double cosseno(double x){
    double a = 0;
    int y;
    for(y=0; y<50; y++){
        // printf("%f ", pow(x, ((2 * y) + 1)));
        // printf("/ %f\n", f((2 * y) + 1));
        a += (pow(-1, y) * (pow(x, (2 * y))/f(2 * y)));
    }
    return a;
}