#include <cstdio>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}


%4d affiche l'entier sur au moins 4 caractères.
Comme chaque nombre occupe la même largeur, les colonnes s'alignent.
