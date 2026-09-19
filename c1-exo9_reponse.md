# Exo 9 — Le massacre du point-virgule

Fait sur une **copie** (`cp c1-exo9_main.cpp copie.cpp && sed -i 's/;//g' copie.cpp`). Outil : clang++ 18.1.3.

1. Tous les `;` supprimés → `3 errors generated` :
   - `copie.cpp:7:24: error: expected ';' after expression`
   - `copie.cpp:8:26: error: expected ';' after expression`
   - `copie.cpp:9:13: error: expected ';' after return statement`
2. Je remets **un seul** `;` (celui de la première erreur, ligne 7) → **2 messages**. Un seul a disparu : les deux autres étaient des fautes indépendantes (un `;` manquant par ligne).
3. g++ 13.3.0 : il n'affiche que la première (`expected ';' before 'printf'`), puis la suivante après correction.

**Ce que l'expérience montre.** Sur un programme aussi court, chaque faute est séparée : clang « imagine » le `;` manquant et poursuit, donc peu d'effet en cascade. La cascade apparaît quand la faute **désoriente** l'analyse. Exemple mesuré : retirer l'accolade `{` après `int main()` (avec 3 `printf`) donne **5 erreurs** pour **une** seule cause ; remise de l'accolade, 0 erreur. D'où la méthode : lire la première, corriger, recompiler.
Leçon de la consigne : on fait ce genre d'essai sur une copie, jamais sur l'unique exemplaire d'un travail.
