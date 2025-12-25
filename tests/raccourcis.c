#include "style.c"
#include "bigint.h"

#ifndef RACCOURCIS
#define RACCOURCIS

void verif_bigint(bigint A, bigint B) {
        if (A.taille != B.taille) {
        printf(
            "%sErreur, taille virtuelle incorrecte, obtenue %ld au lieu de %ld%s\n",
            RED, A.taille, B.taille, DEFAULT_STYLE
        );
        exit(1);
    }

    if (A.taille_reelle != B.taille_reelle) {
        printf(
            "%sErreur, taille réelle incorrecte, obtenue %ld au lieu de %ld%s\n",
            RED, A.taille_reelle, B.taille_reelle, DEFAULT_STYLE
        );
        exit(1);
    }

    if (A.signe != B.signe) {
        printf(
            "%sErreur, signe incorrecte, obtenue %d au lieu de %d%s\n",
            RED, A.signe, B.signe, DEFAULT_STYLE
        );
        exit(1);
    }

    for (size_t i = 0; i < A.taille; i++) {
        if (A.arr[i] != B.arr[i]) {
            printf(
                "%sErreur, valeur incorrecte, Bloc %ld vaut %d au lieu de %d%s",
                RED, i, A.arr[i], B.arr[i], DEFAULT_STYLE
            );
        }
    }
}

#endif