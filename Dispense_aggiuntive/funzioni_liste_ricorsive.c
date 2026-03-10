#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int content;
    struct list_node *next;
} node;

typedef node * list;

// Inserisce l'elemento alla fine (coda) della lista e ritorna la "nuova" lista
list tailInsert(list l, int content);

// Inserisce l'elemento all'inizio (testa) della lista e ritorna la nuova lista
list headInsert(list l, int content);

// Inserisce l'elemento nella lista in ordine e ritorna la "nuova" lista
list sortInsert(list l, int content);

// Rimuove il primo elemento della lista che contiene l'elemento passato come parametro
list removeFirst(list l, int content);

// Rimuove tutti gli elementi della lista che contengono l'elemento passato come parametro
list removeAll(list l, int content);

// Ritorna 1 se content e' presente nella lista, 0 altrimenti
int find(list l, int content);

// Ritorna il numero di elementi nella lista
int size(list l);

// Cancella ogni elemento della lista
void clearList(list l);

// Stampa la lista
void printList(list l);

int main(int argc, const char * argv[]) {
    list l = NULL;
    
    l = tailInsert(l, 10);
    l = tailInsert(l, 12);
    l = headInsert(l, 8);
    l = sortInsert(l, 4);
    l = sortInsert(l, 14);
    l = sortInsert(l, 6);
    l = sortInsert(l, 6);
    l = sortInsert(l, 6);
    l = sortInsert(l, 6);
    printf("Valore atteso:\t4 -->\t6 -->\t6 -->\t6 -->\t6 -->\t8 -->\t10 -->\t12 -->\t14 --|\n");
    printf("Valore reale:\t");
    printList(l);
    printf("\n");
    
    l = removeFirst(l, 6);
    printf("Valore atteso:\t4 -->\t6 -->\t6 -->\t6 -->\t8 -->\t10 -->\t12 -->\t14 --|\n");
    printf("Valore reale:\t");
    printList(l);
    printf("\n");
    
    l = removeAll(l, 6);
    printf("Valore atteso:\t4 -->\t8 -->\t10 -->\t12 -->\t14 --|\n");
    printf("Valore reale:\t");
    printList(l);
    printf("\n");
    
    l = removeAll(l, 4);
    printf("Valore atteso:\t8 -->\t10 -->\t12 -->\t14 --|\n");
    printf("Valore reale:\t");
    printList(l);
    printf("\n");
    
    l = removeAll(l, 14);
    printf("Valore atteso:\t8 -->\t10 -->\t12 --|\n");
    printf("Valore reale:\t");
    printList(l);
    printf("\n");
    
    printf("Valore atteso:\t1\n");
    printf("Valore reale:\t%d\n\n", find(l, 8));
    
    printf("Valore atteso:\t0\n");
    printf("Valore reale:\t%d\n\n", find(l, 14));
    
    printf("Valore atteso:\t3\n");
    printf("Valore reale:\t%d\n\n", size(l));
    
    return 0;
}

list tailInsert(list l, int content) {
    node *n;
    if (l == NULL) {
        n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->content = content;
        return n;
    } else {
        l->next = tailInsert(l->next, content);
        return l;
    }
}

list headInsert(list l, int content) {
    node *n = (node *) malloc(sizeof(node));
    n->next = l;
    n->content = content;
    return n;
}

list sortInsert(list l, int content) {
    node *n;
    if (l != NULL && l->content < content) {
        l->next = sortInsert(l->next, content);
        return l;
    } else {
        n = (node *) malloc(sizeof(node));
        n->content = content;
        if (l != NULL) {
            n->next = l;
        } else {
            n->next = NULL;
        }
        return n;
    }
}

list removeFirst(list l, int content) {
    node *n;
    if (l == NULL) {
        return l;
    } else if (l->content == content) {
        n = l->next;
        free (l);
        return n;
    } else {
        l->next = removeFirst(l->next, content);
        return l;
    }
}

list removeAll(list l, int content) {
    node *n;
    if (l == NULL) {
        return l;
    } else if (l->content == content) {
        n = removeAll(l->next, content);
        free(l);
        return n;
    } else {
        l->next = removeAll(l->next, content);
        return l;
    }
}

int find(list l, int content) {
    if (l == NULL) {
        return 0;
    } else {
        return l->content == content || find(l->next, content);
    }
}

int size(list l) {
    if (l == NULL) {
        return 0;
    } else {
        return 1 + size(l->next);
    }
}

void clearList(list l) {
    node *n;
    if (l != NULL) {
        n = l->next;
        free(l);
        clearList(n);
    }
}

void printList(list l) {
    if (l != NULL) {
        printf("%d ", l->content);
        if (l->next != NULL)
            printf("-->\t");
        printList(l->next);
    } else {
        printf("--|\n");
    }
}
