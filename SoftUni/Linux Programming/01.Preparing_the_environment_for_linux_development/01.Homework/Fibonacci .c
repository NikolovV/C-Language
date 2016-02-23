#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long fib(unsigned int n);

int main()
{
    long long fibonacci = 1, temp = 0;
    long n = 1;
    while (fibonacci > 0)
    {
        temp = fibonacci;
        fibonacci = fib(n);
        n++;
    }

    fibonacci = temp;
    printf("%lld\n", fibonacci);

    char fileName[7];
    snprintf(fileName, 3, "%ld", n);
    strncat(fileName, ".txt", 4);

    FILE *fp = fopen(fileName, "w");
    if (!fp)
    {
        fprintf(stderr, "Could not create file!");
        exit(0);
    }

    fclose(fp);

    return 0;
}

long long fib(unsigned int n)
{
    long long i = n - 1, a = 1, b = 0, c = 0, d = 1, t;
    if (n <= 0)
        return 0;
    while (i > 0)
    {
        if (i % 2 == 1)
        {
            t = d * (b + a) + c*b;
            a = d * b + c*a;
            b = t;
        }
        t = d * (2 * c + d);
        c = c * c + d*d;
        d = t;
        i = i / 2;
    }
    return a + b;
}
