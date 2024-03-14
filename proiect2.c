#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Subiectul 2.1 Să se scrie un program pentru tabelarea unor funcţii matematice. Programul trebuie să tabeleze 
funcţiile (x*x*x+4)/(x*x+5), x+10 şi 2*x*x-1. 
Tabelarea se va realiza pe intervalul [A,B] cu pasul P. Valorile A, B şi P se vor citi de la tastatură. Programul va 
afişa valorile funcţiilor sub formă de tabel.
Trebuie să se folosească pointeri la funcţii. Scrieţi o funcţie generică pentru tabelarea unei funcţii matematice 
oarecare. Această funcţie generică va avea un parametru de tip pointer la funcţie. 
Folosind funcţia generică, tabelaţi cele patru funcţii matematice amintite mai sus.*/

/*

typedef double (*functii_matematice)(double);

double functia1(double x) {
    return (x * x * x + 4) / (x * x + 5);
}

double functia2(double x) {
    return x + 10;
}

double functia3(double x) {
    return 2 * x * x - 1;
}


void tabelareFunctie(double a, double b, double p, functii_matematice f) {
    printf("Tabelarea functiei:\n");
    printf("x\t\tf(x)\n");
    for (double x = a; x <= b; x = x + p) {
        double y = f(x);
        printf("%.2f\t\t%.2f\n", x, y);
    }
}

int main() {
    double a, b, p;
    printf("Introduceti capetele intervalului [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Introduceti pasul P: ");
    scanf("%lf", &p);

    tabelareFunctie(a, b, p, functia1);
    printf("\n");
    
    tabelareFunctie(a, b, p, functia2);
    printf("\n");
    
    tabelareFunctie(a, b, p, functia3);

    return 0;
}*/

/* Subiectul 2.2 Se citesc mai multe cuvinte din linia de comandă. Cu ajutorul pointerilor la funcții (un vector de 
pointeri la funcții) să se apeleze într-o structură repetitivă următoarele funcții. Să se afișeze rezultatele pentru
fiecare cuvânt pe ecran și în fișierul text CUVINTE.TXT.
a) Primește parametru un șir de caractere și returneză lungimea șirului.
b) Primește parametru un șir de caractere și returneză numărul de vocale din text.
c) Primește parametru un șir de caractere și returneză numărul de litere mari din text.
Primește parametru un șir de caractere și returneză diferența codurilor ASCII ale primului caracter și al ultimului 
caracter.*/

/* !!!
typedef int (*pointer_functii)(char *);

int lungimeSir(char *s) {
    return strlen(s);
}

int numar_Vocale(char *s) {
    int numar = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            numar++;
    }
    return numar;
}

int numar_LitereMari(char *s) {
    int numar = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i]))
            numar++;
    }
    return numar;
}

int diferenta_ASCII(char *s) {
    int primaLitera = (int)s[0];
    int ultimaLitera = (int)s[strlen(s) - 1];
    return ultimaLitera - primaLitera;
}

int main() {
    int argc;
    char *argv[50];
   
    if (argc < 3) {
        printf("Introduceti cuvinte.");
    }

    FILE *fout = fopen("CUVINTE.TXT", "w");
    if (fout == NULL) {
        printf("Nu s-a putut deschide fisierul pentru scriere.\n");
    }

    pointer_functii functii[] = {lungimeSir, numar_Vocale, numar_LitereMari, diferenta_ASCII};
    int numarFunctii = sizeof(functii) / sizeof(functii[0]);

    
    for (int i = 1; i < argc; i++) {
        printf("Cuvantul \"%s\":\n", argv[i]);
        fprintf(fout, "Cuvantul \"%s\":\n", argv[i]);
        for (int j = 0; j < numarFunctii; j++) {
            int rezultat = functii[j](argv[i]);
            printf("Functia %c: %d\n", 'a' + j, rezultat);
            fprintf(fout, "Functia %c: %d\n", 'a' + j, rezultat);
        }
        printf("\n");
        fprintf(fout, "\n");
    }

    fclose(fout);

    return 0;
}*/
