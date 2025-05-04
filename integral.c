#include <math.h>
#include "integral.h"
#include <stdio.h>

double integral(double (*f)(double), double a, double b, double eps2){

    double res_1 = f(a) + f(b);
    res_1 /= 2;

    int n = 1;
    double res_2 = res_1;
    double h = (b - a);
    int i = 0;
    do {

        if (i == 28){
            printf("Warning: calculations are to heavy for given epsilon accuracy. Current accurecy is %lf.\n",
                 2 * fabs(h * res_1 - h * res_2));
            break;
        }

        i++;
        n *= 2;
        h /= 2;


        double tmp;
        tmp = res_1;
        res_1 = res_2;
        res_2 = tmp; 

        res_1 *= 2;


        for (int j = 1; j < n; j += 2) {
            res_2 += f(a + h * j); 

        }

            
    } while (fabs(h * res_1 - h * res_2) > eps2);
    

    return res_2 * h;
}