// La variable 'inutile' est déclarée puis jamais utilisée : ce n'est pas une erreur
// (le programme est valide), mais -Wall -Wextra le signale.
//   clang++ -std=c++17 -Wall -Wextra c1-exo10_main.cpp -o programme
#include <cstdio>

int main()
{
    int inutile = 42;
    printf("Bonjour\n");
    return 0;
}
