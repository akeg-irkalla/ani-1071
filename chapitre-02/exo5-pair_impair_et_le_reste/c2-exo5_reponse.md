#include <cstdio>

int main(void) {
    int n;
    printf("Saisir un entier :\n");
    scanf("%d", &n);
    if (n % 2 == 0) {
      printf("pair\n");
    } else {
      printf("impair\n");
    }

    if (n > 0) printf("positif\n");
    if (n < 0) printf("negatif\n");
    if (n == 0) printf("nul\n");

    if (n % 3 == 0) printf("divisible par 3\n");
    else printf("non divisible par 3\n");

    return 0;
}
