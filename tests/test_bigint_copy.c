#include "raccourcis.c"

void test_bigint_copy() {
    int ctr = 1;

    // Test
    printf("Test %d...", ctr++);

    bigint A = bigint_new();

    bigint B = bigint_copy(A);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);


    // Test

    printf("Test %d...", ctr++);

    A.taille = 4;
    A.taille_reelle = 100;
    A.arr = malloc(A.taille_reelle * sizeof(uint32_t));
    A.arr[0] = 1;
    A.arr[1] = 2;
    A.arr[2] = 3;
    A.arr[3] = 4;

    B = bigint_copy(A);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test

    printf("Test %d...", ctr++);

    A.taille = 4;
    A.taille_reelle = 4;
    A.arr = malloc(A.taille_reelle * sizeof(uint32_t));
    A.arr[0] = 1;
    A.arr[1] = 2;
    A.arr[2] = 3;
    A.arr[3] = 4;

    B = bigint_copy(A);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);
}