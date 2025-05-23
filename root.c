#include <math.h>
#include "root.h"
#include <stdlib.h>
#include <stdio.h>

/* calculates intersection of g and f at given segment [a, b]
 * @param f first function
 * @param g second function
 * @param a segment start
 * @param b segment end
 * @param eps1 accurasy of calculations
 * @param iterations point to interetions counter
 */
double root(double (*f)(double), double (*g)(double), double a, double b, double eps1,  int *iterations) {
    int i = 0;

    double v_a = f(a) - g(a);
    double v_b = f(b) - g(b);
    if(v_a * v_b > 0) {
        printf("incorrect input segment: [%lf;%lf].\n", a, b);
        exit(1);
    }

    double x_1 = a;
    double x_0 = b;
    double v_x_0 = f(x_0) - g(x_0);

    while ((f(x_0 - eps1 / 2) - g(x_0 - eps1 / 2))*(f(x_0 + eps1 / 2) - g(x_0 + eps1 / 2)) > 0) {
        v_a = f(a) - g(a);
        v_b = f(b) - g(b);
    
        x_1 = x_0;
        x_0 = a - v_a /(v_b - v_a) * (b - a);
    
        v_x_0 = f(x_0) - g(x_0);

        if (v_x_0 * v_b <= 0) {
            a = x_0;
        } else if (v_x_0 * v_a <= 0) {
            b = x_0; 
        }

        i++;
    }

    if (iterations != NULL)
        *iterations = i;
    
    return x_0;
}
