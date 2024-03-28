#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Subiectul 1: Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un 
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1 
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite 
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să 
fie minim.*/
/*
#define MAX 1000
struct Masina {
    unsigned int cod_masina : 13; // număr între 1 și 9000
    unsigned int numar_locuri : 3; // între 1 și 9
    unsigned int putere : 9; //  cai putere între 1 și 500
    unsigned int an_fabricatie : 8; // între 1800 și 2017
    char marca[21];  
    char culoare[21]; 
};

int numar_masini = 0;
struct Masina parc[MAX]; 

void introducere_automobil() {
    int aux1, aux2, aux3, aux4;
    if (numar_masini < MAX) {
        printf("Codul masinii (intre 1 si 9000): ");
        scanf("%d", &aux1);
        parc[numar_masini].cod_masina=aux1;
        
        printf("Numarul de locuri (intre 1 si 9): ");
        scanf("%u", &aux2);
        parc[numar_masini].numar_locuri=aux2;
        
        printf("Puterea (intre 1 si 500 cai putere): ");
        scanf("%u", &aux3);
        parc[numar_masini].putere=aux3;
        
        printf("Anul fabricatiei (intre 1800 si 2017): ");
        scanf("%u", &aux4);
        parc[numar_masini].putere=aux4;
        
        printf("Marca: ");
        scanf("%s", parc[numar_masini].marca);
        
        printf("Culoarea: ");
        scanf("%s", parc[numar_masini].culoare);

        numar_masini++;
        
        printf("Automobilul a fost adaugat cu succes!\n");
        
    } else {
        printf("Nu mai este loc in parc pentru adaugarea unui nou automobil.\n");
    }
}

void stergere_automobil() {
    unsigned int cod;
    printf("Introduceti codul masinii pe care doriti sa o stergeti: ");
    scanf("%d", &cod);

    int gasit = 0;
    for (int i = 0; i < numar_masini; i++) {
        if (parc[i].cod_masina == cod) {
            gasit = 1;
            for (int j = i; j < numar_masini - 1; j++) {
                parc[j] = parc[j + 1];
            }
            numar_masini--;
            printf("Automobilul a fost sters cu succes!\n");
            break;
        }
    }
    if (!gasit) {
        printf("Nu a fost gasit niciun automobil cu codul %d.\n", cod);
    }
}

void afisare_lista() {
    printf("Lista automobilelor din parc:\n");
    for (int i = 0; i < numar_masini; i++) {
        printf("Automobil %d:\n", i + 1);
        printf("Cod masina: %d\n", parc[i].cod_masina);
        printf("Numar locuri: %d\n", parc[i].numar_locuri);
        printf("Putere: %d cai putere\n", parc[i].putere);
        printf("An fabricatie: %d\n", parc[i].an_fabricatie);
        printf("Marca: %s\n", parc[i].marca);
        printf("Culoare: %s\n", parc[i].culoare);
        printf("\n");
    }
}

void afisare_numar_locuri() {
    unsigned int locuri;
    printf("Introduceti numarul de locuri pentru care doriti sa afisati automobilele: ");
    scanf("%d", &locuri);

    printf("Automobilele cu %d locuri sunt:\n", locuri);
    for (int i = 0; i < numar_masini; i++) {
        if (parc[i].numar_locuri == locuri) {
            printf("Cod masina: %d, Marca: %s, Culoare: %s, Putere: %d cai putere, An fabricatie: %d\n", parc[i].cod_masina, parc[i].marca, parc[i].culoare, parc[i].putere, parc[i].an_fabricatie);
        }
    }
}

int comparare_an_fabricatie(const void *a, const void *b) {
    return ((struct Masina *)a)->an_fabricatie - ((struct Masina *)b)->an_fabricatie;
}

void ordonare_an_fabricatie() {
    qsort(parc, numar_masini, sizeof(struct Masina), comparare_an_fabricatie);
    printf("Lista de automobile a fost ordonata in functie de anul fabricatiei.\n");
}

int main() {
    int optiune;
    
    printf("------------------------------------------------------\n");
    printf("1. Introducere automobil nou.\n");
    printf("2. Stergere automobil.\n");
    printf("3. Afisare lista automobilelor.\n");
    printf("4. Afisare automobile cu un anumit numar de locuri.\n");
    printf("5. Ordonare lista dupa anul fabricatiei.\n");
    printf("6. Iesire.\n");
    printf("------------------------------------------------------\n");
    

    do {
        printf("Alegeti optiunea:\n");
        scanf("%d", &optiune);
        switch (optiune) {
            case 1:
                introducere_automobil();
                    break;
            case 2:
                stergere_automobil();
                break;
            case 3:
                afisare_lista();
                break;
            case 4:
                afisare_numar_locuri();
                break;
            case 5:
                ordonare_an_fabricatie();
                break;
            case 6:
                printf("Programul s-a terminat.\n");
                break;
            default:
                printf("Optiune invalida. Va rugam selectati o optiune valida.\n");
        }
    } while (optiune != 6);

    return 0;
}*/
/* Subiectul 2: Să se realizeze o aplicaţie pentru gestionarea unei biblioteci folosind struct și union, iar dacă e 
posibil și structuri cu câmpuri pe biți.
Se vor memora următoarele informaţii pentru fiecare înregistrare:
 Titlu
 Autor
 Număr de exemplare
 Preț (exprimat în lei, număr întreg, maxim 500 lei)
 Număr de pagini (maxim 1000 pagini)
 Greutate (exprimată în grame, maxim 5000 grame)
 Dacă e Carte sau Revistă
 Dacă e carte se va memora ISBN, sir de 13 caractere, exemplu: 9783161484100, iar dacă e revistă se va 
memora anul în care a apărut primul număr.
Folosind un meniu să se realizeze următoarele operaţii:
a) Introduceţi un produs.
b) Afişaţi toate publicaţiile aflate în stoc care sunt cărţi si au preţul peste 100.
c) Afişaţi toate înregistrările.
d) Salvaţi toate publicatiile - Toate produsele se vor salva într-un fişier binar (inventar.bin) folosind structura 
creată anterior.
Datele de intrare se vor citi de la tastatură */
// Definirea constantei pentru numărul maxim de caractere pentru titlu și autor
#define MAX 100

struct Carte {
    char titlu[MAX];
    char autor[MAX];
    int numar_exemplare;
    int pret;
    int numar_pagini : 10; // maxim 1000 pagini
    int greutate : 13; // maxim 5000 grame
    unsigned int este_carte : 1; // 0 - revistă, 1 - carte
    union {
        char ISBN[14]; 
        int an_aparitie_revista; 
    } detalii;
};

void introducere_publicatie(struct Carte *biblioteca, int *numar_publicatii) {
    int aux1, aux2, aux3;
    printf("Introduceti informatiile despre publicatie:\n");
    
    printf("Titlu: ");
    scanf("%s", biblioteca[*numar_publicatii].titlu);
    
    printf("Autor: ");
    scanf("%s", biblioteca[*numar_publicatii].autor);
    
    printf("Numar exemplare: ");
    scanf("%d", &biblioteca[*numar_publicatii].numar_exemplare);
    
    printf("Pret (maxim 500 lei): ");
    scanf("%d", &biblioteca[*numar_publicatii].pret);
    
    printf("Numar pagini (maxim 1000 pagini): ");
    scanf("%d", &aux1);
    biblioteca[*numar_publicatii].numar_pagini=aux1;
    
    printf("Greutate (maxim 5000 grame): ");
    scanf("%d", &aux2);
    biblioteca[*numar_publicatii].greutate=aux2;

    printf("Este carte sau revista? (0 - revista, 1 - carte): ");
    scanf("%d", &aux3);
    biblioteca[*numar_publicatii].este_carte = aux3;

    if (aux3) {
        printf("ISBN (13 caractere): ");
        scanf("%s", biblioteca[*numar_publicatii].detalii.ISBN);
    } else {
        printf("An aparitie revista: ");
        scanf("%d", &biblioteca[*numar_publicatii].detalii.an_aparitie_revista);
    }

    (*numar_publicatii)++;
    printf("Publicatia a fost adaugata cu succes!\n");
}


void afisare_carti_cu_pret_mare(struct Carte *biblioteca, int numar_publicatii) {
    printf("Cartile aflate in stoc cu pretul peste 100 lei sunt:\n");
    for (int i = 0; i < numar_publicatii; i++) {
        if (biblioteca[i].este_carte && biblioteca[i].pret > 100) {
            printf("Titlu: %s, Autor: %s, Pret: %d lei\n", biblioteca[i].titlu, biblioteca[i].autor, biblioteca[i].pret);
        }
    }
}


void afisare_inregistrari(struct Carte *biblioteca, int numar_publicatii) {
    printf("Toate publicatiile din biblioteca sunt:\n");
    for (int i = 0; i < numar_publicatii; i++) {
        printf("Titlu: %s, Autor: %s, Pret: %d lei, Numar exemplare: %d\n", biblioteca[i].titlu, biblioteca[i].autor, biblioteca[i].pret, biblioteca[i].numar_exemplare);
    }
}

void salvare_publicatii(struct Carte *biblioteca, int numar_publicatii) {
    FILE *f;
    f = fopen("inventar.bin", "wb");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        exit(EXIT_FAILURE);
    }

    fwrite(biblioteca, sizeof(struct Carte), numar_publicatii, f);
    fclose(f);
    printf("Publicatiile au fost salvate cu succes in fisierul inventar.bin.\n");
}

int main() {
    struct Carte biblioteca[1000]; 
    int numar_publicatii = 0;
    int optiune;
    
    printf("--------------------------------------------------------------------------------------------\n");
    printf("a) Introduceţi un produs.\n");
    printf("b) Afişaţi toate publicaţiile aflate în stoc care sunt cărţi si au preţul peste 100.\n");
    printf("c) Afişaţi toate înregistrările.\n");
    printf("d) Salvaţi toate publicatiile.\n");
    printf("e) Ieşire.\n");
    printf("--------------------------------------------------------------------------------------------\n");
    do {
        printf("Alegeti optiunea:\n");
        scanf(" %c", &optiune);
        switch (optiune) {
            case 'a':
                introducere_publicatie(biblioteca, &numar_publicatii);
                break;
            case 'b':
                afisare_carti_cu_pret_mare(biblioteca, numar_publicatii);
                break;
            case 'c':
                afisare_inregistrari(biblioteca, numar_publicatii);
                break;
            case 'd':
                salvare_publicatii(biblioteca, numar_publicatii);
                break;
            case 'e':
                printf("Programul s-a terminat.\n");
                break;
            default:
                printf("Optiune invalida. Va rugam selectati o optiune valida.\n");
        }
    } while (optiune != 'e');

    return 0;
}

