#include <stdio.h>
#include "hs_utils.h"
/* 1. Implementati biblioteca descrisa succint sub numele de hs_utils (fisierele hs_utils.c si 
hs_utils.h) adaugând și alte funcții precum estePar, esteImpar, esteNegativ, estePozitiv. Testati 
biblioteca hs_utils */

int main() {
    int numere[] = { -9, 1, 2, 3, -8, 10 };
    int n = sizeof(numere) / sizeof(numere[0]);

    for (int i = 0; i < n; i++) {
        int numar = numere[i];
        printf("Numar: %d\n", numar);
        printf("  Este par: %s\n", estePar(numar) ? "Da" : "Nu");
        printf("  Este impar: %s\n", esteImpar(numar) ? "Da" : "Nu");
        printf("  Este negativ: %s\n", esteNegativ(numar) ? "Da" : "Nu");
        printf("  Este pozitiv: %s\n", estePozitiv(numar) ? "Da" : "Nu");
    }

    return 0;
}




