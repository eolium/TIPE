#include "raccourcis.c"

void test_bigint_new() {
    printf("Test %d... ", 1);

    bigint A = bigint_new();

    bigint B;
    B.taille = 0;
    B.taille_reelle = 1;
    B.signe = false;
    B.arr = calloc(sizeof(uint32_t), 1);

    verif_bigint(A, B);

    free(A.arr);
    free(B.arr);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);
}