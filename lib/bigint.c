#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "bigint.h"

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}


int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}


bigint bigint_new() {
    bigint out;

    out.signe = false;
    out.taille = 0;
    out.taille_reelle = 1;

    out.arr = calloc(sizeof(uint32_t), out.taille_reelle);

    return out;
}


void bigint_free(bigint A) {
    free(A.arr);
}


bigint int_bigint(const int n) {
    bigint A = bigint_new();

    A.signe = n < 0;
    A.taille = 1;
    A.arr[0] = (uint32_t) labs(n);

    return A;
}


uint32_t* array_copy(uint32_t* arr, size_t taille) {
    uint32_t* out = malloc(sizeof(uint32_t) * taille);
    for (size_t i = 0; i < taille; i++) {
        out[i] = arr[i];
    }
    return out;
}


bigint bigint_copy(bigint A) {
    bigint out;
    out.taille_reelle = A.taille_reelle;
    out.taille = A.taille;
    out.signe = A.signe;
    out.arr = array_copy(A.arr, A.taille);

    return out;
}

void bigint_print(bigint A) {
    if (A.signe) {
        printf("- ");
    } else {
        printf("+ ");
    }

    for (size_t i = 0; i < A.taille; i++) {
        printf("%u\t", A.arr[i]);
    }
    printf("\n");
}

int bigint_cmp_absolue(const bigint* A, const bigint* B) {
    if (A->taille > B->taille) {
        return 1;
    }
    if (A->taille < B->taille) {
        return -1;
    }

    for (int i = A->taille-1; i >= 0; i--) {
        if (A->arr[i] > B->arr[i]) {
            return 1;
        }
        if (A->arr[i] < B->arr[i]) {
            return -1;
        }
    }

    return 0;
}

int bigint_cmp(const bigint* A, const bigint* B) {
    // A<0 et B>0
    if (A->signe && !B->signe) {
        return -1;
    }

    // A>0 et B<0
    if (!A->signe && B->signe) {
        return 1;
    }


    // On calcule le plus grand en valeur absolue
    int cmp_absolue = bigint_cmp_absolue(A, B);

    // A>0 et B>0
    if (!A->signe && !B->signe) {
        // On le traite normalement
        return cmp_absolue;
    }

    // A<0 et B<0
    if (A->signe && B->signe) {
        // On inverse simplement l'ordre
        return -cmp_absolue;
    }

    // Cas absurde
    assert(0);
    return 0;
}


void bigint_optimize(bigint* A) {
    if (A->taille > 1) {
        size_t new_size = A->taille;
    
        while (new_size > 1 && A->arr[new_size -1] == 0) {
            new_size--;
        }
    
        if (new_size < A->taille) {
            A->taille = new_size;
        }
    }

    if (A->taille > 0 && A->taille * 4 <= A->taille_reelle) {
        uint32_t* new_arr = array_copy(A->arr, A->taille);
        free(A->arr);
        A->arr = new_arr;
        A->taille_reelle = A->taille;
    }
}


int bigint_taille_after_add(bigint A, bigint B) {
    int size_max = max(A.taille, B.taille);

    if (((uint64_t) A.arr[A.taille - 1] + (uint64_t) B.arr[B.taille - 1] + 1) >> 32 > 0) {
        size_max++;
    }

    return size_max;
}


/*void big_add(bigint* A, bigint B) {
    int size = add_size_taille(*A, B);

    if (size == A->taille) {

        uint64_t r = 0;

        for (int i = 0; i < size; i++) {
            uint64_t s = r;

            if (i < A->taille) {
                s += (uint64_t) A->arr[i];
            }
            if (i < B.taille) {
                s += (uint64_t) B.arr[i];
            }

            A->arr[i] = (uint32_t) s;
            r = s >> 32;
        }

        A->signe = false;
        A->taille = size;

    } else {

        uint32_t* arr = calloc(sizeof(uint32_t), size);
        uint64_t r = 0;

        for (int i = 0; i < size; i++) {
            uint64_t s = r;

            if (i < A->taille) {
                s += (uint64_t) A->arr[i];
            }
            if (i < B.taille) {
                s += (uint64_t) B.arr[i];
            }

            arr[i] = (uint32_t) s;
            r = s >> 32;
        }

        free(A->arr);

        A->signe = false;
        A->taille = size;
        A->arr = arr;

    }
}


bigint bigint_add(bigint A, bigint B) {
    bigint out = bigint_copy(A);
    big_add(&out, B);
    return out;
}


int mult_size_taille(bigint A, bigint B) {
    int size_max = A.taille + B.taille - 1;

    if (((uint64_t) A.arr[A.taille - 1] * (uint64_t) B.arr[B.taille - 1]) >> 32 > 0) {
        size_max++;
    }


    return size_max;
}

void bigint_lambda_shift(bigint* A, int shift) {
    for (int i = 0; i < A->taille-1; i++) {
        A->arr[i] = (A->arr[i] >> shift) + ((A->arr[i+1] % 2) << 31);
    }

    A->arr[A->taille-1] = A->arr[A->taille-1] >> shift;

    bigint_optimize(A);
}

void bigint_lambda_mult(bigint* A, const int lambda) {

    if (lambda < 0) {
        A->signe = !A->signe;
    }
    const uint64_t abs_lambda = abs(lambda);

    uint64_t r = 0;
    for (int i = 0; i < A->taille; i++) {
        uint64_t s = ((uint64_t) A->arr[i]) * abs_lambda + r;

        A->arr[i] = (uint32_t) s;

        r = s >> 32;
    }

    if (r > 0) {
        uint32_t* new_arr = malloc(sizeof(uint32_t) * (A->taille+1 + 1));

        for (int i = 0; i < A->taille; i++) {
            new_arr[i] = A->arr[i];
        }

        new_arr[A->taille] = (uint32_t) r;

        free(A->arr);
        A->arr = new_arr;
        A->taille = A->taille+1;
    }
}


bigint bigint_mult(bigint A, bigint B) {
    int size = mult_size_taille(A, B);
    int signe = A.signe ^ B.signe;

    uint32_t* arr = calloc(sizeof(uint32_t), size);

    for (int i = 0; i < A.taille; i++) {
        for (int j = 0; j < B.taille; j++) {
            int rang = i + j;
            uint64_t x = ((uint64_t) A.arr[i]) * ((uint64_t) B.arr[j]);
            uint64_t n = x + arr[rang];

            arr[rang] = (uint32_t) n;

            if (rang+1 < size) {
                arr[rang+1] = n >> 32;
            }
        }
    }

    bigint out;
    out.taille = size;
    out.signe = signe;
    out.arr = arr;

    return out;
}

*/