# Démo 3 — Le même source, deux compilateurs

Comparés : **clang++ 18.1.3** et **g++ 13.3.0** (Ubuntu 24.04, x86-64), sur `bonjour.cpp`.

| | clang++ | g++ |
|---|---|---|
| Exécutable | 16016 octets | 15968 octets |
| Fichier objet `.o` | 1264 octets | 1496 octets |
| Assembleur `-S` | 37 lignes | 45 lignes |
| Sortie | `Bonjour` | `Bonjour` (même `md5sum`) |

`cmp` confirme que les deux exécutables sont **différents** octet à octet.

Exemple concret de différence : g++ remplace `printf("Bonjour\n")` par un appel à `puts` (plus simple, même effet visible) ; clang à ce niveau garde `printf` (Cf `c1-demo9_reponse.md`).

**Conclusion.** Le langage garantit le **comportement observable** : même texte affiché, même code de sortie. Il ne garantit **pas** la façon d'y arriver : taille, instructions choisies, fonction réellement appelée, disposition du binaire, vitesse. Deux implémentations du même langage peuvent produire des programmes différents tant que ce que l'on observe est identique.
