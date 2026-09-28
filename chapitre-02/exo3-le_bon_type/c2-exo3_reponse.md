Pour chacune des valeurs suivantes, choisissez le type de base le plus adapté et justifiez par la taille et la plage : 
 Puis dites, pour chacun, une opération que le type refuse.

 Choix des types de base

1. Âge : unsigned char. Taille 1 octet, plage 0 à 255. Un âge est un petit entier positif.
   Refusé : une valeur négative.

2. Nombre d'habitants de la Terre : long long. Taille 8 octets, plage environ ±9,22 × 10^18. Environ 8,2 milliards, ce qui dépasse int (2 147 483 647) et unsigned int (4 294 967 295).
   Refusé : une partie décimale.

3. Température en degrés : double. Taille 8 octets, environ 15 chiffres significatifs. Elle peut être négative et décimale.
   Refusé : l'opérateur modulo %.

4. Caractère tapé au clavier : char. Taille 1 octet, plage -128 à 127 (ASCII : 0 à 127).
   Refusé : un caractère hors ASCII.

5. Porte ouverte ou non : bool. Taille 1 octet, valeurs true ou false. Il n'y a que deux états.
   Refusé : un troisième état (« entrouverte »). Toute valeur non nulle devient true, et porte++ est interdit.

6. Pixels d'une image 4000 × 3000 : int. Taille 4 octets, plage ±2 147 483 647. 4000 × 3000 = 12 000 000, largement sous la limite.
   Refusé : un nombre non entier (0,5 pixel est tronqué) et tout dépassement de 2 147 483 647 (débordement).

7. Solde bancaire en francs CFA : long long. Taille 8 octets, plage ±9,22 × 10^18. Le franc CFA est entier, et le solde peut être négatif.
   Refusé : les fractions de franc.
