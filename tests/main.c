#include <stdio.h>
#include "style.c"

#include "test_bigint_new.c"
#include "test_int_bigint.c"
#include "test_bigint_copy.c"
#include "test_bigint_cmp.c"
#include "test_bigint_optimize.c"
#include "test_bigint_taille_after_add.c"

int main() {
    printf("Lancement des tests\n\n");

    printf("Test de la fonction bigint_new()\n");
    test_bigint_new();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);



    printf("Test de la fonction int_bigint()\n");
    test_int_bigint();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);



    printf("Test de la fonction bigint_copy()\n");
    test_bigint_copy();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);



    printf("Test de la fonction bigint_cmp()\n");
    test_bigint_cmp();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);



    printf("Test de la fonction bigint_optimize()\n");
    test_bigint_optimize();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);



    printf("Test de la fonction bigint_taille_after_add()\n");
    test_bigint_taille_after_add();
    printf("%sTests passés avec succès !%s\n\n\n", GREEN, DEFAULT_STYLE);


    printf("Tous les tests sont passés avec succès !\n");
}