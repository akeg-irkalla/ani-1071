// Le programme rend 3 au système. Vérification (Linux/macOS) :
//   ./programme ; echo $?      -> affiche 3
// Utilité : un outil qui enchaîne des programmes (make, un script, une CI) ne lit pas
// ce qui s'affiche, il lit ce nombre. 0 = succès, tout autre nombre = échec (et lequel).
// Le programme suivant ne démarre que si celui-ci a rendu 0 (opérateur && du shell).
#include <cstdio>

int main()
{
    printf("Bonjour\n");
    return 3;
}
