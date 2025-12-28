# Nouveau Projet : Construction d'une librairie de Bigint et de Matrices


Le but de ce projet de dev est de coder une librairie C pour utiliser des entiers de taille variable (et pas limités à 32/64 bits), comme en python. Ensuite, le véritable objectif est de coder une librairie de matrices d'entiers en C, optimisé pour le calcul de puissances de matrices, avec un essai d'utilisation pour calculer la suite de Fibonnacci.

Le projet se décompose donc en 2 parties :

- bigint : une librairie d'entiers à tailles variables
- matrix : une librairie de matrices d'entiers à tailles variables, de dimensions souhaitées

Le dépôt git contient 2 dossiers :

- lib : le code
- tests : un ensemble de tests (entre 3 et 10) pour (quasiment) chaque fonction. Toutes les fonctions testées sont notées "CORRECTE" dans le header des librairies, sinon "ADMISE" (pour celles triviales).


Pour réaliser ce projet, je vais coder au moins une fonction par jour, sans les (beaucoup) optimiser pour l'instant.

Une fois que toutes les fonctions seront réalisées, je vais étudier différents algorithmes pour optimiser le calcul :

- bigin_mul : algo de Karatsuba
- bigint_pow : optimisation des variables intermédiaires dans l'exponientation rapide
- matrix_pow : algorithme de Strassen
    -> Structure des matrices par arbre.
- division : algorithme de division binomiale


Complexités de calcul, pour $n$ la taille des entiers :

- big_add : $O(n)$
- big_mult : $O(n^2)$ (une fois opti $O(n^{1.5})$ )
- big_div/reste : $O(n)$ avec $n$ la taille du dividende
- big_pow : $O(n^2 log(p))$


J'ai trouvé un algo de division en $O(n)$ !!!!


Pour l'instant, le problème qui m'embête, c'est de réussir à convertir en chaîne de caractère ou au moins à rendre printable un bigint, pour l'instant la méthode la plus simple que j'ai en tête est l'évaluation d'un polynôme en $2^{32}$, ce qui donnerait $n$ addition, et $n$ multiplications par $2^{32}$, chacune en $O(n)$, donc au total en $O(n^2)$, pas fifou...
