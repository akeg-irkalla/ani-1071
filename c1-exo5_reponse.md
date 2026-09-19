# Exo 5 — Deux fichiers, deux noms

```
clang++ c1-exo5_main.cpp -o essai_un
clang++ c1-exo5_main.cpp -o essai_deux
./essai_un    # Bonjour
./essai_deux  # Bonjour
```

Les deux exécutables fonctionnent et sont **identiques octet pour octet** : 16016 octets chacun, même `md5sum` (`0d1e67b8…`), `cmp` ne signale aucune différence.

**Conclusion.** Le nom du fichier source et le nom du programme n'ont aucun lien : `-o` décide seul du nom de l'exécutable (sans `-o`, le programme s'appelle `a.out`). Le nom du `.cpp` ne sert qu'à dire au compilateur *quoi traduire*. Le contenu de l'exécutable ne dépend que du contenu du source (et du compilateur), pas des noms de fichiers. Le nom `main` de la fonction, lui, est imposé (Cf exo7 / cours §C).
