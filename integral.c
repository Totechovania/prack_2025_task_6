#include <math.h>
#include "integral.h"

/* calculates integral of f at given segment [a, b]
 * @param f function
 * @param a segment start
 * @param b segment end
 * @param eps2 accurasy of calculations
 */
double integral(double (*f)(double), double a, double b, double eps2){
    int n = 1;
    double h = (b - a) / (2 * n);

    double edges = f(a) + f(b);
    double odd = 0;
    double even = 0;

    for (int i = 1; i < 2 * n; i += 2) {
        odd += f(a + i * h);
    }

    for (int i = 2; i < 2 * n; i += 2) {
        even += f(a + i * h);
    }
    
    double res_2n = h * (edges + 2 * even + 4 * odd) / 3;
    double res_n;

    do
    {
        n *= 2;
        h /= 2;

        even += odd;
        odd = 0;

        for (int i = 1; i < 2 * n; i += 2) {
            odd += f(a + i * h);
        }

        res_n = res_2n;
        res_2n = h * (edges + 2 * even + 4 * odd) / 3;

    } while (fabs(res_2n - res_n) > eps2);
    
    
    return res_2n;
}
