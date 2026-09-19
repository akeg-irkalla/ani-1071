# Démo 1 — Prouver qu'un exécutable ne dépend plus de sa source

```
clang++ bonjour.cpp -o bonjour
rm bonjour.cpp
./bonjour        # Bonjour   <- fonctionne toujours
```
1. Le compilateur a **fini** son travail : `bonjour` contient déjà du code machine complet pour `main`, le `.cpp` n'est lu qu'à la compilation, jamais à l'exécution.
2. Un exécutable n'est donc pas « le source en plus rapide » : c'est un autre objet, que le processeur peut lire seul.
3. Il ne dépend que des bibliothèques partagées du système (`ldd bonjour` liste `libc.so.6`, …), pas de son code source. Seul reste le *nom* du fichier (`strings bonjour` montre `bonjour.cpp`), comme métadonnée, jamais le contenu.
4. Le chemin inverse est perdu : noms de variables, commentaires et structure disparaissent à la traduction ; on ne retrouve que de l'assembleur (Cf `c1-demo9_reponse.md`).
5. Livrer un programme, c'est donc livrer le binaire sans le code : le client l'utilise, sans pouvoir le relire ni le modifier commodément.
