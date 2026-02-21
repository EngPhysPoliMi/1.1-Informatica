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

// Rimuove tutti gli elementi dalla lista
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
    printf("Valore  atteso:\t4 --> 6 --> 6 --> 6 --> 6 --> 8 --> 10 --> 12 --> 14 --|\n");
    printf("Valore  reale:\t");
    printList(l);
    printf("\n");
    
    l = removeFirst(l, 6);
    printf("Valore  atteso:\t4 --> 6 --> 6 --> 6 --> 8 --> 10 --> 12 --> 14 --|\n");
    printf("Valore  reale:\t");
    printList(l);
    printf("\n");
    
    l = removeAll(l, 6);
    printf("Valore  atteso:\t4 --> 8 --> 10 --> 12 --> 14 --|\n");
    printf("Valore  reale:\t");
    printList(l);
    printf("\n");
    
    l = removeAll(l, 4);
    printf("Valore  atteso:\t8 --> 10 --> 12 --> 14 --|\n");
    printf("Valore  reale:\t");
    printList(l);
    printf("\n");
    
  l = removeAll(l, 14);
  printf("Valore  atteso:\t8 --> 10 --> 12 --|\n");
  printf("Valore  reale:\t");
  printList(l);
  printf("\n");
    
  printf("Valore  atteso:\t1\n");
  printf("Valore  reale:\t%d\n\n", find(l, 8));
    
  printf("Valore  atteso:\t0\n");
  printf("Valore  reale:\t%d\n\n", find(l, 14));
    
  printf("Valore  atteso:\t3\n");
  printf("Valore  reale:\t%d\n\n", size(l));
    
  return 0;
}

list tailInsert(list l, int content) {
  list currentTail = l;
  node *n = (node *) malloc(sizeof(node));
  n->next = NULL;
  n->content = content;
    
  // Caso di lista inizialmente vuota
  if (l == NULL) {
    return n;
  }
    
  // Caso di lista non vuota
  while (currentTail->next != NULL) {
    currentTail = currentTail->next;
  }
    
  currentTail->next = n;
  return l;
}

list headInsert(list l, int content) {
  node *n = (node *) malloc(sizeof(node));
  n->next = l;
  n->content = content;
  return n;
}

list sortInsert(list l, int content) {
  list currentNode = l;
  node *n = (node *) malloc(sizeof(node));
    
  // Casi in cui l'elemento deve essere inserito in prima posizione
  if (l == NULL || l->content >= content) {
    return headInsert(l, content);
  }
    
  // Caso in cui l'elemento deve essere inserito in una posizione centrale
  while (currentNode->next != NULL && currentNode->next->content < content) {
    currentNode = currentNode->next;
  }
  n->next = currentNode->next;
  n->content = content;
  currentNode->next = n;
  return l;
}

list removeFirst(list l, int content) {
  list previousNode = NULL;
  list currentNode = l;
  list head = l;
    
  while (currentNode != NULL && currentNode->content != content) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
    
  // Se ho trovato l'elemento ...
  if (currentNode != NULL) {
    // L'elemento era in prima posizione
    if (previousNode == NULL) {
      head = currentNode->next;
    }
    // L'elemento NON era in prima posizione
    else {
      previousNode->next = currentNode->next;
    }
    free(currentNode);
  }
    
  return head;
}

list removeAll(list l, int content) {
  list previousNode = NULL;
  list currentNode = l;
  list head = l;
    
  while (currentNode != NULL) {
    if (currentNode->content == content) {
      // L'elemento era in prima posizione
      if (previousNode == NULL) {
	head = currentNode->next;
      }
      // L'elemento NON era in prima posizione
      else {
	previousNode->next = currentNode->next;
      }
      currentNode = currentNode->next;
    } else {
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
  }
    
  return head;
}

int find(list l, int content) {
  while (l != NULL) {
    if (l->content == content) {
      return 1;
    }
    l = l->next;
  }
  return 0;
}

int size(list l) {
  int count = 0;
  while (l != NULL) {
    count++;
    l = l->next;
  }
  return count;
}

void clearList(list l) {
  list temp;
  while (l != NULL) {
    temp = l;
    l = l->next;
    free(temp);
  }
}

void printList(list l) {
  while (l != NULL) {
    printf("%d", l->content);
    if (l->next != NULL)
        printf(" --> ");
    l = l->next;
  }
  printf(" --|\n");
}
