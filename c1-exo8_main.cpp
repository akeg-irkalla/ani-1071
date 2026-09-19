// Volontairement incomplet : calculer() est DÉCLARÉE (on promet qu'elle existe)
// mais jamais DÉFINIE (on ne fournit pas son corps).
//   clang++ -c c1-exo8_main.cpp                 -> réussit (le compilateur croit la promesse)
//   clang++ c1-exo8_main.cpp -o programme       -> échoue à l'édition de liens
#include <cstdio>

int calculer();

int main()
{
    int resultat = calculer();
    printf("%d\n", resultat);
    return 0;
}
