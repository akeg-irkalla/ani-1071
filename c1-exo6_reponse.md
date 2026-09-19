# Exo 6 — Voir le préprocesseur à l'œuvre

Outils : clang++ 18.1.3 et g++ 13.3.0 (Ubuntu 24.04). Source : `bonjour.cpp`, les six lignes du cours.

```
clang++ -E bonjour.cpp > sortie.txt ; wc -l sortie.txt
```

| Compilateur | Lignes de `sortie.txt` |
|---|---|
| clang++ | **1069** |
| g++ | **1056** |
| lignes écrites | 6 |

**Explication de l'écart.** Le préprocesseur ne comprend pas le C++ : il déplace du texte. La ligne `#include <cstdio>` est remplacée par le contenu **complet** du fichier `cstdio`, qui lui-même inclut d'autres fichiers (`stdio.h`, puis `features.h`, `bits/types.h`, …) : 37 fichiers d'en-tête distincts traversés avec clang. Seules les 5 dernières lignes de la sortie (`int main()` … `}`) sont les miennes ; tout ce qui précède vient de l'include.

Dans ces ~1064 lignes : des lignes vides (478), des marqueurs `# 12 "fichier"` qui disent au compilateur d'où vient chaque bout de texte (151), et les vraies déclarations, dont `extern int printf (const char *__restrict __format, ...);` (ligne 597) : **c'est cette ligne qui apprend au compilateur ce qu'est `printf`** (Cf exo3, faute 3). Avec `-P` (sans marqueurs), il reste 443 lignes.

L'écart clang / g++ (1069 contre 1056) ne vient que de la présentation des marqueurs : le fond est le même, et ne dépend pas du compilateur.
