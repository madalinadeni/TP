#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*Aplicația 12.1: Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din 
n cifre care contin exact k cifre de 1. */

/*
void generareNumere(int poz, int n, int k, int numarare1, char* numarulCurent) {
    if (poz == n) {
        if (numarare1 == k) {
            printf("%s\n", numarulCurent);
        }
        return;
    }

    numarulCurent[poz] = '0';
    generareNumere(poz + 1, n, k, numarare1, numarulCurent);

    numarulCurent[poz] = '1';
    generareNumere(poz + 1, n, k, numarare1 + 1, numarulCurent);
}

int main() {
    int n, k;

    printf("Introduceti de la tastatura numarul de cifre: ");
    scanf("%d", &n);
    printf("Introduceti de la tastatura numarul de cifre de 1: ");
    scanf("%d", &k);

    if (k > n) {
        printf("Nu este posibil sa se genereze un numar cu %d cifre de 1 din %d cifre.\n", k, n);
        return 1;
    }

    char numarulCurent[n + 1];
    numarulCurent[n] = '\0'; 

   generareNumere(0, n, k, 0, numarulCurent);

    return 0;
}*/

/* Aplicația 12.2: Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate 
elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare.
Exemplu:
n=5
permutarile care respecta conditia sunt:
3 2 1 4 5
4 2 1 3 5
4 3 1 2 5
5 2 1 3 4
5 3 1 2 4
5 4 1 2 3 */

/*
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int permutari(int *v, int n) {
    int jumatate = n / 2;
    for (int i = 0; i < jumatate - 1; i++) {
        if (v[i] < v[i + 1]) {
            return 0;
        }
    }
    for (int i = jumatate; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void generarePermutari(int *v, int start, int n) {
    if (start == n) {
        if (permutari(v, n)) {
            for (int i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = start; i < n; i++) {
            swap(&v[start], &v[i]);
            generarePermutari(v, start + 1, n);
            swap(&v[start], &v[i]);
        }
    }
}

int main() {
    int n;
    printf("Introduceti de la tastatura un numar natural: ");
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    generarePermutari(v, 0, n);

    return 0;
}*/

/* Aplicația 12.3: Se citesc doua numere naturale n si k, k fiind mai mic decat numarul de cifre ale numarului n. Afisati 
cel mai mare numar care se poate forma eliminand k cifre din numarul n.
Exemplu:
n=3452234
k=4
numarul cautat este 534 */
/*
int convertire(char *numar) {
    int rezultat = 0;
    while (*numar) {
        rezultat = rezultat * 10 + (*numar - '0');
        numar++;
    }
    return rezultat;
}

void gasireNumar(char *numar, int n, int k, int start, char *curent, int Index, int *numarMaxim) {
    if (k == 0) {
        curent[Index] = '\0';
        int numarCurent = convertire(curent);
        if (numarCurent > *numarMaxim) {
            *numarMaxim = numarCurent;
        }
        return;
    }
    
    for (int i = start; i <= n - k; i++) {
        curent[Index] = numar[i];
        gasireNumar(numar, n, k - 1, i + 1, curent, Index + 1, numarMaxim);
    }
}

int main() {
    char numar[100];
    int k;
    
    printf("Introduceti de la tastatura numarul n: ");
    scanf("%s", numar);
    printf("Introduceti de la tastatura numarul k: ");
    scanf("%d", &k);
    
    int n = strlen(numar);
    
    char curent[n - k + 1];
    int numarMaxim = 0;
    
    gasireNumar(numar, n, n - k, 0, curent, 0, &numarMaxim);
    
    printf("Cel mai mare numar este: %d\n", numarMaxim);
    
    return 0;
}*/

/* Aplicația 12.4: Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
- orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
- culorile din fiecare steag trebuie sa fie distincte. */

/*
void generareSteag(char culoare[][10], int n, char steag[][10], int poz, int *folosit) {
    if (poz == 3) {
        if (strcmp(steag[1], "verde") == 0 || strcmp(steag[1], "galben") == 0) {
            for (int i = 0; i < 3; i++) {
                printf("%s ", steag[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!folosit[i]) {
            folosit[i] = 1;
            strcpy(steag[poz], culoare[i]);
            generareSteag(culoare, n, steag, poz + 1, folosit);
            folosit[i] = 0;
        }
    }
}

int main() {
    char culoare[6][10] = {"alb", "galben", "rosu", "verde", "albastru", "negru"};
    char steag[3][10];
    int folosit[6] = {0};

    generareSteag(culoare, 6, steag, 0, folosit);

    return 0;
}*/

/* Aplicația 12.5: Se cere un 0<n<=100 și apoi n valori reale, fiecare reprezentând volumul unui obiect. În final se 
cere v, volumul unei cutii. Se cere să se umple cutia cu unele dintre obiecte date, astfel încât volumul ei să fie
utilizat în mod optim. */
/*
#define MAX 100

void gasireVolum(float volum[], int n, float v, int index, float volumCurent, float *volumMaxim) {
    if (index == n) {
        if (volumCurent <= v && volumCurent > *volumMaxim) {
            *volumMaxim = volumCurent;
        }
        return;
    }

    gasireVolum(volum, n, v, index + 1, volumCurent + volum[index], volumMaxim);
    gasireVolum(volum, n, v, index + 1, volumCurent, volumMaxim);
}

int main() {
    int n;
    float volum[MAX];
    float v;
    
    printf("Introduceti de la tastatura numarul de obiecte (n>0 si n<=100): ");
    scanf("%d", &n);
    
    printf("Introduceti de la tastatura volumele obiectelor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &volum[i]);
    }

    printf("Introduceti de la tastatura volumul cutiei: ");
    scanf("%f", &v);

    float volumMaxim = 0;
   gasireVolum(volum, n, v, 0, 0, &volumMaxim);

    printf("Volumul maxim care poate fi obtinut este: %.2f\n", volumMaxim);

    return 0;
}*/


/* Aplicația 12.6: De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini, 
ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli 
(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca 
vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini
și ateliere. Să se determine toate variantele în care acestea pot fi aranjate. */

/*
#define MAX 100

int verificareAranjament(char aranjament[], int lungime) {
    for (int i = 1; i < lungime; i++) {
        if (aranjament[i] == 'C' && aranjament[i - 1] != 'C' && aranjament[i - 1] != 'B' && aranjament[i - 1] != 'G')
            return 0;
        if (aranjament[i] == 'B' && aranjament[i - 1] != 'B' && aranjament[i - 1] != 'C')
            return 0;
        if (aranjament[i] == 'G' && aranjament[i - 1] != 'G' && aranjament[i - 1] != 'C' && aranjament[i - 1] != 'A')
            return 0;
        if (aranjament[i] == 'A' && aranjament[i - 1] != 'A' && aranjament[i - 1] != 'G')
            return 0;
    }
    return 1;
}

void generareAranjamente(char entitati[], int count[], int total, char aranjament[], int poz) {
    if (poz == total) {
        if (verificareAranjament(aranjament, total)) {
            for (int i = 0; i < total; i++) {
                printf("%c ", aranjament[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (count[i] > 0) {
            aranjament[poz] =entitati[i];
            count[i]--;
            generareAranjamente(entitati, count, total, aranjament, poz + 1);
            count[i]++;
        }
    }
}

int main() {
    int c, b, g, a;
    printf("Introduceti de la tastatură numarul de case: ");
    scanf("%d", &c);
    printf("Introduceti de la tastatură numarul de blocuri: ");
    scanf("%d", &b);
    printf("Introduceti de la tastatură numarul de gradini: ");
    scanf("%d", &g);
    printf("Introduceti de la tastatură numarul de ateliere: ");
    scanf("%d", &a);

    char entitati[4] = {'C', 'B', 'G', 'A'};
    int count[4] = {c, b, g, a};
    int total = c + b + g + a;
    char aranjament[MAX];

    generareAranjamente(entitati, count, total, aranjament, 0);

    return 0;
}*/

/* Aplicația 12.7: Se cere 0<n<=100 și apoi n valori pozitive întregi, reprezentând laturile unor pătrate. În final se 
cere 0<p<=100, valoare întreagă, reprezentând latura unui pătrat. Se cere să se determine dacă există un 
aranjament al celor n pătrate în interiorul pătratului de latură p, astfel încât toate pătratele să fie conținute în acesta 
și să nu existe suprapuneri între pătrate. */

/*
#define MAX 100

int n, p;
int patrate[MAX];
bool folosit[MAX];
int aranjament[MAX][2];

bool verificarePlasare(int x, int y, int size, int v[MAX][MAX]) {
    if (x + size > p || y + size > p) {
        return false;
    }

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (v[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void plasarePatrat(int x, int y, int size, int v[MAX][MAX], int val) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            v[i][j] = val;
        }
    }
}

bool rezolvare(int index, int v[MAX][MAX]) {
    if (index == n) {
        return true;
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            if (verificarePlasare(i, j, patrate[index], v)) {
                plasarePatrat(i, j, patrate[index], v, index + 1);
                aranjament[index][0] = i;
                aranjament[index][1] = j;
                if (rezolvare(index + 1, v)) {
                    return true;
                }
                plasarePatrat(i, j, patrate[index], v, 0);
            }
        }
    }
    return false;
}

int main() {
    printf("Introduceti de la tastatură numarul de patrate: ");
    scanf("%d", &n);

    printf("Introduceti de la tastatură laturile patratelor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &patrate[i]);
    }

    printf("Introduceti de la tastatură latura patratului: ");
    scanf("%d", &p);

    int v[MAX][MAX] = {0};

    if (rezolvare(0, v)) {
        printf("Exista un aranjament valid:\n");
        for (int i = 0; i < n; i++) {
            printf("Patratul de latura %d la (%d, %d)\n", patrate[i], aranjament[i][0], aranjament[i][1]);
        }
    } else {
        printf("Nu exista un aranjament valid.\n");
    }

    return 0;
}*/

/* Aplicația 12.8: Se cere d de tip întreg reprezentând lungimea unei drepte și 0<n<=100 un număr de segmente. În 
câte feluri se poate împărți dreapta dată în n segmente consecutive, având fiecare lungimi întregi pozitive, astfel 
încât fiecare segment să fie strict mai mare decât cel de dinaintea sa? */


int numarareModalitati(int d, int n, int start) {
    if (n == 0 && d == 0) {
        return 1;
    }
    
    if (n == 0 || d <= 0) {
        return 0;
    }
    
    int count = 0;
    for (int i = start + 1; i <= d; i++) {
        count = count + numarareModalitati(d - i, n - 1, i);
    }
    
    return count;
}

int main() {
    int d, n;
    
    printf("Introduceti de la tastatură lungimea dreptei (d): ");
    scanf("%d", &d);
    printf("Introduceti de la tastatură numarul de segmente (n): ");
    scanf("%d", &n);
    
    if (n <= 0 || d <= 0) {
        printf("Datele de intrare nu sunt valide.\n");
        return 0;
    }
    
    int modalitati = numarareModalitati(d, n, 0);
    printf("Numarul de moduri de a imparti dreapta in %d segmente consecutive este: %d\n", n, modalitati);
    
    return 0;
}








