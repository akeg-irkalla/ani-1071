# Exo 7 — S'arrêter avant l'édition de liens

Outil : clang++ 18.1.3. `clang++ -c bonjour.cpp` produit `bonjour.o` (1264 octets), **pas** d'exécutable.

```
$ file bonjour.o
bonjour.o: ELF 64-bit LSB relocatable, x86-64, ... not stripped
$ ./bonjour.o
Permission denied                 (le fichier n'a pas le droit d'exécution)
$ chmod +x bonjour.o ; ./bonjour.o
cannot execute binary file: Exec format error
```

**Pourquoi.** Un fichier objet est du code machine **incomplet**. `nm bonjour.o` montre :
```
0000000000000000 T main      <- défini ici, à l'adresse 0 (adresse provisoire)
                 U printf    <- U = Undefined : référence non résolue
```
`main` est traduite, mais `printf` n'existe pas dans ce fichier, et il manque le point d'entrée réel du programme (`_start`, fourni par le système). Le noyau reconnaît le format « relocatable » (à assembler avec d'autres pièces) et refuse de le lancer. Il faut l'édition de liens pour recoller les pièces (Cf `c1-exo8_reponse.md` et `c1-demo10_reponse.md`).
