# Démo 7 — Enchaîner deux programmes

Avec `parite` (Cf `c1-demo6_reponse.md`).

Unix :
```
echo 4 | ./parite && echo "pair"      # affiche : pair
echo 7 | ./parite && echo "pair"      # n'affiche rien (code 1)
```
Windows :
```
echo 4 | parite.exe & if %ERRORLEVEL%==0 echo pair
```
`&&` ne lance la commande de droite que si celle de gauche a rendu **0**. Le shell ne lit jamais ce que `parite` affiche : il lit uniquement son code de sortie. Un système de construction (make, CI) fait la même chose à grande échelle : compiler, puis tester si la compilation a réussi, puis livrer si les tests ont réussi.
