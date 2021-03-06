#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void posynomial(int argc, char *argv[]) {
    if (argc < 3) {
        printf("At least a_0 and x are required\n");
        return;
    }
    // The naive way. Can put atof down there
    double *a = new double[argc-2];
    for (int i = 1;i < argc-1;i++) {
        a[i-1] = atof(argv[i]);
    }
    double x = atof(argv[argc-1]);
    if (fabs(x) < 1e-6) {
        printf("x should not be zero\n");
        return;
    }
    double current_multiplier = 1.0;
    double answer = 0.0;
    for (int i = 0;i < argc-2;i++) {
        answer += a[i] * current_multiplier;
        current_multiplier /= x;
    }

    printf("Posynomial: %lf\n", answer);
    delete[] a;
}
