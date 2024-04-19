#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/* Aplicații propuse – funcții cu număr variabil de parametrii
Aplicația 6.1: Să se modifice exemplul 2 astfel încât funcția err să încapsuleze și condiția de eroare. Pentru 
aceasta, ea primește în plus pe prima poziție o variabilă de tip int care reprezintă o valoare logică. Dacă valoarea 
este true, se va executa err ca în exemplu, altfel err nu va avea niciun efect.
Exemplu de folosire: err(n<=0||n>100,"n invalid: %d\n",n); // fără if în față, deoarece err încapsulează condiția */

/*
void err(int condition, const char *fmt, ...)
{
    if (condition)
    {
        va_list va; 
        va_start(va, fmt);
        
        fprintf(stderr, "eroare: ");
        vfprintf(stderr, fmt, va);
        
        va_end(va);
        fputc('\n', stderr);
        exit(EXIT_FAILURE);
    }
}

int main()
{
    int i, n;
    float x, y, e, min, max;

    printf("n="); scanf("%d", &n);
    err(n <= 0 || n > 100, "n invalid: %d\n", n);

    printf("x="); scanf("%g", &x);
    printf("y="); scanf("%g", &y);
    err(x >= y, "x=%g nu este mai mic decat y=%g\n", x, y);

    max = x;
    min = y;

    for (i = 0; i < n; i++)
    {
        printf("e="); scanf("%g", &e);
        err(e < x || e > y, "element invalid: %g\n", e);
        
        if (e < min) min = e;
        if (e > max) max = e;
    }

    printf("min: %g, max: %g\n", min, max);

    return 0;
}*/

/* Aplicația 6.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente 
iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele.
Exemplu: allocVec(3,7.2,-1,0) => {7.2, -1, 0}*/

/*
float *allocVec(int n, ...)
{
    float *vector = (float *)malloc(n * sizeof(float));

    if (vector == NULL)
    {
        printf("Eroare la alocarea memoriei!\n");
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, n);
    
    for (int i = 0; i < n; i++)
    {
        vector[i] = (float)va_arg(args, double);
    }
    
    va_end(args);

    return vector;
}

int main()
{
    int n = 3;
    float *vector = allocVec(n, 7.2, -1, 0);

    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f", vector[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    free(vector);

    return 0;
}*/

/* Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la 
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y) */
/*
void absN(int n, ...)
{
    
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        float *ptr = va_arg(args, float *);
        *ptr = fabs(*ptr);
    }

    va_end(args);
}

int main()
{
    float x = -5.5, y = 3.3;

    printf("x = %.2f, y = %.2f\n", x, y);

    absN(2, &x, &y);

    printf("x = %.2f, y = %.2f\n", x, y);

    return 0;
}*/

/* Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1 
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/
/*
int crescator(int n, char tip, ...)
{
    va_list args;
    va_start(args, tip);

    int int_prev;
    double double_prev;

    switch (tip)
    {
        case 'd':
            int_prev = va_arg(args, int);
            for (int i = 1; i < n; i++)
            {
                int current = va_arg(args, int);
                if (current <= int_prev)
                {
                    va_end(args);
                    return 0;
                }
                int_prev = current;
            }
            break;
        case 'f': 
            double_prev = va_arg(args, double);
            for (int i = 1; i < n; i++)
            {
                double current = va_arg(args, double);
                if (current <= double_prev)
                {
                    va_end(args);
                    return 0;
                }
                double_prev = current;
            }
            break;
        default:
            va_end(args);
            printf("Tipul de date introdus nu este valid!\n");
            return -1;
    }

    va_end(args);
    return 1;
}

int main()
{
    printf("%d\n", crescator(3, 'd', -1, 7, 9));
    printf("%d\n", crescator(3, 'f', -1.0, 7.2, 9.5));

    return 0;
}*/

/*
Aplicația 6.5: Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice 
în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe 
ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
Exemplu: input(”n=%dch=%c”,&n,&ch); // citește o valoare de tip int în n și de tip char în ch */

/*
void input(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            switch (*(++fmt))
            {
                case 'd':
                    scanf("%d", va_arg(args, int *));
                    break;
                case 'f':
                    scanf("%f", va_arg(args, float *));
                    break;
                case 'c':
                    scanf(" %c", va_arg(args, char *));
                    break;
                default:
                    putchar(*fmt);
                    break;
            }
        }
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }

    va_end(args);
}

int main()
{
    int n;
    char ch;

    input("n=%d ch=%c", &n, &ch);

    printf("n=%d, ch=%c\n", n, ch);

    return 0;
}*/

/* Aplicația 6.6: Să se scrie o funcție char *concat(int n,...) care primește un număr de șiruri de caractere și apoi 
șirurile propriu-zise. Funcția va concatena într-un nou șir, alocat dinamic, conținuturile tuturor șirurilor date, cu câte 
un spațiu între ele și va returna acest șir.
Exemplu: concat(3,”Ion”,”si”,”Ana”) => “Ion si Ana” */
/*
char *concat(int n, ...)
{
    va_list args;
    va_start(args, n);

    int lungime_totala = 0;
    for (int i = 0; i < n; i++)
    {
        lungime_totala += strlen(va_arg(args, const char *));
    }
   
    lungime_totala += n - 1;

    char *rezultat = (char *)malloc(lungime_totala + 1);
    if (rezultat == NULL)
    {
        printf("Eroare la alocarea memoriei!\n");
        exit(EXIT_FAILURE);
    }

    va_start(args, n);
    strcpy(rezultat, va_arg(args, const char *));
    for (int i = 1; i < n; i++)
    {
        strcat(rezultat, " ");
        strcat(rezultat, va_arg(args, const char *));
    }
    va_end(args);

    return rezultat;
}

int main()
{
    char *rezultat = concat(3, "Ion", "si", "Ana");
    printf("%s\n", rezultat);

    free(rezultat);

    return 0;
}*/

/* Aplicația 6.7: Să se scrie o funcție int comune(int nVec,...) care primește un număr de vectori cu valori de tip int și 
vectorii propriu-ziși. Fiecare vector se dă prin 2 argumente: un pointer la elementele sale și dimensiunea. Funcția 
va returna numărul de elemente comune care se regăsesc în toți vectorii.
Exemplu: comune(3,v1,2,v2,3,v3,3) => returnează 2 pentru v1={5,8}, v2={8,3,5}, v3={5,0,8}*/

/*
int comune(int nVec, ...)
{
    va_list args;
    va_start(args, nVec);

    int *firstVector = va_arg(args, int *);
    int firstSize = va_arg(args, int);

    int contor[100000] = {0};

    for (int i = 0; i < firstSize; i++)
    {
        contor[firstVector[i]]++;
    }

  
    for (int i = 1; i < nVec; i++)
    {
        int *currentVector = va_arg(args, int *);
        int currentSize = va_arg(args, int);
        
        for (int j = 0; j < currentSize; j++)
        {
            if (contor[currentVector[j]] == i)
            {
                contor[currentVector[j]]++;
            }
        }
    }

    int elementeComune = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (contor[i] == nVec)
        {
            elementeComune++;
        }
    }

    va_end(args);

    return elementeComune;
}

int main()
{
    int v1[] = {5, 8};
    int v2[] = {8, 3, 5};
    int v3[] = {5, 0, 8};

    int rezultat = comune(3, v1, 2, v2, 3, v3, 3);

    printf("Numarul de elemente comune este: %d\n", rezultat);

    return 0;
}*/

/* Aplicația 6.8: Să se scrie o funcție sortare(int n,...) care pe prima poziție are numărul de elemente de sortat, iar 
pe următoarele poziții n adrese de valori de tip int. Funcția va sorta crescător valorile de la adresele date.
Exemplu: sortare(3,&i,&j,&k); // sortează crescător valorile lui i, j și k */
/*
void sortare(int n, ...)
{
    va_list args;
    va_start(args, n);

    int *values = (int *)malloc(n * sizeof(int));
    if (values == NULL)
    {
        printf("Eroare la alocarea memoriei!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        values[i] = *va_arg(args, int *);
    }

    va_end(args);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    va_start(args, n);
    for (int i = 0; i < n; i++)
    {
        *va_arg(args, int *) = values[i];
    }
    va_end(args);

    free(values);
}

int main()
{
    int i = 3, j = 4, k = 2;

    printf("Inainte de sortare: i=%d, j=%d, k=%d\n", i, j, k);

    sortare(3, &i, &j, &k);

    printf("Dupa sortare: i=%d, j=%d, k=%d\n", i, j, k);

    return 0;
}*/

/* Aplicații propuse – parametrii în linia de comandă
Aplicația 6.9: Scrieți un program care calculează suma parametrilor primiți din linia de comandă (numere reale).
Exemplu: execuția fără parametri va fișa 0, iar execuția cu parametrii 1.1 6.57 99.122 va afișa 106.792*/
/*
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("0\n");
        return 0;
    }

    double sum = 0.0;

    for (int i = 1; i < argc; i++)
    {
        sum += atof(argv[i]); 
    }

    printf("%.3f\n", sum); 

    return 0;
}*/

/* Aplicația 6.10: Să se scrie un program denumit criptare, care criptează/decriptează un text primit în linia de 
comandă. Programul va fi apelat în felul următor: ./criptare operatie cheie cuvant1 cuvant2 ...
Operația poate fi enc pentru criptare sau dec decriptare. Cheia este un număr întreg. Algoritmul de criptare este 
următorul: pentru fiecare literă din cuvinte se consideră codul său ASCII, la care se adună cheia specificată, 
rezultând un nou cod ASCII, cel al literei criptate. Adunarea este circulară, adică ‘z’ incrementat cu 1 devine ‘a’. 
Decriptarea este inversă: din cuvintele criptate se scade circular cheia specificată. Literele mari se transformă la 
început în litere mici.
Exemple: 
./criptare enc 1 zaraza -> absbab
./criptare dec 1 bcfdfebs -> abecedar
./criptare enc 10 vine VINE primavara PRImaVAra -> fsxo fsxo zbswkfkbk zbswkfkbk*/
/*
void crypt(char *text, int key, char operation)
{
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = ((text[i] - 'A' + key) % 26) + 'A';
            }
            else if (islower(text[i]))
            {
                text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
        }
    }

    if (operation == 'dec')
    {
        key = 26 - key;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    text[i] = ((text[i] - 'A' + key) % 26) + 'A';
                }
                else if (islower(text[i]))
                {
                    text[i] = ((text[i] - 'a' + key) % 26) + 'a';
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Lipsesc argumentele!");
        return 1;
    }

    char *operation = argv[1];
    int key = atoi(argv[2]);

    for (int i = 3; i < argc; i++)
    {
        crypt(argv[i], key, operation[0]);
        printf("%s ", argv[i]);
    }

    printf("\n");

    return 0;
}*/

/* Aplicația 6.11: Un program primește în linia de comandă o expresie formată din numere reale și operatorii {addadunare, sub-scădere, mul-înmulțire, div-împărțire}. Programul va calcula valoarea expresiei și va afișa rezultatul. 
Expresia se calculează de la stânga la dreapta, fără a ține cont de precedența matematică a operatorilor.
Exemplu: ./calcul 10.5 add 1.5 div 3 va afișa: 4 */
/*
double calculate(double a, double b, const char *op)
{
    if (strcmp(op, "add") == 0)
    {
        return a + b;
    }
    else if (strcmp(op, "sub") == 0)
    {
        return a - b;
    }
    else if (strcmp(op, "mul") == 0)
    {
        return a * b;
    }
    else if (strcmp(op, "div") == 0)
    {
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            printf("Eroare: împărțire la zero\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Eroare: operator necunoscut\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4 || argc % 2 == 1)
    {
        printf("Utilizare: ./calcul <număr> <op> <număr> ...\n");
        printf("Operatorii disponibili sunt: add, sub, mul, div\n");
        return 1;
    }

    double result = atof(argv[1]);

    for (int i = 2; i < argc - 1; i += 2)
    {
        double number = atof(argv[i + 1]);
        result = calculate(result, number, argv[i]);
    }

    printf("%.2f\n", result);

    return 0;
}*/

/* Aplicația 6.12: Un program primește în linia de comandă o serie de opțiuni și de cuvinte, mixate între ele. Opțiunile 
specifică operații care se execută asupra cuvintelor. Opțiunile încep cu - (minus) și pot fi: u-transformă toate literele 
cuvintelor în majuscule; f-transformă prima literă în majusculă și următoarele în minuscule; r-inversează literele din 
cuvinte. După fiecare cuvânt se resetează toate opțiunile anterioare. Să se afișeze cuvintele primite în linia de 
comandă cu transformările aplicate.
Exemplu: ./procesare -f mAria -r -u abac va afișa: Maria CABA */
/*
void aplicareOptiune(char *word, char *options)
{
    int upper = 0;
    int firstUpper = 0;
    int reverse = 0;

    while (*options)
    {
        switch (*options)
        {
            case 'u':
                upper = 1;
                firstUpper = 0;
                reverse = 0;
                break;
            case 'f':
                upper = 0;
                firstUpper = 1;
                reverse = 0;
                break;
            case 'r':
                upper = 0;
                firstUpper = 0;
                reverse = 1;
                break;
            default:
                break;
        }
        options++;
    }

    if (upper)
    {
        for (int i = 0; word[i]; i++)
        {
            word[i] = toupper(word[i]);
        }
    }

    if (firstUpper)
    {
        if (islower(word[0]))
        {
            word[0] = toupper(word[0]);
        }
        for (int i = 1; word[i]; i++)
        {
            word[i] = tolower(word[i]);
        }
    }

    if (reverse)
    {
        int start = 0;
        int end = strlen(word) - 1;
        while (start < end)
        {
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;
            start++;
            end--;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Utilizare: ./procesare <opțiuni> <cuvinte> ...\n");
        printf("Opțiunile disponibile sunt: u, f, r\n");
        return 1;
    }

    int optionStart = 1;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            optionStart = i;
        }
        else
        {
            aplicareOptiune(argv[i], argv[optionStart] + 1);
            printf("%s ", argv[i]);
        }
    }

    printf("\n");

    return 0;
}*/


/* Aplicația 6.13: Un program primește în linia de comandă ca prim argument un cod de operație și pe urmă o serie 
de cuvinte. Codul poate fi: 0-afișează numărul total de litere din toate cuvintele: 1-afișează fiecare literă de câte ori 
apare în toate cuvintele.
Exemplu: ./statistica 0 ion merge la film va afișa: 14*/

void printTotalLetters(char *words[], int count)
{
    int totalLetters = 0;
    for (int i = 0; i < count; i++)
    {
        totalLetters += strlen(words[i]);
    }
    printf("%d\n", totalLetters);
}

void printLetterFrequency(char *words[], int count)
{
    int frequency[26] = {0}; // pentru literele de la 'a' la 'z'

    for (int i = 0; i < count; i++)
    {
        char *word = words[i];
        for (int j = 0; j < strlen(word); j++)
        {
            char c = tolower(word[j]);
            if (isalpha(c))
            {
                frequency[c - 'a']++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Utilizare: ./statistica <cod> <cuvinte> ...\n");
        printf("Codurile disponibile sunt: 0, 1\n");
        return 1;
    }

    int code = atoi(argv[1]);

    if (code == 0)
    {
        printTotalLetters(argv + 2, argc - 2);
    }
    else if (code == 1)
    {
        printLetterFrequency(argv + 2, argc - 2);
    }
    else
    {
        printf("Cod de operație invalid.\n");
        return 1;
    }

    return 0;
}












