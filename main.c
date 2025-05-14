#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "integral.h"
#include "root.h"
#include "functions.h"


int main(int argc, char *argv[]) {

    int iter = 0;
    int inter = 0;

    double eps = 10e-5;

    int test_f_1, test_f_2;
    double test_a, test_b, test_eps;
    char *fun_dis[] = {"exp(-x) + 3", "2x - 2", "1 / x"};
    double (*funs[])(double) = {f1, f2, f3};

    // flag processing
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-help")) {
            printf(
                "Calculates surface area between three functions:\n"
                "f1 = exp(-x) + 3, f2 = 2 * x - 2, f3 = 1 / x\n"
                "-help - prints information about program\n"
                "-testr f1 f2 a b eps - tests root function\n"
                "-testi f a b eps - tests root function\n"
                "-inter - intersection points are printed if enabled\n"
                "-iter - amount of iterations for each intersection of points is printed if enabled\n"
                "-eps eps - sets calculation accuracy to eps\n"
                );
            
            return 0;
        } 
        else if (!strcmp(argv[i], "-inter")) {
            inter = 1;
        }
        else if (!strcmp(argv[i], "-iter")) {
            iter = 1;
        }
        else if (!strcmp(argv[i], "-testr")) { 

            if (argc - i - 1 < 5) {
                printf("Not enought arguments\n");

                return 1;
            }

            test_f_1 = atoi(argv[i + 1]);
            test_f_2 = atoi(argv[i + 2]);
            test_a = atof(argv[i + 3]);
            test_b = atof(argv[i + 4]);
            test_eps = atof(argv[i + 5]);

            double res = root(funs[test_f_1 - 1], funs[test_f_2 - 1], test_a, test_b, test_eps, NULL);

            printf("%.15lf\n", res);

            return 0;

        }
        else if (!strcmp(argv[i], "-testi")) {

            if (argc - i - 1 < 4) {
                printf("Not enought arguments\n");

                return 1;
            }

            test_f_1 = atoi(argv[i + 1]);
            test_a = atof(argv[i + 2]);
            test_b = atof(argv[i + 3]);
            test_eps = atof(argv[i + 4]);

            double res = integral(funs[test_f_1 - 1], test_a, test_b, test_eps);
   
            printf("%.15lf\n", res);

            return 0;
        } else if (!strcmp(argv[i], "-eps")) {
            if (argc - i - 1 < 1) {
                printf("Not enought arguments\n");

                return 1;
            }

            i++;
            eps = atof(argv[i]);
            
        } else {
            printf("Unknown flag: %s\n", argv[i]);

            return 1;
        }
        
    }

    int iterations;
    double eps1 = 0.01 * eps;
    double eps2 = 0.1 * eps;

    // root calculations
    double x1 = root(f1, f3, 0.01, 1, eps1, &iterations);
    if (iter || inter) {
        printf("%s = %s:\n", fun_dis[0], fun_dis[2]);
        if (iter)
            printf("\titeratins: %d\n", iterations);
        if (inter)
            printf("\tintersection: %lf\n", x1);
        
        putchar('\n');
    }

    double x2 = root(f2, f3, 1, 2, eps1, &iterations);
    if (iter || inter) {
        printf("%s = %s:\n", fun_dis[1], fun_dis[2]);
        if (iter)
            printf("\titeratins: %d\n", iterations);
        if (inter)
            printf("\tintersection: %lf\n", x2);
        
        putchar('\n');
    }

    double x3 = root(f1, f2, 2, 3, eps1, &iterations);
    if (iter || inter) {
        printf("%s = %s:\n", fun_dis[0], fun_dis[1]);
        if (iter)
            printf("\titeratins: %d\n", iterations);
        if (inter)
            printf("\tintersection: %lf\n", x3);

        putchar('\n');
    }


    // integral calculations
    
    double area = integral(f1, x1, x3, eps2);
    area -= integral(f3, x1, x2, eps2);
    area -= integral(f2, x2, x3, eps2);

    printf("area = %lf\n", area);

    return 0;
}
