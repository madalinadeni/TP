// hs_utils.c
#include "hs_utils.h"

int estePar(int numar) {
    return numar % 2 == 0;
}

int esteImpar(int numar) {
    return numar % 2 != 0;
}

int esteNegativ(int numar) {
    return numar < 0;
}

int estePozitiv(int numar) {
    return numar > 0;
}
