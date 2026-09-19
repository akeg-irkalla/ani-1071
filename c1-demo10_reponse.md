# Démo 10 — Un programme sans bibliothèque

```cpp
int main() { return 7; }
```
`clang++ sept.cpp -o sept && ./sept ; echo $?` → `7`.

| | clang++ | g++ |
|---|---|---|
| `sept` (aucun `#include`) | 15888 octets | 15776 octets |
| `bonjour` (avec `printf`) | 16016 octets | 15968 octets |
| écart | 128 octets | 192 octets |
| fichier objet `sept.o` | 976 octets | |

**Ce que l'on constate.** Un programme de 24 caractères donne un exécutable de ≈ 16 Ko, presque de la même taille que celui qui affiche du texte. Notre code (`main`, 6 instructions) tient en quelques octets dans `sept.o` ; tout le reste a été ajouté **sans que je le demande**.

**Ajouté par qui.** Par la commande de liaison que `clang++` construit et confie à l'éditeur de liens `ld` (visible avec `clang++ -v`) : les fichiers de démarrage du système `Scrt1.o`, `crti.o`, `crtbeginS.o`, `crtendS.o`, `crtn.o`, puis les bibliothèques `-lstdc++ -lm -lgcc_s -lc`. `ldd sept` liste d'ailleurs `libstdc++`, `libm`, `libgcc_s` et `libc`, bien que le programme n'utilise rien.
Le vrai point d'entrée n'est pas `main` mais `_start` (dans `Scrt1.o`) : il prépare l'environnement, appelle `main`, puis transmet sa valeur de retour à `exit`. C'est ce qui transforme `return 7;` en code de sortie 7 (Cf `c1-exo4_reponse.md`).
Les 16 Ko sont surtout ce code de démarrage, les tables du format ELF et un alignement par pages de 4096 octets ; d'où l'écart minuscule avec `bonjour` (Cf `c1-demo9_reponse.md` pour ce que devient `printf`, `c1-exo7_reponse.md` pour ce qu'est un objet incomplet).
