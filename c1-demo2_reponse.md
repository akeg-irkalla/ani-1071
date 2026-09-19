# Démo 2 — Dessiner avec du texte

```cpp
#include <cstdio>

int main()
{
    printf("####################\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("####################\n");
    return 0;
}
```
Vérifié : 7 lignes de 20 caractères (`./rect | awk '{print length($0)}'` → `7 20`). Bord : 20 `#` ; intérieur : `#` + 18 espaces + `#`.

**Nombre à garder : 7 lignes de dessin** (13 lignes de fichier au total). Pour passer à 30 colonnes, il faudrait retoucher les 7 lignes à la main ; au chapitre 2, une boucle fera le même travail en trois lignes, quelle que soit la taille.
