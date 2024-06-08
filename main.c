#include <stdio.h>

long combination(int n, int r);
long recursive(int n, int k);
long general(int n, int k);

long arr[1000][1000] = {0};

int main()
{
    for (int i = 0; i < 1000; i++) {
        arr[i][0] = 1;
    }

    int n = 30;
    int k = 12;
    long gen = general(n, k);
    printf("%ld\n", gen);

    long recurs = recursive(n, k);
    printf("%ld\n", recurs);
    
    // for (int n = 2; n <= 50; n++) {
    //     for (int k = 0; k <= (n / 2); k++) {
    //         long recurs = recursive(n, k);
    //         long gen = general(n, k);

    //         if (recurs != gen) {
    //             printf("n: %d, k: %d\n", n, k);
    //         }
    //     }
    // }
    return 0;
}

long general(int n, int k)
{
    if (k == 0) {
        return 1;
    }
    long result = 1;

    long a = 1;

    for (int i = 1; i <= k; i++) {
        a *= i;
    }

    long b = 1;
    for (int i = 1; i < k; i++) {
        b *= (n - (k + i));
    }

    if (k & 1) {
        result *= -1;
    }

    result *= (b * n) / a;

    return result;
}

long recursive(int n, int k)
{
    if (k == 0) {
        return 1;
    }

    long result = 0;

    for (long m = 0; m < k; m++) {
        long com = combination(n - (2 * m), k - m);
        
        result += com * arr[n][m];
    }

    result *= -1;

    arr[n][k] = result;

    return result;
}

long combination(int n, int r)
{
    long a = 1;
    long b = 1;

    for (int i = 0; i < r; i++) {
        a *= n - i;
    }

    // printf("a: %ld\n", a);

    for (int i = 1; i <= r; i++) {
         b *= i;
    }

    // printf("b: %ld\n", b);

    return a / b;
}

