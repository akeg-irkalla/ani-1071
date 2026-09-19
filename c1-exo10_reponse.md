# Exo 10 — Les avertissements

`clang++ -std=c++17 -Wall -Wextra c1-exo10_main.cpp -o programme` :
```
c1-exo10_main.cpp:8:9: warning: unused variable 'inutile' [-Wunused-variable]
1 warning generated.
```
La commande **réussit** (code 0) : l'exécutable est créé et affiche `Bonjour`.

| | Avertissement (`warning`) | Erreur (`error`) |
|---|---|---|
| Arrête la compilation | **non** | **oui** |
| Exécutable produit | oui | non (`1 error generated`) |
| Le code est-il valide | oui, mais suspect | non, aucune traduction possible |

**Pourquoi l'avertissement existe.** Le C++ autorise des choses légales mais presque toujours des bugs (variable inutilisée, oubli, faute de frappe qui déclare une nouvelle variable). Interdire ces cas casserait du code ancien parfaitement valide ; les ignorer en silence laisserait passer des bugs. Le warning signale sans bloquer. On l'active avec `-Wall -Wextra` (pas activé par défaut) et on peut le durcir avec `-Werror` : essayé, la même ligne devient `error: unused variable 'inutile' [-Werror,-Wunused-variable]` et la compilation échoue.
