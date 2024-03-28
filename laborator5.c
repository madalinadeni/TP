#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Aplicația 5.2: Scrieți un program care copiază conținutul unui fișier sursă într-un fișier destinație. Numele fișierelor se citesc din linia de comandă. Pentru eficiența copierii, programul va citi câte un bloc de maxim 4096 de octeți, pe care îl va scrie în destinație.
Exemplu: ./copiere src.dat dst.dat                    -> copiază src.dat în dst.dat */
/*
#define MAX_BLOCK_SIZE 4096
int main(int argc, char *argv[]) {
    FILE *src, *dst;
    char buffer[MAX_BLOCK_SIZE];
    size_t bytes_read;

    if (argc != 3) {
        printf("Mod de utilizare: %s <fisier_sursa> <fisier_destinatie>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "rb");
    if (src == NULL) {
        printf("Eroare la deschiderea fișierului sursă.\n");
        return 1;
    }

    dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        printf("Eroare la deschiderea fișierului destinație.\n");
        fclose(src);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, MAX_BLOCK_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dst);
    }
    
    fclose(src);
    fclose(dst);

    printf("Copierea s-a încheiat cu succes.\n");

    return 0;
}*/

/* Aplicația 5.3: Se citesc m și n de la tastatură, iar apoi o matrice a[m][n] cu elemente de tip întreg.
Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele, 
așa cum sunt dispuse ele în memorie. Să se citească matricea din fișier într-o variabilă b și să se afișeze.*/
/*
#define MAX 100

void scrie_matrice_binar(int a[MAX][MAX], int m, int n, char *nume_fisier) {
    FILE *f;
    f = fopen(nume_fisier, "wb");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului pentru scriere!\n");
        return;
    }

    fwrite(&m, sizeof(int), 1, f);
    fwrite(&n, sizeof(int), 1, f);
    
    fwrite(a, sizeof(int), m * n, f);
    
    fclose(f);
}

void citeste_matrice_binar(int b[MAX][MAX], char *nume_fisier) {
    FILE *f;
    int m, n;
    
    f = fopen(nume_fisier, "rb");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului pentru citire!\n");
        return;
    }

    fread(&m, sizeof(int), 1, f);
    fread(&n, sizeof(int), 1, f);

    fread(b, sizeof(int), m * n, f);

    fclose(f);

    printf("Matricea citita din fisier este:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, matrice[MAX][MAX];

    printf("Introduceti numarul de linii al matricei: ");
    scanf("%d", &m);
    
    printf("Introduceti numarul de coloane al matricei: ");
    scanf("%d", &n);

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elementul [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    scrie_matrice_binar(matrice, m, n, "matrice.bin");
    
    int matrice_citita[100][100];
    citeste_matrice_binar(matrice_citita, "matrice.bin");

    return 0;
}*/

/* Aplicația 5.4: Să se modifice exemplul 4, astfel încât la începutul fișierului să fie scris numărul de produse. 
Citirea va fi modificată pentru a folosi această informație, în loc de a se testa sfârșitul de fișier.*/
/*
#define MAX_PRODUSE 100 

typedef struct {
    char *nume;
    float pret;
} Produs;

Produs produse[MAX_PRODUSE];
unsigned short nProduse = 0;

void scriere() {
    FILE *fis;
    fis = fopen("produse.dat", "wb");
    if (fis == NULL) {
        printf("Eroare la deschiderea fisierului pentru scriere!\n");
        return;
    }

    fwrite(&nProduse, sizeof(unsigned short), 1, fis);

    for (int i = 0; i < nProduse; i++) {
        unsigned short nNume = strlen(produse[i].nume);
        fwrite(&nNume, sizeof(unsigned short), 1, fis); 
        fwrite(produse[i].nume, sizeof(char), nNume, fis); 
        fwrite(&produse[i].pret, sizeof(float), 1, fis);
    }
    fclose(fis);
}

void citire() {
    FILE *fis;
    fis = fopen("produse.dat", "rb");
    if (fis == NULL) {
        printf("Eroare la deschiderea fisierului pentru citire!\n");
        return;
    }

   
    fread(&nProduse, sizeof(unsigned short), 1, fis);

    for (int i = 0; i < nProduse; i++) {
        unsigned short nNume;
        fread(&nNume, sizeof(unsigned short), 1, fis); 
        char *pNume = (char*)malloc((nNume + 1) * sizeof(char)); 
        if (pNume == NULL) {
            printf("Memorie insuficienta\n");
            fclose(fis);
            exit(EXIT_FAILURE);
        }
        fread(pNume, sizeof(char), nNume, fis); 
        pNume[nNume] = '\0'; 
        produse[i].nume = pNume;
        fread(&produse[i].pret, sizeof(float), 1, fis); 
    }
    fclose(fis);
}

void afisare() {
    printf("Produse disponibile:\n");
    for (int i = 0; i < nProduse; i++) {
        printf("Produs %d: Nume: %s, Pret: %.2f\n", i + 1, produse[i].nume, produse[i].pret);
    }
}

void adaugare() {
    if (nProduse >= MAX_PRODUSE) {
        printf("Numarul maxim de produse a fost atins!\n");
        return;
    }

    printf("Introduceti numele produsului: ");
    char nume[100];
    fgets(nume, sizeof(nume), stdin);
    nume[strcspn(nume, "\n")] = '\0'; 

    printf("Introduceti pretul produsului: ");
    float pret;
    scanf("%f", &pret);
    getchar(); 

    produse[nProduse].nume = strdup(nume);
    produse[nProduse].pret = pret;
    nProduse++;
    printf("Produs adaugat cu succes!\n");
}

int main() {
    int optiune;

    citire(); 
    printf("------------------------------\n");
    printf("1. Adaugare produs\n");
    printf("2. Afisare produse\n");
    printf("3. Scriere baza de date\n");
    printf("4. Iesire\n");
    printf("------------------------------\n");
    do {
        printf("Optiune: ");
        scanf("%d", &optiune);
        getchar(); 
        switch(optiune) {
            case 1:
                adaugare();
                break;
            case 2:
                afisare();
                break;
            case 3:
                scriere();
                break;
            case 4:
                printf("Iesire din program.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }
    } while(optiune != 4);

    return 0;
}*/

/* Aplicația 5.5: Să se scrie un program similar cu hexdump, care primește un nume de fișier în linia de comandă, 
citește câte 16 octeți din el și îi afișează pe câte o linie. Fiecare linie începe cu offsetul ei în fișier, afișat în hexazecimal
pe 8 cifre cu 0 în față, după care valorile hexa ale celor 16 octeți pe câte 2 cifre și în final caracterele. 
Dacă codul unui caracter este în intervalul 32-255 se va afișa ca atare, altfel se va afișa un punct în locul său. 
Dacă ultima linie este incompletă, se va completa cu octeți de 0.*/

/*
#define BUFFER_SIZE 16

void print_hexdump(const char *fn) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes;
    long offset = 0;
    
    FILE *f = fopen(fn, "rb");
    if(f == 0){
        printf("Fisierul nu se poate deschide!\n");
        exit(EXIT_FAILURE);
    }

    while (bytes = fread(buffer, 1, BUFFER_SIZE, f) > 0) {
        printf("%08zx  ", offset); 
        for (size_t i = 0; i < BUFFER_SIZE; i++) {
            if (i < bytes) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   ");
            }
            
            printf(" ");
        }
        
        for (size_t i = 0; i < bytes; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 255) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");
        offset = offset + bytes;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Spatiu: %s <nume_fisier>\n", argv[0]);
        return 1;
    }
    print_hexdump(argv[1]);

    return 0;
}*/

/* Aplicația 5.6: Să se scrie un program care primește 2 fișiere în linia de comandă și le compară între ele. 
Pentru fiecare octet diferit găsit, se afișează offsetul acestuia și valorile sale din fiecare fișier, în hexazecimal, pe câte 2 cifre.
Dacă fișierele sunt de dimensiuni diferite, în final se vor afișa toți octeții din fișierul mai mare. 
Dacă fișierele sunt identice, programul nu va afișa nimic. */
/*
void comparare_fisiere(FILE *f1, FILE *f2) {
    unsigned char byte1, byte2;
    size_t offset = 0;

    while (!feof(f1) && !feof(f2)) {
        fread(&byte1, 1, 1, f1);
        fread(&byte2, 1, 1, f2);
        
        if (byte1 != byte2) {
            printf("Offset: %zu, Fisier1: %02x, Fisier2: %02x\n", offset, byte1, byte2);
        }
        
        offset++;
    }

    while (!feof(f1)) {
        fread(&byte1, 1, 1, f1);
        printf("Offset: %zu, Fisier1: %02x, Fiser2: <EOF>\n", offset, byte1);
        offset++;
    }

    while (!feof(f2)) {
        fread(&byte2, 1, 1, f2);
        printf("Offset: %zu, Fisier1: <EOF>, Fisier2: %02x\n", offset, byte2);
        offset++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Spatiu: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    if (f1 == NULL) {
        printf("Fisierul %s nu s-a putut deschide!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *f2 = fopen(argv[2], "rb");
    if (f2 == NULL) {
        printf("Fisierul %s nu s-a putut deschide!\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    comparare_fisiere(f1, f2);

    fclose(f1);
    fclose(f2);

    return 0;
}*/

/* Aplicația 5.7: Un program primește în linia de comandă un nume de fișier, un offset dat în hexazecimal și apoi o serie de octeți, 
specificați tot în hexazecimal. Programul va scrie în fișierul specificat, începând de la offsetul dat toți octeții primiți în linia de
comandă. Restul fișierului va rămâne nemodificat.
Exemplu: ./inlocuire 1.dat 4a0f 9e b0 51          -> scrie octeții {9e, b0, 51} în fișierul 1.dat, începând cu poziția 4a0f*/

/*
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Spatiu: %s <nume_fisier> <offset> <bytes>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb+");
    if (f== NULL) {
        printf("Fisierul %s nu s-a putut deschide!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    long offset = strtol(argv[2], NULL, 16);
    fseek(f, offset, SEEK_SET);

    for (int i = 3; i < argc; i++) {
        unsigned char byte = (unsigned char)strtol(argv[i], NULL, 16);
        fwrite(&byte, sizeof(unsigned char), 1, f);
    }

    fclose(f);

    return 0;
}*/

/* Aplicația 5.8: Să se scrie un program care primește în linia de comandă un nume de fișier și o serie de octeți, dați în hexazecimal. 
Programul va afișa toate pozițiile din fișier la care se află secvența de octeți specificați.
Exemplu: ./cautare 1.dat 01 aa b2 45        -> caută în fișierul 1.dat secvența {01, aa, b2, 45} și afișează toate pozițiile 
la care o găsește */
/*
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Spatiu: %s <nume_fisier> <bytes>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Fisierul %s nu se poate deschide!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    char *sir = malloc((argc - 2) * sizeof(char));
    if(sir == NULL) {
        printf("Nu s-a putut aloca memorie dinamica!\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++) {
        sir[i - 2] = (char)strtol(argv[i], NULL, 16);
    }

    
    unsigned char buffer[BUFFER_SIZE];
    size_t pozitie = 0;
    size_t lungimeSir = argc - 2;
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, f)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == sir[0]) {
                if (memcmp(&buffer[i], sir, lungimeSir) == 0) {
                    printf("Sirul a fost gasit la pozitia: %zu\n", pozitie + i);
                }
            }
        }
        pozitie = pozitie + bytesRead;
    }

    free(sir);
    fclose(f);

    return 0;
}*/

/* Aplicația 5.9: Să se scrie un program care primește o serie de n programe în linia de comandă și le concatenează pe primele n-1 
într-un nou fișier având numele specificat pe ultima poziție din linia de comandă.
Exemplu: ./concat 1.dat 2.dat 3.dat rez.dat       -> concatenează conținutul fișierelor {1.dat, 2.dat, 3.dat} într-un nou fișier, 
denumit rez.dat */


int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Spatiu: %s <fisier1> <fisier2> ... <fisierN>\n", argv[0]);
        return 1;
    }

    FILE *fout = fopen(argv[argc - 1], "wb");
    if (fout == NULL) {
        printf("Fisierul %s nu s-a putut deschide!\n", argv[argc - 1]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc - 1; i++) {
        FILE *f = fopen(argv[i], "rb");
        if (f == NULL) {
            printf("Fisierul %s nu s-a putut deschide!\n", argv[i]);
            fclose(fout);
            exit(EXIT_FAILURE);
        }

        int c;
        while ((c = fgetc(f)) != EOF) {
            fputc(c, fout);
        }

        fclose(f);
    }

    fclose(fout);

    printf("Fisierle s-au concatenat cu succes!\n");

    return 0;
}










