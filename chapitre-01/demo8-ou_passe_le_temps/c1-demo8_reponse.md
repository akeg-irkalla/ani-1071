Ajouter cinq en-têtes multiplie la compilation par ≈ 5.
L'exécution ne bouge pas.

1 en-tête :
  - temps compilation : 0,077 s
  - temps exécution : 0,002 s

6 en-têtes :
  - temps compilation : 0,327 s
  - temps exécution : 0,002 s

Un programme se compile à chaque modification, alors qu'il s'exécute vite.
Sur un gros projet, chaque fichier source répète l'analyse des mêmes en-têtes.
On la réduit donc en incluant moins d'en-têtes, en ne recompilant que ce qui a changé, et en évitant qu'un en-tête en tire d'autres. Une exécution longue se paie une fois pour l'utilisateur ; une compilation lente se paie plusieurs fois par jour à ceux qui écrivent le code.
