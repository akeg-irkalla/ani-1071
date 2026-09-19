# Démo 5 — Mesurer le coût des étapes

clang++ 18.1.3, moyenne de 12 exécutions de chaque commande, temps en ms. « dix.cpp » = `bonjour` + 10 en-têtes standard (`iostream vector string map set algorithm sstream fstream memory functional`).

| Commande | bonjour.cpp | dix.cpp |
|---|---|---|
| `clang++ -E` | 12 | 51 |
| `clang++ -c` | 15 | 332 |
| compilation complète | 59 | 399 |
| lignes après préprocesseur | 1 069 | 69 720 |

Les mesures sont **cumulatives** (`-c` inclut `-E`, la compilation complète inclut `-c`). Coût propre de chaque étape, par soustraction :

| Étape | bonjour | dix |
|---|---|---|
| Préprocesseur | 12 | 51 |
| Compilation + assemblage | 3 | 281 |
| Édition de liens | 44 | 67 |

**Quelle étape domine.** Sur un programme minuscule, c'est l'**édition de liens** (≈ 44 ms sur 59) : un coût presque fixe, payé quel que soit le programme. Dès qu'on inclut de gros en-têtes, c'est la **compilation** (≈ 281 ms sur 399), parce que le compilateur doit analyser 69 720 lignes au lieu de 1 069. Le préprocesseur lui-même coûte peu, mais c'est lui qui fabrique cette masse de texte à analyser (Cf `c1-exo6_reponse.md`, `c1-demo8_reponse.md`).
