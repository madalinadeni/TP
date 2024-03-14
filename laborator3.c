#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicatia 3.1 Implementati pe calculator structura de date stiva, asa cum este descrisa in laborator.
/*
#define MAX 100 
int varf = -1; 
int stiva[MAX]; 

void push(int element){ 
    if(varf == MAX - 1){ 
        printf("Stiva este plina!"); 
        return;
    }

    stiva[++varf] = element;
    printf("\n");
}

int pop(){  
    if(varf == -1){  
        printf("Stiva este goala!"); 
        return -1;
    }
    return stiva[varf--];
    printf("\n");
}

void afisare(){ 
    if(varf == -1){ 
        printf("Stiva este goala\n"); 
        return;
    }
    printf("Elementele din stiva sunt:"); 
    for(int i=varf; i>=0; i--){
        printf(" %d ", stiva[i]);
    }
   printf("\n");
}

int main(){
    push(4);
    push(9);
    push(55);
    push(22);
    afisare();
    printf("Elementul extras din stiva este: %d\n", pop());
    afisare();
    return 0;
}*/

// Aplicatia 3.2 Implementati pe calculator structura de date coada, asa cum este descrisa in laborator.
/*
#define SIZE 100 
int fata = -1; 
int spate = -1; 

int coada[SIZE]; 

void adaugaElement(int element){ 
    if(spate == SIZE - 1){
        printf("Coada este plina!\n"); 
        return;
    }
    
    if(fata == -1)
        fata = 0;
    coada[++spate] = element;
}

int scoateElement(){
    if(fata == -1 || fata > spate){
        printf("Coada este goala\n");
        return -1;
    }
    return coada[fata++];
}

void afisare(){
    if(fata == -1 || fata > spate){
        printf("Coada este goala\n");
        return;
    }

    printf("Elementele din coada sunt:");
    for(int i=fata; i<=spate; i++)
        printf(" %d ", coada[i]);
    printf("\n");
}

int main(){
    adaugaElement(5);
    adaugaElement(49);
    adaugaElement(67);
    adaugaElement(92);
    afisare();
    printf("Elementul extras din coada este: %d\n", scoateElement());
    afisare();
    return 0;

}*/

/* Aplicatia 3.3 Sa se implementeze cu ajutorul unei stive functia undo dintr-un fisier text. Functia 
undo permite utilizatorului sa se revina la o versiune mai veche a documentului, eliminand ultimile 
modificari. Pentru a implementa functia undo cu o stiva fiecare modificare va fi retinuta pe stiva, iar 
cand e necesar sa se revina la o versiune anterioara se va elimina din stiva ultima modificare 
adaugata. Pe stiva se va retine la fiecare modificare: textul nou scris (sir de maxim 100 de 
caractere), randul unde a fost scris (int) */

/* !!?!!
#define MAX 100 
int varf = -1; 
int stiva[MAX]; 

void push(int element){ 
    if(varf == MAX - 1){ 
        printf("Stiva este plina!"); 
        return;
    }

    stiva[++varf] = element;
    printf("\n");
}

int pop(){  
    if(varf == -1){  
        printf("Stiva este goala!"); 
        return -1;
    }
    return stiva[varf--];
    printf("\n");
}

void afisare(){ 
    if(varf == -1){ 
        printf("Stiva este goala\n"); 
        return;
    }
    printf("Elementele din stiva sunt:"); 
    for(int i=varf; i>=0; i--){
        printf(" %d ", stiva[i]);
    }
   printf("\n");
}
int main(){
    push(4);
    push(9);
    push(55);
    push(22);
    afisare();
    printf("Elementul extras din stiva este: %d\n", pop());
    afisare();
    return 0;
}*/

/* Aplicatia 3.4 Sa se implementeze cu ajutorul unei cozi un buffer care retine temporar informatiile 
primite de la diversi transmitatori (informatia este adaugata in coada) si le transmite mai apoi catre 
un receptor (informatia este eliminata din coada). Informatia primita in buffer are urmatoare 
structura: numar identificare transmitator (int), mesaj (sir de caractere de maxim 256 caractere) */
// !!!??!!!
#define SIZE 100 
#define MAX_CHAR 256

int fata = -1; 
int spate = -1; 

int coada[SIZE]; 

typedef struct {
    int transmitator_id;
    char mesaj[MAX_CHAR];
}Informatie_primita;

void adaugaElement(int transmitator_id, char *mesaj){ 
    if(spate == SIZE - 1){
        printf("Coada este plina!\n"); 
        return;
    }
    
    if(fata == -1)
        fata = 0;
        spate = (spate + 1) % SIZE;
    
}

int scoateElement(){
    if(fata == -1 || fata > spate){
        printf("Coada este goala\n");
        return -1;
    }
    return coada[fata++];
}

void afisare(){
    if(fata == -1 || fata > spate){
        printf("Coada este goala\n");
        return;
    }

    printf("Elementele din coada sunt:");
    for(int i=fata; i<=spate; i++)
        printf(" %d ", coada[i]);
    printf("\n");
}

int main(){
   /* adaugaElement(5);
    adaugaElement(49);
    adaugaElement(67);
    adaugaElement(92);*/
    //afisare();
    printf("Elementul extras din coada este: %d\n", scoateElement());
    afisare();
    return 0;

}