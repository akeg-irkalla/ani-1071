# Exo 11 — Le plus petit programme possible

```cpp
int main(){}
```
**12 caractères** (fichier de 12 octets, sans retour à la ligne final). Il compile sans avertissement (`-std=c++17 -Wall`, clang et g++), s'exécute, n'affiche rien et rend 0.

**Rien ne peut être retiré.** J'ai supprimé chaque caractère, un par un (12 essais) : les 12 versions échouent, avec clang **et** g++ : `nt main(){}`, `intmain(){}` (mots collés), `int ain(){}`, `int main){}`, `int main({}`, `int main()}`, `int main(){`…
Cas piège : supprimer tout `int ` (`main(){}`) : clang refuse (`a type specifier is required`), g++ accepte avec un simple warning (`ISO C++ forbids declaration of 'main' with no type`), ce qui viole « sans avertissement ». Le type de retour est donc obligatoire.
Pas de `return 0;` : pour `main` uniquement, le langage dit que sortir de la fonction sans `return` vaut `return 0;`. Pas de `#include` : on n'utilise rien.
