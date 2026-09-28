#include <cstdio>

int main(void) {
    int n, somme = 0;
    printf("Saisir 5 entiers :\n");
    for (int i = 0; i < 5; i+=1) {
        scanf("%d", &n);
        somme += n;
    }
    printf("Somme : %d\n", somme);
    printf("Moyenne : %.1f\n", somme / 5.0);
    return 0;
}
