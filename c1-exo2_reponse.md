# Exo 2 — Sans passage à la ligne (explication)

Sans `\n`, la sortie est `KilyanYaounde` : les deux textes sont collés sur **une seule ligne**, sans espace, et rien ne termine la ligne.

Après le programme, le shell réaffiche son invite juste à la suite : `KilyanYaounde$ `. Ce n'est pas un bug : `printf` écrit exactement les caractères qu'on lui donne, ni plus ni moins. Le passage à la ligne n'est pas « automatique » : c'est un caractère (`\n`, un seul) qu'il faut écrire soi-même. Le shell, lui, ne fait qu'afficher son invite à l'endroit où se trouve le curseur.
