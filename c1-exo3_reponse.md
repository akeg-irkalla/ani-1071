# Exo 3 — Lire trois erreurs

Compilateur : clang++ 18.1.3 (g++ 13.3.0 en note). Base : `c1-exo3_main.cpp` (sain, `printf` ligne 7).
Commande : `clang++ c1-exo3_main.cpp -o programme`

| # | Faute introduite | Message exact | Ligne signalée | Ligne réellement fautive | Étape qui parle |
|---|---|---|---|---|---|
| 1 | retirer le `;` après `printf("Bonjour\n")` | `c1-exo3_main.cpp:7:24: error: expected ';' after expression` | 7 (colonne 24 = fin de ligne) | 7 | 2 — compilation (analyse syntaxique) |
| 2 | `Printf` au lieu de `printf` | `c1-exo3_main.cpp:7:5: error: use of undeclared identifier 'Printf'; did you mean 'printf'?` | 7 | 7 | 2 — compilation (nom inconnu) |
| 3 | retirer `#include <cstdio>` | `c1-exo3_main.cpp:6:5: error: use of undeclared identifier 'printf'` | 6 (l'include a disparu, les lignes remontent) | la ligne 3 d'origine : celle qui **manque** | 2 — compilation, pas le préprocesseur |

Points à retenir :
- **Faute 1.** clang montre la bonne ligne. g++ écrit `expected ';' before 'return'` : il a compris qu'il manquait quelque chose en voyant le mot **suivant**. La ligne signalée est celle où le compilateur *s'aperçoit*, pas forcément celle où l'on a fauté.
- **Faute 2.** `printf` et `Printf` sont deux identifiants distincts : le C++ distingue majuscules et minuscules. clang propose la correction (« did you mean »).
- **Faute 3.** Le préprocesseur n'a rien signalé : une ligne `#include` absente n'est pas une erreur pour lui, il n'a simplement rien à recopier. C'est le compilateur qui découvre ensuite que `printf` n'est pas déclaré. Le préprocesseur ne se plaindrait que d'un `#include` dont le **fichier** est introuvable (`fatal error: 'xxx' file not found`). g++ va plus loin : `'printf' is defined in header '<cstdio>'; did you forget to '#include <cstdio>'?`.
- Aucune des trois n'a produit d'exécutable : erreur = la chaîne s'arrête (Cf `c1-exo10_reponse.md` pour la différence avec un avertissement).
