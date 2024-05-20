#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Aplicația 11.1: Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan. Fiecare punct reprezintă 
poziția unde va trebui dată o gaură într-o placă. Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de 
dat găuri, astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea */

/*Am folosit metoda Greedy pentru a rezolva problema. Algoritmul este potrivit pentru problema deoarece, in fiecare pas,
alegem întotdeauna punctul cel mai apropiat de locatia curenta a bormasinii, ceea ce minimizeaza distanta parcursa la fiecare mutare. */

/*
#define MAX_PUNCTE 100

typedef struct {
    double x;
    double y;
} Punct;

double Calculare_Distanta(Punct a, Punct b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int Gasire_Punct(Punct puncte[], bool vizitat[], int n, Punct current) {
    int Index = -1;
    double minDist = INFINITY;

    for (int i = 0; i < n; i++) {
        if (!vizitat[i]) {
            double dist = Calculare_Distanta(current, puncte[i]);
            if (dist < minDist) {
                minDist = dist;
                Index = i;
            }
        }
    }

    return Index;
}

int main() {
    int n;
    Punct puncte[MAX_PUNCTE];
    bool vizitat[MAX_PUNCTE] = {false};

    printf("Introduceti numarul de puncte (n < 100): ");
    scanf("%d", &n);


    printf("Introduceti coordonatele punctelor x y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &puncte[i].x, &puncte[i].y);
    }

    Punct current = {0.0, 0.0};

    printf("Ordinea de dat gauri este:\n");
  
    for (int i = 0; i < n; i++) {
        int Index = Gasire_Punct(puncte, vizitat, n, current);
        if (Index != -1) {
            vizitat[Index] = true;
            current = puncte[Index];
            printf("Punctul %d: (%.2f, %.2f)\n", Index + 1, current.x, current.y);
        }
    }

    return 0;
}*/

/* Aplicația 11.2: Se cere un n strict pozitiv și patru valori reale: ma, mb, m, d. ma și mb reprezintă masele a două 
corpuri situate la distanța d unul de celălalt. m este masa unui corp care pornește din a și ajunge în b, din n pași 
egali. Să se calculeze în fiecare punct al traseului lui m forța F de atracție gravitațională care acționează asupra 
lui. F va fi cu semn: negativ înseamnă că m este atras către ma, iar pozitiv către mb. Formula atracției gravitaționale 
dintre două corpuri m1 și m2, situate la distanța d unul de celălalt este: F=G*m1*m2/d2
, unde G=6.674e-11. Masele 
sunt exprimate în kilograme, distanțele în metri, iar forțele în newtoni */

/* Am folosit metoda "Divide and Conquer" deoarece am impartit problema in subprobleme mai mici și le-am rezolvat recursiv*/

/*
#define G 6.674e-11

double calculareForta(double m1, double m2, double distanta) {
    return G * m1 * m2 / (distanta * distanta);
}

void calculareForte(double ma, double mb, double m, double start, double sfarsit, int pasiiRamasi, int pasiiTotali) {
    if (pasiiRamasi <= 0) {
        return;
    }

    double mijloc = (start + sfarsit) / 2;
    double distantaA = mijloc;
    double distantaB = sfarsit - mijloc;

    double fortaA = calculareForta(ma, m, distantaA);
    double fortaB = calculareForta(mb, m, distantaB);
    double forta = fortaB - fortaA;

    int numarPasi = pasiiTotali - pasiiRamasi + 1;
    printf("Pasul %d: pozitia %.2f m, forta %.2e N\n", numarPasi, mijloc, forta);

    calculareForte(ma, mb, m, start, mijloc, pasiiRamasi - 1, pasiiTotali);
    calculareForte(ma, mb, m, mijloc, sfarsit, pasiiRamasi - 1, pasiiTotali);
}

int main() {
    int n;
    double ma, mb, m, d;

    printf("Introduceti de la tastatura numarul de pasi n: ");
    scanf("%d", &n);
    printf("Introduceti de la tastatura masa ma: ");
    scanf("%lf", &ma);
    printf("Introduceti de la tastatura masa mb: ");
    scanf("%lf", &mb);
    printf("Introduceti de la tastatura masa m: ");
    scanf("%lf", &m);
    printf("Introduceti de la tastatura distanta d: ");
    scanf("%lf", &d);

    printf("Punctele traseului si forta de atractie gravitationala in fiecare punct sunt:\n");

    calculareForte(ma, mb, m, 0, d, n, n);

    return 0;
}*/

/* Aplicația 11.3: Definim reducerea unei matrici cu elemente întregi ca fiind valoarea calculată astfel: dacă matricea 
nu are niciun element, reducerea este 0. Dacă matricea are un element, reducerea este valoarea acelui element. 
Pentru orice alte cazuri, matricea se subîmparte în 4 matrici prin tăierea ei în cruce, prin mijlocul matricii. Reducerea 
va fi maximul reducerilor celor două matrici superioare, minus minimul reducerilor celor două matrici inferioare. Să 
se calculeze reducerea unei matrici de dimensiuni m,n citită de la tastatură. */

/* Am folosit metoda "Divide and Conquer" deoarece am impartit problema in subprobleme mai mici și le-am rezolvat recursiv*/

/*
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}


int reducereMatrice(int matrice[][100], int startLinie, int sfarsitLinie, int startColoana, int sfarsitColoana) {
    int numLinie = sfarsitLinie - startLinie + 1;
    int numColoana = sfarsitColoana - startColoana + 1;

    if (numLinie == 0 || numColoana == 0) {
        return 0; 
    }
    
    if (numLinie == 1 && numColoana == 1) {
        return matrice[startLinie][startColoana]; 
    }

    int mijlocLinie = (startLinie + sfarsitLinie) / 2;
    int mijlocColoana = (startColoana + sfarsitColoana) / 2;

    
    int topStanga = reducereMatrice(matrice, startLinie, mijlocLinie, startColoana, mijlocColoana);
    int topDreapta = reducereMatrice(matrice, startLinie, mijlocLinie, mijlocColoana + 1, sfarsitColoana);
    int bottomStanga = reducereMatrice(matrice, mijlocLinie + 1, sfarsitLinie, startColoana, mijlocColoana);
    int bottomDreapta = reducereMatrice(matrice, mijlocLinie + 1, sfarsitLinie, mijlocColoana + 1, sfarsitColoana);

    int topMax = max(topStanga, topDreapta);
    int bottomMin = min(bottomStanga, bottomDreapta);

    return topMax - bottomMin;
}

int main() {
    int m, n;
    int matrice[100][100];

    printf("Introduceti de la tastatură numarul de randuri m: ");
    scanf("%d", &m);
    printf("Introduceti de la tastatură numarul de coloane n: ");
    scanf("%d", &n);

    printf("Introduceti de la tastatură elementele matricii:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    int reducere = reducereMatrice(matrice, 0, m - 1, 0, n - 1);
    
    printf("Reducerea matricii este: %d\n", reducere);

    return 0;
}*/

/* Aplicația 11.4: La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int). 
Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor, astfel 
încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și ei în 
grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe, pentru 
valori citite dintr-un fișier. */

/* Am folosit metoda Greedy pentru a rezolva problema.Algoritmul este potrivit aici deoarece distribuim jucatorii în grupe 
astfel încat fiecare grupa sa primeasca în mod repetitiv cel mai valoros jucator ramas.*/

/*
#define MAX_LUNGIME_NUME 15
#define MAX_JUCATORI 100

typedef struct {
    char nume[MAX_LUNGIME_NUME + 1];
    int valoare;
} Jucator;

int comparareJucatori(const void* a, const void* b) {
    Jucator* jucatorA = (Jucator*)a;
    Jucator* jucatorB = (Jucator*)b;
    return jucatorB->valoare - jucatorA->valoare;
}

void distribuireJucatori(Jucator jucatori[], int n, int m, Jucator grupe[][MAX_JUCATORI / m]) {
    qsort(jucatori, n, sizeof(Jucator), comparareJucatori);

    for (int i = 0; i < n; i++) {
        int Index = i % m;
        int pozitie = i / m;
        grupe[Index][pozitie] = jucatori[i];
    }
}

int main() {
    int n, m;
    FILE *f = fopen("jucatori.txt", "r");
    
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        exit(EXIT_FAILURE);
    }
    
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);

    Jucator jucatori[MAX_JUCATORI];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }
    fclose(f);

    Jucator grupe[m][MAX_JUCATORI / m];

    distribuireJucatori(jucatori, n, m, grupe);

    for (int i = 0; i < m; i++) {
        printf("Grupa %d:\n", i + 1);
        for (int j = 0; j < n / m; j++) {
            printf("%s %d\n", grupe[i][j].nume, grupe[i][j].valoare);
        }
        printf("\n");
    }

    return 0;
}*/

/* Aplicația 11.5: Să se scrie o funcție care primește un număr întreg 0<=n<1000 și îl afișează în formă literară. Să 
se apeleze funcția pentru numere introduse de la tastatură, pană la apariția valorii 1000.
Exemple: 108 → o suta opt; 520 → cinci sute douazeci; 16 → saisprezece */

/* Am folosit metoda "Divide and Conquer" deoarece am impartit problema in subprobleme mai mici. */


void convertireSute(int n, char* rezultat) {
    char *unitati[] = {"", "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};
    char *zece[] = {"zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece", "saisprezece", "saptesprezece", "optsprezece", "nouasprezece"};
    char *zeci[] = {"", "", "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"};
    char *sute[] = {"", "o suta", "doua sute", "trei sute", "patru sute", "cinci sute", "sase sute", "sapte sute", "opt sute", "noua sute"};

    int h = n / 100;
    int t = (n % 100) / 10;
    int u = n % 10;

    rezultat[0] = '\0';

    if (h > 0) {
        strcat(rezultat, sute[h]);
    }

    if (t > 1) {
        if (h > 0) strcat(rezultat, " ");
        strcat(rezultat, zeci[t]);
        if (u > 0) {
            strcat(rezultat, " ");
            strcat(rezultat, unitati[u]);
        }
    } else if (t == 1) {
        if (h > 0) strcat(rezultat, " ");
        strcat(rezultat, zece[u]);
    } else if (u > 0) {
        if (h > 0) strcat(rezultat, " ");
        strcat(rezultat, unitati[u]);
    }
}

void convertireCuvinte(int n, char* rezultat) {
    if (n == 0) {
        strcpy(rezultat, "zero");
        return;
    }

    if (n < 100) {
        convertireSute(n, rezultat);
    } else {
        int hundredsPart = n / 100;
        int remainder = n % 100;
        
        char hundredsStr[100];
        char remainderStr[100];
       
        convertireSute(hundredsPart * 100, hundredsStr);
        convertireSute(remainder, remainderStr);
        
        strcpy(rezultat, hundredsStr);
        
        if (remainder > 0) {
            strcat(rezultat, " ");
            strcat(rezultat, remainderStr);
        }
    }
}

int main() {
    int n;
    char rezultat[100];

    printf("Introduceti un numar intre 0 si 999 (sau 1000 pentru a opri): ");
    while (1) {
        scanf("%d", &n);
        if (n == 1000) break;
        if (n < 0 || n >= 1000) {
            printf("Numarul trebuie sa fie intre 0 si 999. Introduceti din nou: ");
            continue;
        }
        
        convertireCuvinte(n, rezultat);
        printf("%d -> %s\n", n, rezultat);
        printf("Introduceti un numar intre 0 si 999 (sau 1000 pentru a opri): ");
    }

    return 0;
}



