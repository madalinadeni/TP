#include <stdio.h>
#include <stdlib.h>

/* Aplicația 9.1: Din fisierul date.in se citeste un numar natural k si apoi de pe a doua linie numere intregi. Contruiti 
o lista liniara simplu inlantuita care sa contina numerele intregi citite in ordinea din fisier.
Permutati lista cu k pozitii spre stanga si afisati valorile din lista.
Indicatie: se vor scrie si folosi functii pentru adaugarea unei valori la sfarsitul listei si pentru stergerea primului nod 
al listei si vor fi folosite pentru permuarea ceruta.
Exemplu:
date.in
3
1 2 3 4
date.out
4 1 2 3 */

/*
typedef struct Nod {
    int val;
    struct Nod* urm;
} Nod;

void adaugaSfarsit(Nod **cap, int val) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (*cap == NULL) {
        *cap = nou;
        return;
    }

    Nod *temp = *cap;
    while (temp->urm != NULL) {
        temp = temp->urm;
    }

    temp->urm = nou;
}

void stergePrimul_Nod(Nod **cap) {
    if (*cap == NULL) {
        return;
    }

    Nod *temp = *cap;
    *cap = (*cap)->urm;
    free(temp);
}

void permuta(Nod **cap, int k) {
    if (*cap == NULL) {
        return;
    }

    while (k > 0) {
        adaugaSfarsit(cap, (*cap)->val);
        stergePrimul_Nod(cap);
        k--;
    }
}


void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

int main() {
    FILE *f = fopen("date.in.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului");
        exit(EXIT_FAILURE);
    }

    int k;
    fscanf(f, "%d", &k);

    Nod *cap = NULL;
    int val;
    while (fscanf(f, "%d", &val) == 1) {
        adaugaSfarsit(&cap, val);
    }

    fclose(f);

    permuta(&cap, k);
    afiseazaLista(cap);

    while (cap != NULL) {
        stergePrimul_Nod(&cap);
    }

    return 0;
}*/

/* Aplicația 9.2: Se citesc numere intregi dintr-un fisier text. Sa se creeze 2 liste care sa contina in ordine elementele 
din fisier, una elementele pare, iar cealalta pe cele impare.
Sa se adauge la sfarsitul listei cu elemente pare lista cu elemente impare.*/
/*
typedef struct Nod {
    int val;
    struct Nod* urm;
} Nod;

void adaugaSfarsit(Nod **cap, int val) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (*cap == NULL) {
        *cap = nou;
        return;
    }

    Nod *temp = *cap;
    while (temp->urm != NULL) {
        temp = temp->urm;
    }

    temp->urm = nou;
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

int main() {
    FILE* f = fopen("numere.txt", "r");
    if (f == NULL) {
        printf("Eroare deschidere fisier");
        exit(EXIT_FAILURE);
    }

    Nod *listaPare = NULL;
    Nod *listaImpare = NULL;
    int val;

    while (fscanf(f, "%d", &val) == 1) {
        if (val % 2 == 0) {
            adaugaSfarsit(&listaPare, val);
        } else {
            adaugaSfarsit(&listaImpare, val);
        }
    }

    fclose(f);

    if (listaPare == NULL) {
        listaPare = listaImpare;
    } else {
        Nod* temp = listaPare;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = listaImpare;
    }

    printf("Lista cu numere pare: ");
    afiseazaLista(listaPare);

    while (listaPare != NULL) {
        Nod *temp = listaPare;
        listaPare = listaPare->urm;
        free(temp);
    }

    return 0;
}*/


/* Aplicația 9.3: Se considera o lista liniara simplu inlantuita care memoreaza valori intregi. Sa se scrie o functie care 
primeste ca parametru adresa primului nod al listei si insereaza dupa fiecare nod care memoreaza o valoare para 
un nod care sa memoreze jumatate din valoare acestuia.*/
/*
typedef struct Nod {
    int val;
    struct Nod *urm;
} Nod;

void adaugaDupaPar(Nod *nod) {
    if (nod == NULL) {
        return;
    }

    if (nod->val % 2 == 0) {
        Nod *nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) {
            printf("Eroare la alocarea memoriei");
            exit(EXIT_FAILURE);
        }
        nou->val = nod->val / 2;
        nou->urm = nod->urm;
        nod->urm = nou;

        
        adaugaDupaPar(nod->urm);
    } else {
        
        adaugaDupaPar(nod->urm);
    }
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;

    for (int i = 10; i >= 1; i--) {
        Nod *nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) {
            printf("Eroare la alocarea memoriei");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = cap;
        cap = nou;
    }

    printf("Lista initiala este: ");
    afiseazaLista(cap);


    adaugaDupaPar(cap);

    printf("Lista modificata este: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.4: Se considera o lista liniara dublu inlantuita cu numar par de noduri. Sa se scrie o functie care 
primeste ca parametru adresa primului nod al listei si interschimba primul nod cu cel de-al doilea, al treilea cu cel 
de-al patrulea si asa mai departe.*/
/*
typedef struct Nod {
    int val;
    struct Nod *urm;
    struct Nod *pred;
} Nod;

void interschimbaPerechi(Nod *cap) {
    if (cap == NULL || cap->urm == NULL) {
        return; 
    }

    Nod *prim = cap;
    Nod *alDoilea = prim->urm;

    while (prim && alDoilea) {
        int temp = prim->val;
        prim->val = alDoilea->val;
        alDoilea->val = temp;

        if (alDoilea->urm && alDoilea->urm->urm) {
            prim = alDoilea->urm;
            alDoilea = prim->urm;
        } else {
            break; 
        }
    }
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;
    Nod *ultim = NULL;

    for (int i = 1; i <= 10; i++) {
        Nod *nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) {
            printf("Eroare la alocarea memoriei");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;

        if (ultim == NULL) {
            cap = nou;
        } else {
            ultim->urm = nou;
        }
        ultim = nou;
    }

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    interschimbaPerechi(cap);

    printf("Lista modificata este: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.5: Se considera o lista liniara dublu inlantuita. Sa se scrie o functie care primeste ca parametru adresa 
primului nod al listei si sterge primul si ultimul nod din lista */
/*
typedef struct Nod {
    int val;
    struct Nod *urm;
    struct Nod *pred;
} Nod;

void stergePrimUltim(Nod **cap) {
    if (*cap == NULL || (*cap)->urm == NULL) {
        return;
    }

    Nod *prim = *cap;
    Nod *ultim = prim;

    while (ultim->urm != NULL) {
        ultim = ultim->urm;
    }

    *cap = prim->urm;

  
    if (prim->urm) {
        prim->urm->pred = NULL;
    }
    free(prim);

    if (ultim->pred) {
        ultim->pred->urm = NULL;
    }
    free(ultim);
}


void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;
    Nod *ultim = NULL;

    for (int i = 1; i <= 10; i++) {
        Nod *nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) {
            printf("Eroare la alocarea memoriei");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;

        if (ultim == NULL) {
            cap = nou;
        } else {
            ultim->urm = nou;
        }
        ultim = nou;
    }

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    stergePrimUltim(&cap);

    printf("Lista modificata este: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.6: Se considera o lista liniara dublu inlantuita. Sa se scrie o functie care primeste ca parametru adresa 
primului nod al listei si muta ultimul nod in fata primului*/
/*
typedef struct Nod {
    int val;
    struct Nod *urm;
    struct Nod *pred;
} Nod;

void mutaUltimInFata(Nod **cap) {
    if (*cap == NULL || (*cap)->urm == NULL) {
        return;
    }

    Nod *ultim = *cap;
    while (ultim->urm != NULL) {
        ultim = ultim->urm;
    }

    
    ultim->urm = *cap;
    (*cap)->pred = ultim;

  
    *cap = ultim->urm;
    (*cap)->pred = NULL;

   
    ultim->urm = NULL;
}


void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}


void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    
    Nod *cap = NULL;
    Nod *ultim = NULL;

   
    for (int i = 1; i <= 10; i++) {
        Nod *nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) {
            printf("Eroare la alocarea memoriei");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;

        if (ultim == NULL) {
            cap = nou;
        } else {
            ultim->urm = nou;
        }
        ultim = nou;
    }

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    mutaUltimInFata(&cap);

    printf("Lista modificata este: ");
    afiseazaLista(cap);
    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.7: Se considera o lista liniara dublu inlantuita ale carei noduri sunt memorare cifre. Sa se scrie o functie 
care primeste ca parametru adresa primului nod al listei si verifica daca numarul care se compune din cifrele 
memorare in lista in ordine este sau nu palindrom. Functia va returna 1 daca este palindrom si 0 in caz contrar.*/
/*

typedef struct Nod {
    int cifra;
    struct Nod *urm;
    struct Nod *pred;
} Nod;


void adaugaNodSfarsit(Nod **cap, int cifra) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Eroare la alocarea memoriei");
        exit(EXIT_FAILURE);
    }
    nou->cifra = cifra;
    nou->urm = NULL;
    nou->pred = NULL;

    if (*cap == NULL) {
        *cap = nou;
    } else {
        Nod *temp = *cap;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = nou;
        nou->pred = temp;
    }
}


int estePalindrom(Nod *cap) {
    Nod *stanga = cap;
    Nod *dreapta = cap;

   
    while (dreapta->urm != NULL) {
        dreapta = dreapta->urm;
    }

    while (stanga != dreapta && dreapta->urm != stanga) {
        if (stanga->cifra != dreapta->cifra) {
            return 0; 
        }
        stanga = stanga->urm;
        dreapta = dreapta->pred;
    }

    return 1; 
}


void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->cifra);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;

 
    int cifra;
    printf("Introduceti cifrele pentru lista: ");
    while (1) {
        scanf("%d", &cifra);
        if (cifra == 0) {
            break;
        }
        adaugaNodSfarsit(&cap, cifra);
    }

    printf("Lista introdusa este: ");
    afiseazaLista(cap);

   
    if (estePalindrom(cap)) {
        printf("Numarul format este palindrom.\n");
    } else {
        printf("Numarul format nu este palindrom.\n");
    }

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.8: Sa se scrie o functie care primeste ca parametru adresa primului nod al unei liste liniare simplu 
inlantuite cu cel putin 3 noduri si muta primul nod al listei dupa ultimul nod al listei*/
/*
typedef struct Nod {
    int valoare;
    struct Nod *urm;
} Nod;


void adaugaNodSfarsit(Nod **cap, int valoare) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Eroare la alocarea memoriei");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) {
        *cap = nou;
    } else {
        Nod *temp = *cap;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void mutaPrimulDupaUltimul(Nod **cap) {
    if (*cap == NULL || (*cap)->urm == NULL || (*cap)->urm->urm == NULL) {
        printf("Lista nu are suficiente noduri pentru a efectua mutarea.\n");
        return;
    }

    Nod *temp = *cap;
    *cap = (*cap)->urm;

    Nod *ultim = *cap;
    while (ultim->urm != NULL) {
        ultim = ultim->urm;
    }

    ultim->urm = temp;
    temp->urm = NULL;
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;

    adaugaNodSfarsit(&cap, 6);
    adaugaNodSfarsit(&cap, 1);
    adaugaNodSfarsit(&cap, 5);
    adaugaNodSfarsit(&cap, 9);

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    
    mutaPrimulDupaUltimul(&cap);

    printf("Lista dupa mutare este: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.9: Sa se construiasca o lista liniara simplu inlantuita cu elemente numere intregi. Sa se stearga din 
lista elementele pare.*/
/*
typedef struct Nod {
    int valoare;
    struct Nod *urm;
} Nod;

void adaugaNodSfarsit(Nod **cap, int valoare) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Eroare la alocarea memoriei");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) {
        *cap = nou;
    } else {
        Nod *temp = *cap;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void stergePare(Nod **cap) {
    while (*cap != NULL && (*cap)->valoare % 2 == 0) {
        Nod *temp = *cap;
        *cap = (*cap)->urm;
        free(temp);
    }

    Nod *current = *cap;
    while (current != NULL && current->urm != NULL) {
        if (current->urm->valoare % 2 == 0) {
            Nod *temp = current->urm;
            current->urm = temp->urm;
            free(temp);
        } else {
            current = current->urm;
        }
    }
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;

    adaugaNodSfarsit(&cap, 4);
    adaugaNodSfarsit(&cap, 2);
    adaugaNodSfarsit(&cap, 9);
    adaugaNodSfarsit(&cap, 6);
    adaugaNodSfarsit(&cap, 3);

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    stergePare(&cap);

    printf("Lista dupa stergere elemente pare este: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

/* Aplicația 9.10: Sa se construiasca o lista liniara simplu inlantuita care sa contina numere naturale. Sa se scrie o 
functie care sa separe elementele pare de cele impare in 2 liste separate*/

typedef struct Nod {
    int valoare;
    struct Nod *urm;
} Nod;

void adaugaNodSfarsit(Nod **cap, int valoare) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Eroare la alocarea memoriei");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) {
        *cap = nou;
    } else {
        Nod *temp = *cap;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void separaPareImpare(Nod *cap, Nod **capPare, Nod **capImpare) {
    while (cap != NULL) {
        if (cap->valoare % 2 == 0) {
            adaugaNodSfarsit(capPare, cap->valoare);
        } else {
            adaugaNodSfarsit(capImpare, cap->valoare);
        }
        cap = cap->urm;
    }
}

void afiseazaLista(Nod *cap) {
    while (cap != NULL) {
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}


void elibereazaLista(Nod *cap) {
    while (cap != NULL) {
        Nod *temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() {
    Nod *cap = NULL;
    Nod *capPare = NULL;
    Nod *capImpare = NULL;


    adaugaNodSfarsit(&cap, 1);
    adaugaNodSfarsit(&cap, 6);
    adaugaNodSfarsit(&cap, 3);
    adaugaNodSfarsit(&cap, 8);
    adaugaNodSfarsit(&cap, 2);

    printf("Lista initiala este: ");
    afiseazaLista(cap);

    separaPareImpare(cap, &capPare, &capImpare);

    printf("Lista cu elemente pare este: ");
    afiseazaLista(capPare);

    printf("Lista cu elemente impare este: ");
    afiseazaLista(capImpare);

    elibereazaLista(capPare);
    elibereazaLista(capImpare);

    return 0;
}




