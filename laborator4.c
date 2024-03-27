#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Probleme ușoare
/* Aplicația 4.0: Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de 
caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.*/
/*
typedef struct{
    char nume[21]; 
    int nota;
}Student;

int main() {
    Student student;

    printf("Introduceti numele studentului: ");
    scanf("%s", &student.nume);
    
    printf("Introduceti nota studentului: ");
    scanf("%d", &student.nota);

    printf("Informatii despre student:\n");
    printf("Nume: %s\n", student.nume);
    printf("Nota: %d\n", student.nota);

    return 0;
}*/

/* Aplicația 4.1: Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de 
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc 
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze 
pe ecran */

/*
struct Fisier{
    char nume[16]; 
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tip_fisier : 1; 
};

int main() {
    struct Fisier fis;
    int  aux1, aux2, aux3;

    printf("Introduceti numele fisierului: ");
    scanf("%s", &fis.nume);
   
    printf("Introduceti dimensiunea fisierului in octeti: ");
    scanf("%d", &aux1);
    fis.dimensiune=aux1;

    printf("Introduceti tipul fisierului (.txt - 0, .doc - 1, .xls - 2): ");
    scanf("%d", &aux2);
    fis.tip=aux2;

    printf("Introduceti tipul fisierului (normal - 0, read-only - 1): ");
    scanf("%d", &aux3);
    fis.tip_fisier=aux3;

 
    printf("Informatii despre fisier:\n");
    printf("Nume: %s\n", fis.nume);
    printf("Dimensiune: %u octeti\n", fis.dimensiune);
    printf("Tip: ");
    switch (fis.tip) {
        case 0:
            printf(".txt\n");
            break;
        case 1:
            printf(".doc\n");
            break;
        case 2:
            printf(".xls\n");
            break;
        default:
            printf("Necunoscut\n");
    }
    printf("Tip fisier: %s\n", fis.tip_fisier ? "Read-only" : "Normal");

    return 0;
}*/

/* Aplicația 4.2: Cu ajutorul structurii de la problema mai sus să se salveze într-un vector de structuri declarat static 
informații despre mai multe fișiere (maxim 10). Să se citească de la tastatură informațiile despre fișiere și să se 
salveze în fișierul memorie.txt. */
/*
struct Fisier {
    char nume[16]; 
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tip_fisier : 1; 
};

int main() {
    
    struct Fisier fis[10] = {0};
    int numar_fisiere, aux1, aux2, aux3;

    printf("Introduceti numarul de fisiere: ");
    scanf("%d", &numar_fisiere);

    if (numar_fisiere < 1 || numar_fisiere > 10) {
        printf("Numarul de fisiere trebuie sa fie intre 1 si 10.\n");
    }

    for (int i = 0; i < numar_fisiere; ++i) {
        printf("Introduceti informatiile despre fisierul %d:\n", i + 1);
        
        printf("Nume: ");
        scanf("%s", fis[i].nume);
        
        printf("Dimensiune (in octeti, maxim 1024 octeti): ");
        scanf("%d", &aux1);
        fis[i].dimensiune=aux1;
        
        printf("Tip (0 pentru .txt, 1 pentru .doc, 2 pentru .xls): ");
        scanf("%d", &aux2);
        fis[i].tip=aux2;
        
        printf("Tip fisier (0 pentru normal, 1 pentru read-only): ");
        scanf("%d", &aux3);
        fis[i].tip_fisier=aux3;
    }

    FILE *f = fopen("memorie.txt", "w");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului pentru scriere.\n");
    }

    for (int i = 0; i < numar_fisiere; ++i) {
        fprintf(f, "Fisier %d:\n", i + 1);
        fprintf(f, "Nume: %s\n", fis[i].nume);
        fprintf(f, "Dimensiune: %u octeti\n", fis[i].dimensiune);
        fprintf(f, "Tip: %s\n", fis[i].tip == 0 ? ".txt" : (fis[i].tip == 1 ? ".doc" : ".xls"));
        fprintf(f, "Tip fisier: %s\n", fis[i].tip_fisier == 0 ? "normal" : "read-only");
        fprintf(f, "\n");
    }

    fclose(f);

    printf("Informatiile despre fisiere au fost salvate in fisierul 'memorie.txt'.\n");

    return 0;
}*/

// Aplicația 4.3: Modificați problema de mai sus astfel încât vectorul de structuri să fie alocat dinamic.
/*
struct Fisier {
    char nume[16]; 
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tip_fisier : 1; 
};

int main() {
    
    int numar_fisiere, aux1, aux2, aux3;

    printf("Introduceti numarul de fisiere: ");
    scanf("%d", &numar_fisiere);

    if (numar_fisiere < 1 || numar_fisiere > 10) {
        printf("Numarul de fisiere trebuie sa fie intre 1 si 10.\n");
    }

    struct Fisier *fis = malloc(numar_fisiere * sizeof(struct Fisier));
    if (fis == NULL) {
        printf("Alocarea dinamica a esuat. Memorie insuficienta.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < numar_fisiere; ++i) {
        printf("Introduceti informatiile despre fisierul %d:\n", i + 1);
        
        printf("Nume: ");
        scanf("%s", fis[i].nume);
        
        printf("Dimensiune (in octeti, maxim 1024 octeti): ");
        scanf("%d", &aux1);
        fis[i].dimensiune=aux1;
        
        printf("Tip (0 pentru .txt, 1 pentru .doc, 2 pentru .xls): ");
        scanf("%d", &aux2);
        fis[i].tip=aux2;
        
        printf("Tip fisier (0 pentru normal, 1 pentru read-only): ");
        scanf("%d", &aux3);
        fis[i].tip_fisier=aux3;
    }
    
    FILE *f = fopen("memorie.txt", "w");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului pentru scriere.\n");
        free(fis);
    }
    
    for (int i = 0; i < numar_fisiere; ++i) {
        fprintf(f, "Fisier %d:\n", i + 1);
        fprintf(f, "Nume: %s\n", fis[i].nume);
        fprintf(f, "Dimensiune: %u octeti\n", fis[i].dimensiune);
        fprintf(f, "Tip: %s\n", fis[i].tip == 0 ? ".txt" : (fis[i].tip == 1 ? ".doc" : ".xls"));
        fprintf(f, "Tip fisier: %s\n", fis[i].tip_fisier == 0 ? "normal" : "read-only");
        fprintf(f, "\n");
    }

    fclose(f);
    free(fis);
    
    printf("Informatiile despre fisiere au fost salvate in fisierul 'memorie.txt'.\n");

    return 0;
}*/

// PROBLEME MEDII

/* Aplicația 4.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre 
animale:
● numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
● greutatea în kg: număr real
● periculos pentru om: da/nu
● abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
● vârsta maximă în ani: număr întreg, minim 0, maxim 2000
Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1, 
“nu”=0. Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. Afişaţi spaţiul de memorie 
ocupat, folosind operatorul sizeof. Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar 
pe urmă afişaţi-le pe ecran. */
/*

struct Animal {
    unsigned int numar_picioare : 10; 
    float greutate; 
    unsigned int periculos_pentru_om : 1; // da - 1, nu - 0
    unsigned int varsta_maxima : 11; 
    char abreviere_specie[9]; 
};

int main() {
    struct Animal animal;
    int aux1, aux2, aux3;
    
    printf("Introduceti numarul de picioare (maxim 1000): ");
    scanf("%d", &aux1);
    animal.numar_picioare=aux1;

    printf("Introduceti greutatea in kg: ");
    scanf("%f", &animal.greutate);

    printf("Este animalul periculos pentru om? (da - 1, nu - 0): ");
    scanf("%d", &aux2);
    animal.periculos_pentru_om=aux2;

    printf("Introduceti varsta maxima in ani (maxim 2000): ");
    scanf("%d", &aux3);
    animal.varsta_maxima=aux3;

    printf("Introduceti abrevierea stiintifica a speciei (maxim 8 caractere): ");
    scanf("%s", animal.abreviere_specie);

    printf("Informatii despre animal:\n");
    printf("Numarul de picioare: %d\n", animal.numar_picioare);
    printf("Greutatea: %.2f kg\n", animal.greutate);
    printf("Periculos pentru om: %s\n", animal.periculos_pentru_om ? "da" : "nu");
    printf("Varsta maxima: %d ani\n", animal.varsta_maxima);
    printf("Abrevierea stiintifica a speciei: %s\n", animal.abreviere_specie);

    // Afișarea spațiului de memorie ocupat de structură
    printf("Spatiul de memorie ocupat de structura Animal: %zu bytes\n", sizeof(animal));

    return 0;
}*/

/* Aplicația 4.5: Să se codifice următoarele informații despre un medicament, astfel încât ele să ocupe în total un 
singur octet. Să se scrie un program care să citească datele unui medicament și ulterior să le afișeze.
● gradul de periculozitate: scăzută, medie, mare
● dacă se eliberează doar pe bază de rețetă: da, nu
● vârsta minimă de administrare: 1...18 ani inclusiv */

/*
struct Medicament {
    unsigned int grad_periculozitate : 2; // scăzută - 0, medie - 1, mare - 2
    unsigned int reteta : 1; // da - 1, nu - 0
    unsigned int varsta_minima : 5; // 1...18 ani inclusiv
};

int main() {
    struct Medicament medicament;
    int aux1, aux2, aux3;

    printf("Introduceti gradul de periculozitate (scăzută - 0, medie - 1, mare - 2): ");
    scanf("%d", &aux1);
    medicament.grad_periculozitate=aux1;

    printf("Se elibereaza doar pe baza de rețetă? (da - 1, nu - 0): ");
    scanf("%d", &aux2);
    medicament.reteta=aux2;

    printf("Introduceti vârsta minimă de administrare (1...18 ani inclusiv): ");
    scanf("%d", &aux3);
    medicament.varsta_minima=aux3;

    printf("Informatii despre medicament:\n");
    switch (medicament.grad_periculozitate) {
        case 0:
            printf("Gradul de periculozitate: scăzută\n");
            break;
        case 1:
            printf("Gradul de periculozitate: medie\n");
            break;
        case 2:
            printf("Gradul de periculozitate: mare\n");
            break;
        default:
            printf("Grad de periculozitate necunoscut\n");
    }
    printf("Eliberare doar pe baza de rețetă: %s\n", medicament.reteta ? "da" : "nu");
    printf("Vârsta minimă de administrare: %d ani\n", medicament.varsta_minima);

    return 0;
}*/

/* Aplicația 4.6: Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și multiplicatorul 
acesteia (pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga). 
● Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval 
cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia. O măsurătoare va ocupa exact 2 
octeți.
● Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. Să se determine 
multiplicatorul astfel încât valoarea stocată să fie cât mai mică, fără a se pierde precizie, iar apoi să se 
stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile 
măsurătorii. */

struct Masuratoare {
    unsigned char valoare; 
    unsigned char unitate_multiplicator; 
};

unsigned char determina_multiplicator(unsigned int valoare) {
    if (valoare < 100) {
        return 0; // pico
    } else if (valoare < 1000) {
        return 1; // nano
    } else if (valoare < 10000) {
        return 2; // mili
    } else if (valoare < 100000) {
        return 3; // centi
    } else if (valoare < 1000000) {
        return 4; // deci
    } else if (valoare < 10000000) {
        return 5; // deca
    } else if (valoare < 100000000) {
        return 6; // hecto
    } else if (valoare < 1000000000) {
        return 7; // kilo
    } else if (valoare < 10000000000) {
        return 8; // mega
    } else {
        return 9; // giga
    }
}

void afiseaza_masuratoare(struct Masuratoare masuratoare) {
    const char *multiplicatori[] = {"pico", "nano", "mili", "centi", "deci", "deca", "hecto", "kilo", "mega", "giga"};
    const char *unitati[] = {"gram", "metru", "litru"};

    printf("Valoare: %d\n", masuratoare.valoare);
    printf("Unitate de masura: %s\n", unitati[masuratoare.unitate_multiplicator % 3]);
    printf("Multiplicator: %s\n", multiplicatori[masuratoare.unitate_multiplicator / 3]);
}

int main() {
    struct Masuratoare masuratoare;
    unsigned int valoare;
    unsigned char multiplicator;


    printf("Introduceti valoarea: ");
    scanf("%d", &valoare);
    multiplicator = determina_multiplicator(valoare);

    if (multiplicator > 7) {
        printf("Eroare: Valoarea este prea mare pentru a fi reprezentata intr-o masuratoare.\n");
        return 1;
    }

    masuratoare.valoare = valoare;
    masuratoare.unitate_multiplicator = multiplicator * 3; 

    printf("Masuratoare citita:\n");
    afiseaza_masuratoare(masuratoare);

    return 0;
}


    
    
    
