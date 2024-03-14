/* Aplicația 8.3: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program care 
generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor utiliza 
pointeri.*/ 

#include <stdio.h>
#include <stdlib.h>
/*
void citireMatrice(int n, int m, int *matrice){
    int valoare = 1;
    for(int i = 0; i< n; i++){
        for(int j=0; j<m; j++){
            *(matrice + i * n + j) = valoare++;
        }
    }
}

void afisareMatrice(int n, int m, int *matrice){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", *(matrice + i * n + j));
        }
    }
}

int main(){
    int n, m;
    printf("Introduceti de la tastatură numarul de coloane:");
    scanf("%d", &n);
    printf("Introduceti de la tastatura numarul de linii:");
    scanf("%d", &m);
    
    if(n > 10 || m > 20){
        printf("Introduceti de la tastatura valori <= 10 pentru n si valori <=20 pentru m!");
    }
    
    int *matrice = (int *)malloc(n* m * sizeof(int));
    if(matrice == NULL){
        printf("Nu s-a alocat corect memoria!");
    }
    
    citireMatrice(n, m, matrice);
    printf("Matricea este: ");
    afisareMatrice(n, m, matrice);
    
    free(matrice);
    
    return 0;
}*/

/* Aplicația 8.4: Se citește de la tastatură o matrice pătratică cu n<=50 linii și coloane. Să se interschimbe elementele 
de deasupra diagonalei principale, considerată ca axă de simetrie, cu elementele de sub diagonala principală, 
elementele de pe diagonala principală rămânând la fel.*/
/* #define MAX 50

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InterschimbareElemente(int matrice[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&matrice[i][j], &matrice[j][i]);
        }
    }
}

void afisareMatrice(int matrice[MAX][MAX], int n) {
    printf("Matricea este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrice[MAX][MAX];
    
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    if ( n > MAX) {
        printf("Dimensiunea matricei trebuie sa fie intre 1 si 50.\n");
    }


    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    InterschimbareElemente(matrice, n);
    afisareMatrice(matrice, n);

    return 0;
}*/

/* Aplicația 8.5: Se citește de la tastatură o matrice cu n<=20 linii și coloane. Să se memoreze într-un vector suma 
tuturor elementelor de pe fiecare linie și într-un alt vector, suma tuturor elementelor de pe fiecare coloană. Să se 
afișeze cei doi vectori. Se vor utiliza pointeri atât pentru vectori cât și pentru matrici. */
/* !!!!!!!!
#define MAX 20

void SumaLinie(int *matrice, int *suma_linii, int n) {
    for (int i = 0; i < n; i++) {
        *(suma_linii + i) = 0;
        for (int j = 0; j < n; j++) {
            *(suma_linii + i) += *(matrice + i * n + j);
        }
    }
}

void SumaColoane(int *matrice, int *suma_coloane, int n) {
    for (int i = 0; i < n; i++) {
        *(suma_coloane + i) = 0;
        for (int j = 0; j < n; j++) {
            *(suma_coloane + j) += *(matrice + i * n + j);
        }
    }
}

void afisareVector(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(vector + i));
    }
    printf("\n");
}

int main() {
    int n;
    int matrice[MAX][MAX];
    int suma_coloane[MAX];
    int suma_linii[MAX];
    
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    if (n > 20) {
        printf("Dimensiunea matricei trebuie sa fie intre 1 si 20!\n");
    }

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    SumaLinie(matrice, suma_linii, n);
    SumaColoane(matrice, suma_coloane, n);

    printf("Suma elementelor pe fiecare linie:\n");
    afisareVector(SumaLinie, n);

    printf("Suma elementelor pe fiecare coloana:\n");
    afisareVector(SumaColoane, n);

    return 0;
}*/

/* Aplicația 8.6: Se citește un număr n<=10 de persoane, fiecare persoană fiind identificată printr-un număr între 
0..n-1. O persoană poate fi prietenă cu oricare alte persoane. După ce s-a citit n, se vor citi pentru fiecare persoană 
prietenii ei pe rând. Să se afișeze pentru fiecare persoană câți prieteni are. */
/*
#define MAX 10

int citire_numar_prieteni(int n) {
    int numar;
    printf("Introduceti numarul de prieteni pentru persoana %d: ", n);
    scanf("%d", &numar);
    return numar;
}

void citire_lista_prieteni(int n, int numar, int lista_prieteni[]) {
    printf("Introduceti numerele de persoane prietene cu persoana %d: ", n);
    for (int i = 0; i < numar; i++) {
        scanf("%d", &lista_prieteni[i]);
    }
}

int total_prieteni(int n, int lista_prieteni[MAX][MAX]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lista_prieteni[i][0]; j++) {
            total++;
        }
    }
    return total;
}

void afisare_numar_prieteni(int n, int lista_prieteni[MAX][MAX]) {
    printf("Numarul de prieteni pentru fiecare persoana:\n");
    for (int i = 0; i < n; i++) {
        printf("Persoana %d are %d prieteni.\n", i, lista_prieteni[i][0]);
    }
}

int main() {
    int n;
    int lista_prieteni[MAX][MAX];
    printf("Introduceti de la tastatură numarul de persoane: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Numarul de persoane trebuie sa fie intre 1 si 20.\n");
    }

    for (int i = 0; i < n; i++) {
        int numar = citire_numar_prieteni(i);
        lista_prieteni[i][0] = numar; 
        citire_lista_prieteni(i, numar, &lista_prieteni[i][1]); 
    }

    afisare_numar_prieteni(n, lista_prieteni);

    return 0;
}*/

/* Aplicația 8.7: Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă dintre 
ele. Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct. Să se afișeze perechea de orașe 
cele mai apropiate între ele în mod direct. */
/*
#define MAX 10


int distanta_orase(int oras1, int oras2) {
    int distanta;
    printf("Introduceti distanta dintre orasele %d si %d: ", oras1, oras2);
    scanf("%d", &distanta);
    return distanta;
}

void orase_apropiate(int n, int distanta[MAX][MAX]) {
    int distanta_minima = 1, oras1, oras2;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distanta[j] != 0) {
                distanta_minima = distanta[i][j];
                oras1 = i;
                oras2 = j;
            }
        }
    }

    if (distanta_minima == 0) {
        printf("Nu exista drum direct intre nici doua orase.\n");
    } else {
        printf("Cele mai apropiate orase sunt %d si %d, cu o distanta de %d km.\n", oras1, oras2, distanta_minima);
    }
}

int main() {
    int n;
    int distanta[MAX][MAX];
    
    printf("Introduceti numarul de orase: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numarul de orase trebuie sa fie intre 1 si %d.\n", MAX);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            distanta[i][j] = distanta_orase(i, j);
            distanta[j][i] = distanta[i][j]; 
        }
    }
    
    orase_apropiate(n, distanta);

    return 0;
}

/* Aplicația 8.8: Se citesc numerele m,n,p fiecare mai mici decat 10, apoi se citesc matricile a[m][n] și b[n][p]. Se 
cere să se calculeze matricea „c” care rezultă din înmulțirea matricilor a cu b și să se afișeze. */
/*
#define MAX 10

void citire_matrice(int n, int m, int matrice[MAX][MAX]) {
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
}

void inmultire_matrice(int n, int m, int p, int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;
            for (int k = 0; k < p; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void afisare_matrice(int n, int m, int matrice[MAX][MAX]) {
    printf("Matricea rezultata este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, p;
    int a[MAX][MAX];
    int b[MAX][MAX];
    int c[MAX][MAX];
    
    printf("Introduceti de la tastatură numarul de linii al primei matrici: ");
    scanf("%d", &m);
    
    printf("Introduceti de la tastatură numarul de coloane al primei matrici: ");
    scanf("%d", &n);
    
    printf("Introduceti de la tastatură numarul de coloane al celei de-a doua matrici: ");
    scanf("%d", &p);

    if (m <= 0 || n <= 0 || p <= 0) {
        printf("Dimensiunile matricilor trebuie sa fie intre 1 si %d.\n", MAX);
    }

    

    printf("Introduceti matricea A:\n");
    citire_matrice(m, n, a);
    afisare_matrice(m, n, a);

    printf("Introduceti matricea B:\n");
    citire_matrice(n, p, b);
    afisare_matrice(n, p, b);

    inmultire_matrice(m, n, p, a, b, c);

    afisare_matrice(m, p, c);

    return 0;
}*/

/* Aplicația 8.9: Se citește un număr n<=10. Se cere să se inițializeze o matrice a[n][n] cu 1 pe diagonale și cu 0 în 
rest. Să se afișeze matricea. */
/*
#define MAX 10

void initializare_matrice(int n, int matrice[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrice[i][j] = 1; 
            } else {
                matrice[i][j] = 0; 
            }
        }
    }
}


void afisare_matrice(int n, int matrice[MAX][MAX]) {
    printf("Matricea rezultata este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrice[MAX][MAX];
    
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Dimensiunea matricei trebuie sa fie intre 1 si %d.\n", MAX);
    }


    initializare_matrice(n, matrice);
    afisare_matrice(n, matrice);

    return 0;
}*/

/* Aplicația 8.10: Se citește un număr n<=10 de produse și pentru fiecare produs vânzările lui trimestriale pe un an 
(4 valori). Se cere să se afișeze care produse au înregistrat o creștere continuă a vânzărilor în decurs de un an. */
/* !!!!!
#define MAX 10

void citire_vanzari(int n, int vanzari[][4]) {
    for (int i = 0; i < n; i++) {
        printf("Introduceti vanzarile trimestriale pentru produsul %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &vanzari[i][j]);
        }
    }
}

int inregistrare_crestere(int vanzari[]) {
    for (int i = 1; i < 4; i++) {
        if (vanzari[i] <= vanzari[i - 1]) {
            return 0; 
        }
    }
    return 1;
}

void afisare_produse(int n, int vanzari[][4]) {
    printf("Produsele cu crestere continua a vanzarilor:\n");
    for (int i = 0; i < n; i++) {
        if (inregistrare_crestere(vanzari[i])) {
            printf("Produsul este:%d\n", i + 1);
        }
    }
}

int main() {
    int n;
    int vanzari[MAX][4];
    
    printf("Introduceti numarul de produse: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numarul de produse trebuie sa fie intre 1 si %d.\n", MAX);
    }


    citire_vanzari(n, vanzari);
    afisare_produse(n, vanzari);

    return 0;
}*/






