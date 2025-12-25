#include "raccourcis.c"

void test_bigint_optimize() {
    int ctr = 1;

    // Test
    printf("Test %d...", ctr++);

    bigint A = bigint_new();
    bigint B = bigint_copy(A);

    bigint_optimize(&B);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(0);
    B = bigint_copy(A);

    bigint_optimize(&B);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A = int_bigint(16542);
    B = bigint_copy(A);

    bigint_optimize(&B);

    verif_bigint(B, A);

    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 4;
    A.taille = 4;
    A.arr = malloc(4 * sizeof(uint32_t));
    A.arr[0] = 0;
    A.arr[1] = 0;
    A.arr[2] = 1;
    A.arr[3] = 0;

    bigint_optimize(&A);

    B.taille_reelle = 4;
    B.taille = 3;
    B.arr = malloc(4 * sizeof(uint32_t));
    B.arr[0] = 0;
    B.arr[1] = 0;
    B.arr[2] = 1;
    B.arr[3] = 0;

    verif_bigint(A, B);

    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 4;
    A.taille = 4;
    A.arr = malloc(4 * sizeof(uint32_t));
    A.arr[0] = 0;
    A.arr[1] = 1;
    A.arr[2] = 0;
    A.arr[3] = 0;

    bigint_optimize(&A);

    B.taille_reelle = 4;
    B.taille = 2;
    B.arr = malloc(4 * sizeof(uint32_t));
    B.arr[0] = 0;
    B.arr[1] = 1;
    B.arr[2] = 0;
    B.arr[3] = 0;

    verif_bigint(A, B);

    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 4;
    A.taille = 1;
    A.arr = malloc(4 * sizeof(uint32_t));
    A.arr[0] = 1;
    A.arr[1] = 0;
    A.arr[2] = 0;
    A.arr[3] = 0;

    bigint_optimize(&A);

    B.taille_reelle = 1;
    B.taille = 1;
    B.arr = malloc(4 * sizeof(uint32_t));
    B.arr[0] = 1;
    B.arr[1] = 0;
    B.arr[2] = 0;
    B.arr[3] = 0;

    verif_bigint(A, B);
    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 8;
    A.taille = 2;
    A.arr = calloc(sizeof(uint32_t), 8);
    A.arr[1] = 1;

    bigint_optimize(&A);

    B.taille_reelle = 2;
    B.taille = 2;
    B.arr = calloc(sizeof(uint32_t), 2);
    B.arr[0] = 0;
    B.arr[1] = 1;


    verif_bigint(A, B);
    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 8;
    A.taille = 1;
    A.arr = calloc(sizeof(uint32_t), 8);
    A.arr[0] = 1;

    bigint_optimize(&A);

    B.taille_reelle = 1;
    B.taille = 1;
    B.arr = calloc(sizeof(uint32_t), 1);
    B.arr[0] = 1;


    verif_bigint(A, B);
    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 8;
    A.taille = 1;
    A.arr = calloc(sizeof(uint32_t), 8);
    A.arr[0] = 0;

    bigint_optimize(&A);

    B.taille_reelle = 1;
    B.taille = 1;
    B.arr = calloc(sizeof(uint32_t), 1);
    B.arr[0] = 0;


    verif_bigint(A, B);
    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);



    // Test
    printf("Test %d...", ctr++);

    A.taille_reelle = 8;
    A.taille = 0;
    A.arr = calloc(sizeof(uint32_t), 8);

    bigint_optimize(&A);

    B.taille_reelle = 8;
    B.taille = 0;
    B.arr = calloc(sizeof(uint32_t), 8);


    verif_bigint(A, B);
    
    bigint_free(A);
    bigint_free(B);

    printf("%sOK%s\n", GREEN, DEFAULT_STYLE);
}