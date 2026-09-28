#include <cstdio>

int main() {
    int lignes = 12;
    int colonnes = 40;

    for (int y = 0; y < lignes; y+=1) {
        for (int x = 0; x < colonnes; x+=1) {
            if (y == 0 || y == lignes - 1 || x == 0 || x == colonnes - 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
