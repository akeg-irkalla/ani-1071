# Exo 4 — Le code de sortie (explication en trois lignes)

`./programme ; echo $?` affiche `3` (sous Windows : `echo %ERRORLEVEL%`).
1. Ce nombre est la seule chose qu'un outil qui enchaîne des programmes (make, script, intégration continue) lit ; il ne lit pas l'affichage.
2. Convention : `0` = tout va bien, tout autre nombre = échec, et sa valeur dit lequel.
3. Ainsi `A && B` ne lance B que si A a rendu 0 : c'est le principe d'un système de construction (Cf `c1-demo7_reponse.md`).
