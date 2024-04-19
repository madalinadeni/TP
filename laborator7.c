#include <stdio.h>
#include <stdlib.h>

/* Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0*/
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;


void append(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}


int areIdentical(Node* a, Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data) {
            return 0;
        }
        a = a->next;
        b = b->next;
    }

    return (a == NULL && b == NULL);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

//    append(&head1, 1);
//    append(&head1, 2);
//    append(&head1, 3);

//    append(&head2, 1);
//    append(&head2, 5);
//    append(&head2, 3);
    
    append(&head1, 1);
    append(&head1, 5);
    append(&head1, 3);

    append(&head2, 1);
    append(&head2, 2);
    append(&head2, 9);

    printf("Lista 1: ");
    printList(head1);
    printf("Lista 2: ");
    printList(head2);

    if (areIdentical(head1, head2)) {
        printf("Listele sunt identice.\n");
    } else {
        printf("Listele nu sunt identice.\n");
    }

    return 0;
}*/

/* Aplicația 7.2: Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate. 
Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente. */
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void reverseList(Node** headRef) {
    Node* prev = NULL;
    Node* current = *headRef;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headRef = prev;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Lista originală: ");
    printList(head);

    reverseList(&head);

    printf("Lista inversată: ");
    printList(head);

    return 0;
}*/

/* Aplicația 7.3: Să se scrie o funcție care primește ca parametri două liste și returnează o listă care reprezintă 
reuniunea elementelor lor, fiecare element apărând o singură dată, chiar dacă în listele originare el este duplicat.*/
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

int exists(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Node* unionLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 != NULL) {
        if (!exists(result, current1->data)) {
            append(&result, current1->data);
        }
        current1 = current1->next;
    }

    while (current2 != NULL) {
        if (!exists(result, current2->data)) {
            append(&result, current2->data);
        }
        current2 = current2->next;
    }

    return result;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    append(&head1, 1);
    append(&head1, 2);
    append(&head1, 3);

    append(&head2, 3);
    append(&head2, 4);
    append(&head2, 5);

    printf("Lista 1: ");
    printList(head1);
    printf("Lista 2: ");
    printList(head2);

    Node* result = unionLists(head1, head2);

    printf("Reuniunea listelor: ");
    printList(result);

    return 0;
}*/

/* Aplicația 7.4: Pentru implementarea listei care memorează adresa ultimului element, să se scrie o funcție șterge, 
care șterge din listă un element dat.*/
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;     
    Node* tail; 
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void append(LinkedList* list, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
}

void deleteNode(LinkedList* list, Node* nodeToDelete) {
    if (list->head == NULL) {
        return;
    }

    if (list->head == nodeToDelete) {
        list->head = list->head->next;
        free(nodeToDelete);
        if (list->head == NULL) {
            list->tail = NULL;
        }
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next != nodeToDelete) {
        current = current->next;
    }

    if (current->next == nodeToDelete) {
        current->next = nodeToDelete->next;
        if (nodeToDelete == list->tail) {
            list->tail = current;
        }
        free(nodeToDelete);
    }
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    initList(&list);

    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);

    printf("Lista: ");
    printList(&list);

    Node* nodeToDelete = list.head;
    while (nodeToDelete != NULL && nodeToDelete->data != 2) {
        nodeToDelete = nodeToDelete->next;
    }

    if (nodeToDelete != NULL) {
        deleteNode(&list, nodeToDelete);
    }

    printf("Lista după ștergere: ");
    printList(&list);

    return 0;
}*/

/* Aplicația 7.5: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt egale, indiferent de 
ordinea și numărul elementelor, altfel returnează 0.
Exemple: listele {1, 7, 3, 1, 3} și {7, 1, 3, 7} sunt egale. Listele {1,2} și {2} nu sunt egale.*/
 /*
#define MAX_SIZE 100

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[MAX_SIZE];
} HashTable;

void initHashTable(HashTable* ht) {
    for (int i = 0; i < MAX_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

void addToHashTable(HashTable* ht, int key) {
    int index = abs(key) % MAX_SIZE;

    HashNode* newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = NULL;

    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = newNode;
    } else {
        HashNode* current = ht->buckets[index];
        while (current->next != NULL) {
            if (current->key == key) {
                current->value++;
                free(newNode);
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }
}

int areListsEqual(int* arr1, int size1, int* arr2, int size2) {
    if (size1 != size2) {
        return 0;
    }

    HashTable ht;
    initHashTable(&ht);

    for (int i = 0; i < size1; i++) {
        addToHashTable(&ht, arr1[i]);
    }

    for (int i = 0; i < size2; i++) {
        int index = abs(arr2[i]) % MAX_SIZE;
        HashNode* current = ht.buckets[index];
        while (current != NULL) {
            if (current->key == arr2[i] && current->value > 0) {
                current->value--;
                break;
            }
            current = current->next;
        }
        if (current == NULL || current->value == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int arr1[] = {1, 7, 3, 1, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {7, 1, 3, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (areListsEqual(arr1, size1, arr2, size2)) {
        printf("Listele sunt egale.\n");
    } else {
        printf("Listele nu sunt egale.\n");
    }

    return 0;
}*/

/* Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un 
element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să 
se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată. 
Programul nu va folosi niciun vector.*/
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertSorted(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL || newData < (*headRef)->data) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    Node* current = *headRef;
    while (current->next != NULL && current->next->data < newData) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void sortList(Node** headRef) {
    Node* sortedList = NULL;
    Node* current = *headRef;
    Node* next;

    while (current != NULL) {
        next = current->next;
        insertSorted(&sortedList, current->data);
        current = next;
    }

    *headRef = sortedList;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertSorted(&head, 3);
    insertSorted(&head, 1);
    insertSorted(&head, 4);
    insertSorted(&head, 2);

    printf("Lista nesortată: ");
    printList(head);

    sortList(&head);

    printf("Lista sortată: ");
    printList(head);

    return 0;
}*/

/* Aplicația 7.7: Pentru implementarea listei care memorează ultimul element, să se scrie o funcție care primește 
două liste sortate și returnează lista sortată care conține toate elementele lor. Pentru lista rezultată se va folosi 
doar operația de adăugare la sfârșit de listă.
Exemplu: {1, 2, 7, 8} și {2, 9} -> {1, 2, 2, 7, 8, 9} */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

Node* mergeSortedLists(Node* head1, Node* head2) {
    Node* result = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            append(&result, head1->data);
            head1 = head1->next;
        } else {
            append(&result, head2->data);
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        append(&result, head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        append(&result, head2->data);
        head2 = head2->next;
    }

    return result;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    append(&head1, 1);
    append(&head1, 2);
    append(&head1, 7);
    append(&head1, 8);

    append(&head2, 5);
    append(&head2, 9);

    printf("Lista 1: ");
    printList(head1);

    printf("Lista 2: ");
    printList(head2);

    Node* mergedList = mergeSortedLists(head1, head2);

    printf("Lista combinată și sortată: ");
    printList(mergedList);

    return 0;
}



















