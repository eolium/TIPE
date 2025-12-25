#ifndef BIGINT
#define BIGINT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

struct bigint_s {
    bool signe;
    size_t taille;
    size_t taille_reelle;
    uint32_t* arr;
};

typedef struct bigint_s bigint;

bigint bigint_new(); // CORRECTE

bigint int_bigint(const int n); // CORRECTE

void bigint_free(bigint A); // ADMISE

bigint bigint_copy(bigint A); // CORRECTE

void bigint_print(bigint A); // ADMISE

int bigint_cmp(const bigint* A, const bigint* B); // CORRECTE

void bigint_optimize(bigint* A);

bigint bigint_add(bigint A, bigint B); // DONE

void big_add(bigint* A, bigint B); // DONE

bigint bigint_mult(bigint A, bigint B); // DONE

void big_lambda_mult(bigint A, int lambda); // DONE

void bigint_lambda_mult(bigint* A, int lambda);

void bigint_lambda_div(bigint* A, int lambda);

void bigint_lambda_shift(bigint* A, int shift);

// TODO
bigint bigint_div(bigint A, bigint B);

// TODO
bigint bigint_mod(bigint A, bigint B);

// TODO
bigint bigint_pow(bigint A, bigint B);

#endif