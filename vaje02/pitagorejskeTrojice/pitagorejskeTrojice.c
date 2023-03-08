#include <stdio.h>
#include <math.h>

int main() {
    double m, n;
    double c = 0;
    double a = 1;
    double b = 1;
    double counter = 0;

    scanf("%lf %lf", &m, &n);

    for (int i = m; i <= n; i++){
        c = pow(i, 2);
        for (a = 1; a <= i; a++){
            for (b = a; b <= i; b++){
                if (pow(a, 2) + pow(b, 2) == c){
                    // printf("%f + %f = %f\n", pow(a, 2), pow(b,2), c);
                    counter++;
                }
            } 
        }
    }
    printf("%d\n", (int) counter);
}