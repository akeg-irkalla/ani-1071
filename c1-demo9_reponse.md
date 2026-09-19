# Démo 9 — Regarder l'assembleur

`clang++ -S bonjour.cpp -o bonjour.s` (clang++ 18.1.3). Extrait utile (directives retirées) :

```
main:                                   # @main
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    $0, -4(%rbp)
    leaq    .L.str(%rip), %rdi          # adresse du texte "Bonjour\n"
    movb    $0, %al
    callq   printf@PLT                  # <- l'appel à printf
    xorl    %eax, %eax                  # <- la valeur de retour : 0
    addq    $16, %rsp
    popq    %rbp
    retq
```
Les trois éléments demandés :
- **L'étiquette `main`** : `main:` — c'est le nom que l'éditeur de liens cherche (Cf cours §C, exo7).
- **L'appel à `printf`** : `callq printf@PLT`. Avec **g++**, la ligne est `call puts@PLT` : g++ a remplacé `printf("Bonjour\n")` par `puts`, équivalent ici ; avec `-fno-builtin` il redevient `call printf@PLT` (Cf `c1-demo3_reponse.md`).
- **La valeur de retour** : `xorl %eax, %eax` (mettre `eax` à 0 ; g++ écrit `movl $0, %eax`). Par convention, une fonction rend son résultat dans le registre `eax` : ce `0` est celui de `return 0;`.
