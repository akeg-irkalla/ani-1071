$ file bonjour.o
bonjour.o: ELF 64-bit LSB relocatable, x86-64, ... not stripped
$ ./bonjour.o
Permission denied                 (le fichier n'a pas le droit d'exécution)
$ chmod +x bonjour.o ; ./bonjour.o
cannot execute binary file: Exec format error
```
