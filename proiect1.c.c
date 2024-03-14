#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Subiect 8.1: Se citesc de la tastatură două numere n și m, n>=m. Pe urmă se citesc două matrici pătratice de 
dimensiuni n, respectiv m, conținând numere întregi. Afișați toate pozitiile unde a doua matrice apare în prima 
matrice. Afișarea se va face pe ecran sub forma unor perechi de forma (linie, coloană). Dacă a doua matrice nu 
apare în prima matrice, se va afișa textul “Nu apare”.
Spre exemplu dacă se introduce:
5 3
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1
0 1 1
1 0 1
0 1 1
se va afișa pe ecran:
(0,1) (2,1) */

/*#define MAX 10

void citire_matrice(int n, int matrice[MAX][MAX]) {
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
}

void pozitie_matrice(int n, int a[][MAX], int m, int b[][MAX]) {
    int found = 0; 

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            int potrivire = 1;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[i + k][j + l] != b[k][l]) {
                        potrivire = 0;
                        break;
                    }
                }
                if (!potrivire) {
                    break;
                }
            }
            if (potrivire) {
                found = 1;
                printf("(%d,%d) ", i, j);
            }
        }
    }

    if (!found) {
        printf("Nu apare");
    }
    printf("\n");
}

int main() {
    int n, m;
    int matriceA[MAX][MAX];
    int matriceB[MAX][MAX];
    
    printf("Introduceti dimensiunea matricei mare: ");
    scanf("%d", &n);
    
    printf("Introduceti dimensiunea matricei mici: ");
    scanf("%d", &m);

    if (n < m ||  n < 3) {
        printf("Dimensiunile matricilor trebuie sa fie intre 3 si %d.\n", MAX);
    }


    citire_matrice(n, matriceA);
    citire_matrice(m, matriceB);

    pozitie_matrice(n, matriceA, m, matriceB);

    return 0;
}*/

/* Subiect 8.2: Se citesc de la tastatură un număr n și o matrice pătratică de dimensiune n conținând litere din 
alfabet. Pe urmă se citește de la tastatură un cuvânt. Verificați dacă respectivul cuvânt se poate construi 
parcurgând literele matricii pe verticală în sus sau în jos sau pe orizontală spre stânga sau spre dreapta. Afișați 
toate pozițiile de unde trebuie începută parcurgerea, precum și sensul de parcurgere necesar pentru a construi 
cuvântul.
Spre exemplu, dacă de la tastatură se introduce:
5
e r e m a
h e r e b
b m e r e
b a m e r
a e m r e
mere
pe ecran se va afișa:
De la linia 0 coloana 3 spre stânga.
De la linia 0 coloana 3 în jos.
De la linia 2 coloana 1 spre dreapta.
De la linia 3 coloana 2 în sus.
Nu are importanță ordinea în care sunt afișate soluțiile găsite. Dacă nu există soluție, se afișează “Nu există 
soluție”. */
/* !!!!
#define MAX 10
#define MAX_WORD 20

void citire_matrice(int n, int matrice[MAX][MAX]) {
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
}

void cautare_cuvant(int n, char matrice[MAX][MAX], char cuvant[]) {
    int found = 0; 

    printf("Pozițiile și sensurile de parcurgere necesare pentru construirea cuvântului:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrice[i][j] == cuvant[0]) {
                int k, l;
                for (k = 0, l = i; k < strlen(cuvant) && l >= 0; k++, l--) {
                    if (matrice[l][j] != cuvant[k]) {
                        break;
                    }
                }
                if (k == strlen(cuvant)) {
                    found = 1;
                    printf("De la linia %d coloana %d spre sus.\n", i, j);
                }

                for (k = 0, l = i; k < strlen(cuvant) && l < n; k++, l++) {
                    if (matrice[l][j] != cuvant[k]) {
                        break;
                    }
                }
                if (k == strlen(cuvant)) {
                    found = 1;
                    printf("De la linia %d coloana %d spre jos.\n", i, j);
                }

                for (k = 0, l = j; k < strlen(cuvant) && l >= 0; k++, l--) {
                    if (matrice[i][l] != cuvant[k]) {
                        break;
                    }
                }
                if (k == strlen(cuvant)) {
                    found = 1;
                    printf("De la linia %d coloana %d spre stanga.\n", i, j);
                }
                
                for (k = 0, l = j; k < strlen(cuvant) && l < n; k++, l++) {
                    if (matrice[i][l] != cuvant[k]) {
                        break;
                    }
                }
                if (k == strlen(cuvant)) {
                    found = 1;
                    printf("De la linia %d coloana %d spre dreapta.\n", i, j);
                }
            }
        }
    }

    if (!found) {
        printf("Nu există soluție.\n");
    }
}

int main() {
    int n;
    char matrice[MAX][MAX];
    char cuvant[MAX_WORD];
    
    printf("Introduceti dimensiunea matricei pătratice: ");
    scanf("%d", &n);

    if (n <= 0 ) {
        printf("Dimensiunea matricei trebuie să fie între 1 și %d.\n");
    }


    citire_matrice(n, matrice);

    printf("Introduceti cuvant: ");
    scanf("%s", cuvant);

    cautare_cuvant(n, matrice, cuvant);

    return 0;
}*/

