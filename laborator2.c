#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Aplicația 2.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat 
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari 
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/
/*
#define MAX_NUME 50
#define MAX_REZULTATE 100

typedef struct {
    char nume[MAX_NUME];
    int nota;
} RezultateStudent;

int comparare_rezultate(const void *a, const void *b) {
    const RezultateStudent *rezultatA = (const RezultateStudent *)a;
    const RezultateStudent *rezultatB = (const RezultateStudent *)b;

    if (rezultatA->nota != rezultatB->nota) {
        return rezultatB->nota - rezultatA->nota; 
    } else {
        return strcmp(rezultatA->nume, rezultatB->nume);
    }
}

int main() {
    int n;
    RezultateStudent rezultate[MAX_REZULTATE];
    
    printf("Introduceti numarul de studenti: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numarul de studenti trebuie sa fie intre 1 si %d.\n", MAX_REZULTATE);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Introduceti numele studentului %d: ", i + 1);
        scanf("%s", rezultate[i].nume);
        printf("Introduceti nota studentului %d: ", i + 1);
        scanf("%d", &rezultate[i].nota);
    }


    qsort(rezultate, n, sizeof(RezultateStudent), comparare_rezultate);

    printf("Rezultatele sortate:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", rezultate[i].nume, rezultate[i].nota);
    }

    return 0;
}*/

/* Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor 
din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția 
va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu 
numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
negativ și să se afișeze vectorul rezultat */
/*
typedef int (*Predicat)(int);

int este_negativ(int numar) {
    if(numar < 0)
    return numar > 0;
}

void verificare_conditie(int *v, int *size, Predicat pred) {
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (pred(v[i])) {
            v[j] = v[i];
            j++;
        }
    }
    *size = j;
}

int main() {
    int n;
    int v[n];
    
    printf("Introduceti numarul de elemente din vector: ");
    scanf("%d", &n);


    printf("Introduceti elementele vectorului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("Vectorul initial: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    verificare_conditie(v, &n, este_negativ);

    printf("Vectorul dupa filtrare (fara numere negative): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/

/* Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort 
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția 
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort 
și bsearch */

/*
int comparare(const void *a, const void *b) {
    const float *float_a = (const float *)a;
    const float *float_b = (const float *)b;
    
    if (*float_a < *float_b) 
        return -1;
    if (*float_a > *float_b) 
        return 1;
    return 0;
}

int main() {
    int n;
    
    
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 10) {
        printf("Numarul de elemente trebuie sa fie intre 1 si 9.\n");
    }
    
    float v[n];
    printf("Introduceti cele %d numere:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
    }

    qsort(v, n, sizeof(float), comparare);
    
    
    printf("Vectorul sortat:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    float x;
    printf("Introduceti numarul cautat: ");
    scanf("%f", &x);

    float *rezultat = (float *)bsearch(&x, v, n, sizeof(float), comparare);
    if (rezultat != NULL) {
        printf("%.2f exista in vectorul sortat.\n", x);
    } else {
        printf("%.2f nu exista in vectorul sortat.\n", x);
    }

    return 0;
}
*/

/* Aplicația 2.4: Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca 
argument. Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double. Funcția 
de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat, n - un număr 
întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de 
tabelat. Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs 
din math.h
Exemplu: tabelare(-10,10,20,fabs) va afișa pe câte o linie valori de forma f(-10)=10 f(-9)=9 … f(10)=10 */
#include <stdio.h>
#include <math.h>

typedef double (*functii_matematice)(double);


void tabelare(double a, double b, int n, functii_matematice f) {
    double pas = (b - a) / n;
    
    printf("Tabelarea functiei intre %.2f si %.2f, in %d segmente:\n", a, b, n);
    for (int i = 0; i <= n; i++) {
        double x = a + i * pas;
        double y = f(x);
        printf("f(%.2f)=%.2f\n", x, y);
    }
}

int main() {
    double a, b;
    int n;
    
    printf("Introduceti capetele intervalului [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Introduceti numarul de segmente: ");
    scanf("%d", &n);
    
    printf("Tabelarea functiei cos:\n");
    tabelare(a, b, n, cos);
    
    printf("\nTabelarea functiei sqrt:\n");
    tabelare(a, b, n, sqrt);
    
    printf("\nTabelarea functiei fabs:\n");
    tabelare(a, b, n, fabs);
    
    return 0;
}

