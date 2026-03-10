#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * next;
} node;

node * init(node *, int[], int );
node * insert(node *, int );
int sum(node *);
void print(node *);
void destroy(node *);

int main(void) 
{
  node * head = NULL;
  int val[] = { 1, 2, 3, 4 }; 

  head = insert(init(head, val, 4), 5);
  print(head);
  printf("%d\n", sum(head));

  destroy(head);
  head = NULL;

  return 0;
}

node * init(node * head, int val[], int num_elem)
{
  for(int i=0; i<num_elem; i++)
    head = insert(head, val[i]);

  return head;
}

node * insert(node * head, int val) 
{
  node * p = (node * ) malloc( sizeof(node) );
  p->value = val;
  p->next = NULL;

  if(head == NULL)
    head = p; // Non modifica l'head del main

  else 
  {
    node * current;
    for(current = head; current->next != NULL; current = current->next)
      ;
    current->next = p;
  }

  return head;
}

int sum(node * head)
{
  if(head != NULL)
    return head->value + sum(head->next);

  return 0;
}

void print(node * head)
{
  node * current;
  for(current = head; current != NULL; current = current->next)
    printf("%d ", current->value);

  printf("\n");
}

void destroy(node * head)
{
  node * current = head;
  node * temp;
  while(current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }
}