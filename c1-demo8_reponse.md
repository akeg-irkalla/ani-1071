# Démo 8 — Où passe le temps

clang++ 18.1.3, moyenne de 12 compilations et de 30 exécutions.

| Programme | Compilation | Exécution |
|---|---|---|
| bonjour.cpp | ≈ 56 ms | ≈ 1,0 ms |
| + 5 en-têtes (`iostream vector string map algorithm`) | ≈ 291 ms | ≈ 1,2 ms |

Ajouter cinq en-têtes multiplie la compilation par ≈ 5 (le préprocesseur produit 51 968 lignes contre 1 069) ; l'exécution ne bouge pas : elle est déjà au minimum, qui est le simple démarrage du programme.

**Pourquoi, sur un projet réel, on cherche surtout à réduire la première.** Un programme se compile à chaque modification, et à chaque fois pour chaque développeur, alors qu'il s'exécute vite et souvent sur un travail utile. Sur un gros projet, chaque fichier source répète l'analyse des mêmes en-têtes (des dizaines de milliers de lignes recopiées dans chacun) : la compilation devient le temps mort de chaque essai, multiplié par le nombre de fichiers et de personnes. On la réduit donc en incluant moins d'en-têtes, en ne recompilant que ce qui a changé, et en évitant qu'un en-tête en tire d'autres. Une exécution un peu longue se paie une fois pour l'utilisateur ; une compilation lente se paie des centaines de fois par jour à ceux qui écrivent le code. (Cf `c1-demo5_reponse.md` pour le détail par étape.)
