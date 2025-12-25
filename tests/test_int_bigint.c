#include "raccourcis.c"

void test_int_bigint_aux(int* nb_test, const long entree) {
    printf("Test %d... ", *nb_test);
    *nb_test = *nb_test + 1;

    bigint A = int_bigint(entree);

    bigint B;
    B.taille = 1;
    B.taille_reelle = 1;
    B.signe = (entree < 0);
    B.arr = malloc(sizeof(uint32_t) * 1);
    B.arr[0] = labs(entree);

    verif_bigint(A, B);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);
}

void test_int_bigint() {
    int ctr = 1;

    test_int_bigint_aux(&ctr, 0);
    test_int_bigint_aux(&ctr, 1);
    test_int_bigint_aux(&ctr, -1);
    test_int_bigint_aux(&ctr, 4);
    test_int_bigint_aux(&ctr, 100);
    test_int_bigint_aux(&ctr, -100);
    test_int_bigint_aux(&ctr, 16382);

    test_int_bigint_aux(&ctr, 2147483647);

    test_int_bigint_aux(&ctr, -2147483647);

    test_int_bigint_aux(&ctr, -0);
}