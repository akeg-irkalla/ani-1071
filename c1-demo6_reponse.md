# Démo 6 — Un programme qui échoue exprès

```cpp
#include <cstdio>

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 2;      // pas de nombre lisible
    }
    if (n % 2 == 0)
    {
        return 0;      // pair
    }
    return 1;          // impair
}
```
On teste `== 0` et non `== 1` : en C++, `-3 % 2` vaut `-1`, pas `1`.

```
$ for v in 4 7 0 -3 -8 abc; do echo $v | ./parite; echo "entrée=$v code=$?"; done
entrée=4   code=0
entrée=7   code=1
entrée=0   code=0
entrée=-3  code=1
entrée=-8  code=0
entrée=abc code=2
```
Le programme n'affiche rien : son seul résultat est son **code de sortie**, lu par celui qui l'a lancé. Lancer des entrées connues, comparer le code obtenu au code attendu : c'est le principe d'un banc de test.
