#include "raccourcis.c"

void test_bigint_cmp() {
    int ctr = 1;

    // Test
    printf("Test %d...", ctr++);


    bigint A = bigint_new();
    bigint B = bigint_copy(A);

    if (bigint_cmp(&A, &B) != 0) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), 0, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(0);
    B = int_bigint(1);

    if (bigint_cmp(&A, &B) != -1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), -1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(-100);
    B = int_bigint(1);

    if (bigint_cmp(&A, &B) != -1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), -1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(-100);
    B = int_bigint(1000);

    if (bigint_cmp(&A, &B) != -1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), -1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(1000);
    B = int_bigint(-100);

    if (bigint_cmp(&A, &B) != 1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), 1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(-100);
    B = int_bigint(-100);

    if (bigint_cmp(&A, &B) != 0) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), 0, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 10;
    A.taille = 5;
    A.signe = false;
    A.arr = malloc(5 * sizeof(uint32_t));
    A.arr[0] = 5;
    A.arr[1] = 4;
    A.arr[2] = 3;
    A.arr[3] = 2;
    A.arr[4] = 1;

    B = bigint_copy(A);

    if (bigint_cmp(&A, &B) != 0) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), 0, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 10;
    A.taille = 5;
    A.signe = false;
    A.arr = malloc(5 * sizeof(uint32_t));
    A.arr[0] = 5;
    A.arr[1] = 4;
    A.arr[2] = 3;
    A.arr[3] = 2;
    A.arr[4] = 1;

    B.taille_reelle = 10;
    B.taille = 6;
    B.signe = false;
    B.arr = malloc(6 * sizeof(uint32_t));
    B.arr[0] = 5;
    B.arr[1] = 4;
    B.arr[2] = 3;
    B.arr[3] = 2;
    B.arr[4] = 1;
    B.arr[5] = 1;

    if (bigint_cmp(&A, &B) != -1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), -1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 10;
    A.taille = 5;
    A.signe = false;
    A.arr = malloc(5 * sizeof(uint32_t));
    A.arr[0] = 5;
    A.arr[1] = 4;
    A.arr[2] = 3;
    A.arr[3] = 2;
    A.arr[4] = 1;

    B.taille_reelle = 10;
    B.taille = 5;
    B.signe = false;
    B.arr = malloc(6 * sizeof(uint32_t));
    B.arr[0] = 4;
    B.arr[1] = 4;
    B.arr[2] = 3;
    B.arr[3] = 2;
    B.arr[4] = 1;

    if (bigint_cmp(&A, &B) != 1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), 1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 10;
    A.taille = 5;
    A.signe = false;
    A.arr = malloc(5 * sizeof(uint32_t));
    A.arr[0] = 10000;
    A.arr[1] = 10000;
    A.arr[2] = 10000;
    A.arr[3] = 10000;
    A.arr[4] = 2;

    B.taille_reelle = 10;
    B.taille = 5;
    B.signe = false;
    B.arr = malloc(10 * sizeof(uint32_t));
    B.arr[0] = 0;
    B.arr[1] = 0;
    B.arr[2] = 0;
    B.arr[3] = 0;
    B.arr[4] = 4;

    if (bigint_cmp(&A, &B) != -1) {
        printf(
            "%sErreur, obtenue : %d au lieu de %d%s\n",
            RED, bigint_cmp(&A, &B), -1, DEFAULT_STYLE
        );
    }

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);
}