# Exo 8 — L'erreur qui ne vient pas du compilateur

Outils : clang++ 18.1.3 (g++ 13.3.0 en note).

**Avec `-c`** : `clang++ -c c1-exo8_main.cpp` **réussit** (aucun message, `c1-exo8_main.o` créé). `nm -C` montre `U calculer()` : référence non résolue, mise de côté.
**Sans `-c`** :
```
/usr/bin/ld: c1-exo8_main.cpp:(.text+0x10): undefined reference to `calculer()'
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
```
(g++ : même ligne `ld`, puis `collect2: error: ld returned 1 exit status`).

**Pourquoi la première réussit.** `int calculer();` est une **déclaration** : une promesse « cette fonction existe, elle rend un `int` ». Le compilateur ne traduit qu'un fichier à la fois : il vérifie que l'appel respecte la promesse (types corrects) et laisse un trou à remplir. Il n'a aucun moyen de savoir si la définition existe dans un autre fichier.

**Pourquoi la seconde échoue, et qui parle.** Sans `-c`, la chaîne va jusqu'à l'étape 4 : l'éditeur de liens `ld` cherche la **définition** de `calculer()` dans tous les objets et bibliothèques, n'en trouve aucune, et s'arrête. Avec `-c` : le compilateur (étape 2) ; sans `-c` : `ld` (étape 4).
Signe distinctif : le message de `ld` n'a ni colonne, ni flèche `^`, ni ligne du source : il donne un décalage dans l'objet (`.text+0x10`) et le nom du symbole. Il ne ressemble en rien à une erreur de l'étape 2.
