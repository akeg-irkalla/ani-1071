# Démo 4 — Ce que coûte l'optimisation

clang++ 18.1.3. Temps : moyenne de 12 compilations et de 30 lancements. `million.cpp` :
```cpp
#include <cstdio>
int main()
{
    long long somme = 0;
    for (int i = 0; i < 1000000; i++) { somme += i; }
    printf("%lld\n", somme);   // 499999500000
    return 0;
}
```
| Programme | Option | Taille exécutable | Temps de compilation | Temps d'exécution |
|---|---|---|---|---|
| bonjour | (aucune) | 16016 o | ≈ 69 ms | ≈ 1,1 ms |
| bonjour | `-O2` | 16016 o | ≈ 64 ms | ≈ 1,1 ms |
| million | (aucune) | 16016 o | ≈ 58 ms | ≈ 3,0 ms |
| million | `-O2` | 16016 o | ≈ 62 ms | ≈ 1,1 ms |

**Ce que `-O2` a changé.** Dans l'assembleur du programme « million », la boucle d'un million de tours a **disparu** : le compilateur a calculé le total lui-même et écrit la constante (`movabsq $499999500000, %rsi`). L'exécution retombe de ≈ 3 ms à ≈ 1,1 ms, c'est-à-dire au simple coût de démarrage d'un programme (le même que « bonjour »).
**Ce qu'elle n'a pas changé.** Le résultat affiché (identique) ; la taille (16016 octets partout : elle est dominée par le code de démarrage et l'alignement, pas par le nôtre) ; le temps de compilation, qui reste dans le bruit de mesure (± 10 ms) sur ces programmes minuscules, où l'essentiel est le lancement de clang et l'édition de liens. Le coût de `-O2` ne se voit que sur de gros programmes.
