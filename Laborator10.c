#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* Aplicația 10.1: Calculați recursiv cel mai mare divizor comun a două numere.
𝑐𝑚𝑚𝑑𝑐(𝑎, 𝑏) = {
𝑎, 𝑑𝑎𝑐ă 𝑏 = 0
𝑐𝑚𝑚𝑑𝑐(𝑏, 𝑎%𝑏), 𝑑𝑎𝑐ă 𝑏 > 0 */
/*
int cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return cmmdc(b, a % b);
    }
}

int main() {
    int a, b;

    printf("Introduceți două numere întregi: ");
    scanf("%d %d", &a, &b);

    int rezultat = cmmdc(a, b);

    printf("Cel mai mare divizor comun al lui %d și %d este: %d\n", a, b, rezultat);

    return 0;
}*/

/* Aplicația 10.2: Calculați recursiv suma cifrelor unui număr natural.
𝑠𝑢𝑚𝑎_𝑐𝑖𝑓𝑟𝑒𝑙𝑜𝑟(𝑛) = {
𝑛, 𝑑𝑎𝑐ă 𝑛 < 10
𝑛%10 + 𝑠𝑢𝑚𝑎_𝑐𝑖𝑓𝑟𝑒𝑙𝑜𝑟(𝑛/10), 𝑑𝑎𝑐ă 𝑛 >= 10 */
/*
int suma_cifrelor(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + suma_cifrelor(n / 10);
    }
}

int main() {
    int numar;

    printf("Introduceți un număr natural: ");
    scanf("%d", &numar);

    int rezultat = suma_cifrelor(numar);

    printf("Suma cifrelor numărului %d este: %d\n", numar, rezultat);

    return 0;
}*/

/* Aplicația 10.3: Determinați recursiv cifra maximă a unui număr natural.
𝑐𝑖𝑓𝑟𝑎_𝑚𝑎𝑥(𝑛) = {
𝑛, 𝑑𝑎𝑐ă 𝑛 < 10
𝑐𝑖𝑓𝑟𝑎_max(𝑛%10, 𝑐𝑖𝑓𝑟𝑎_𝑚𝑎𝑥(𝑛/10)), 𝑑𝑎𝑐ă 𝑛 >= 10 */

/*
int max(int a, int b) {
    return (a > b) ? a : b;
}

int cifra_max(int n) {
    if (n < 10) {
        return n;
    } else {
        return max(n % 10, cifra_max(n / 10));
    }
}

int main() {
    int numar;

    printf("Introduceți un număr natural: ");
    scanf("%d", &numar);

    int rezultat = cifra_max(numar);

    printf("Cifra maximă a numărului %d este: %d\n", numar, rezultat);

    return 0;
}*/

/* Aplicația 10.4: Sa se determine recursiv al n-lea termen Fibonacci.
𝑓𝑖𝑏(𝑛) = {
1, 𝑑𝑎𝑐ă 𝑛 = 1 𝑠𝑎𝑢 𝑛 = 0
𝑓𝑖𝑏(𝑛 − 1) + 𝑓𝑖𝑏(𝑛 − 2), 𝑑𝑎𝑐ă 𝑛 > 1 */
/*
int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;

    printf("Introduceți valoarea lui n: ");
    scanf("%d", &n);

    int rezultat = fib(n);

    printf("Al %d-lea termen Fibonacci este: %d\n", n, rezultat);

    return 0;
}*/

/*Aplicația 10.5: Se considera sirul-de-caractere de tip Fibbonaci in care primii doi termeni sunt sirurile de caractere 
s1 si s2 (pot fi transmise ca si parametri functiei), iar orice alt termen se obtine prin concatenarea celor doi termeni 
anteriori. Sa se implementeze o functie care un numar natural n (si orice alti parametri considerati necesari) si 
afiseaza termenul de pe pozitia n din sirul construit conform celor de mai sus. */

/*
char* sirul_fibbonaci(int n, char* s1, char* s2) {
    if (n == 1) return s1;
    if (n == 2) return s2;

    char *a = strdup(s1); 
    char *b = strdup(s2); 
    char *c = NULL;

    for (int i = 3; i <= n; i++) {
        c = (char*)malloc(strlen(a) + strlen(b) + 1); 
        strcpy(c, b); 
        strcat(c, a); 

        free(a); 
        a = b; 
        b = c; 
    }

    free(a); 

    return c; 
}

int main() {
    char s1[] = "Negru";
    char s2[] = "Madalina";
    int n = 5;

    char* result = sirul_fibbonaci(n, s1, s2);
    printf("Termenul %d din sirul de caractere Fibonacci este: %s\n", n, rezultat);

    free(rezultat); 

    return 0;
}*/

/* Aplicația 10.6: Se poate demonstra (v. Knuth) ca limita raportului a doi termeni invers consecutivi din sirul lui 
Fibbonaci este egala cu Phi (proportia de aur). 
Astfel ϕ = lim𝑛→∞
(
𝐹𝑛+1
𝐹𝑛
) 
Implementati o functie (recursiva) care sa determine Phi cu o anumita precizie. */

/*
long long fibonacci(int n, long long* m) {
    if (n <= 1) 
        return n;
    if (m[n] != 0) 
        return m[n];
        m[n] = fibonacci(n-1, m) + fibonacci(n-2, m);
    return m[n];
}

double CalcularePhi(double precizie, int n, long long* m) {
    double phi_n = (double)fibonacci(n+1, m) / fibonacci(n, m);
    double phi_n_minus_1 = (double)fibonacci(n, m) / fibonacci(n-1, m);

    if (fabs(phi_n - phi_n_minus_1) < precizie) {
        return phi_n;
    }
    return CalcularePhi(precizie, n+1, m);
}

int main() {
    double precizie = 0.00001; 
    int initial_n = 2; 
    long long m[1000] = {0}; 

    double phi = CalcularePhi(precizie, initial_n, m);
    printf("Valoarea lui Phi cu o precizie de %.5f este: %.10f\n", precizie, phi);

    return 0;
}*/

/* Aplicația 10.7: Serii de puteri. Calculaţi, cu o precizie dată, valoarea lui ex după dezvoltarea în serie Taylor:
ex = 1 + x1
/1! + x2
/2! + x3
/3! + ...
Calculaţi suma până când termenul curent devine mai mic decât o valoare dată (de ex. 10-6
). Pentru a evita 
recalcularea lui n! transmiteţi ca parametru şi termenul curent, şi calculaţi-l pe următorul după relaţia: xn
/n! = xn-1
/(n-1)! * x/n.*/

/*
double CalculareVal(double x, double precizie) {
    double suma = 1.0; 
    double termen = 1.0; 
    int n = 1; 

    while (termen >= precizie) {
        termen = termen * x / n; 
        suma = suma + termen; 
        n++; 
    }

    return suma;
}

int main() {
    double x = 1.0; 
    double precizie = 1e-6; 

    double rezultat = CalculareVal(x, precizie);
    printf("Valoarea lui e^%.2f cu o precizie de %.0e este: %.10f\n", x, precizie, rezultat);

    return 0;
}*/

/* Aplicația 10.8: Să se implementeze cu o functie recursivă căutarea binară pe un vector ordonat (Binary Search -
bsearch). Functia trebuie să returneze dacă numărul căutat există sau nu în vector. Principiul după care 
funcționează bsearch este că vectorul se împarte la fiecare pas în 2 vectori de dimensiuni egale (sau aproximativ 
egale) și continuă căutarea doar în unul dintre ei (apelează recursiv funcția de căutare doar pe jumătate din vectorul 
inițial), cel din partea stângă sau cel din partea dreaptă, în funcție de valoarea numărului căutat. 
Exemplu:
v = 1, 5, 8, 12, 17, 20, 33, 40 , n = 33
imparte v in 2 vectori egali :v1 = 1, 5, 8, 12 v2 = 17, 20, 33, 40
continua cautarea lui n = 33 in vectorul v2
acum v = 17, 20, 33, 40, n=33
imparte v in 2 vectori egali :v1 = 17, 20 v2 = 33, 40
continua cautarea lui n = 33 in vectorul v2
acum v = 33, 40, n=33
imparte v in 2 vectori egali :v1 = 33 v2 = 40
continua cautarea lui n = 33 in vectorul v1
acum v = 33, n=33
l-a gasit */

bool binarySearch(int v[], int stanga, int dreapta, int n) {
    if (stanga > dreapta) {
        return false; 
    }

    int mijloc = stanga + (dreapta - stanga) / 2; 

    if (v[mijloc] == n) {
        return true; 
    } else if (v[mijloc] > n) {
        return binarySearch(v, stanga, mijloc - 1, n); 
    } else {
        return binarySearch(v, mijloc + 1, dreapta, n); 
    }
}

int main() {
    int v[] = {1, 5, 8, 12, 17, 20, 33, 40};
    int n = 33;
    int size = sizeof(v) / sizeof(v[0]);

    if (binarySearch(v, 0, size - 1, n)) {
        printf("Numarul %d a fost gasit in vector.\n", n);
    } else {
        printf("Numarul %d nu a fost gasit in vector.\n", n);
    }

    return 0;
}







