#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30

typedef struct student {
  char name[ MAX_CHAR ];
  char family_name[ MAX_CHAR ];
  int birthyear;
  double avg;
} student;

typedef struct node {
  student value;
  struct node * next;
} node;

int compare_by_birthdate(const void *, const void *);
int compare_by_fullname(const void *, const void *);

node * insert(node *, student, int);
node * insert_on_head(node *, student);
node * insert_on_queue(node *, student);
node * get_elem_by_pos(node *, int);
int length(node *);
void print(node *);
void destroy(node *);
void list2array(node *, node* []);
void array2list(node* [], int, node **);

int main(void) 
{
  // Create students
  student s1;
  strcpy(s1.name, "A");
  strcpy(s1.family_name, "AA");
  s1.birthyear = 2005;
  s1.avg = 27.3;

  student s2;
  strcpy(s2.name, "B");
  strcpy(s2.family_name, "BB");
  s2.birthyear = 1990;
  s2.avg = 28.5;

  student s3;
  strcpy(s3.name, "C");
  strcpy(s3.family_name, "CC");
  s3.birthyear = 2001;
  s3.avg = 20.7;

  // Create list
  node * head = NULL;
  head = insert(head, s1, 0);
  head = insert(head, s2, 1);
  head = insert(head, s2, 0);
  head = insert(head, s1, 1);
  head = insert(head, s3, 2);
  print(head);
  printf("\n%d\n", length(head));

  // Convert list to array, so that it can be sorted by qsort
  node ** arr = (node **) malloc( length(head) * sizeof(node *) );
  list2array(head, arr);

  // Sort by the specified criterium
  qsort(arr, length(head), sizeof(node *), compare_by_birthdate);

  // Create a new list out of the sorted array
  node * sorted = NULL;
  array2list(arr, length(head), &sorted);
  print(sorted);

  // Free memory
  destroy(head);
  head = NULL;

  destroy(sorted);
  head = NULL;

  free(arr);
  arr = NULL;

  return 0;
}

void list2array(node * head, node * arr[])
{
  for(int i=0; i<length(head); i++)
    arr[i] = get_elem_by_pos(head, i);
}

void array2list(node * arr[], int len, node ** head)
{
  for(int i=0; i<len; i++)
    *head = insert(*head, arr[i]->value, i);
}

int length(node * head)
{
  if(head == NULL)
    return 0;

  return 1 + length( head->next );
}

node * get_elem_by_pos(node * head, int pos)
{
  if(pos == 0)
    return head;

  return get_elem_by_pos(head->next, pos-1);
}

node * insert(node * head, student s, int pos) 
{
  // If pos is not a valid position, return the list unchanged
  if(pos < 0 || pos > length(head))
    return head;

  if(pos == 0)
  {
    node * p = (node *) malloc( sizeof(node) );
    p->value = s;
    p->next = head;
    head = p;
  }
  else
    head->next = insert(head->next, s, pos-1);

  return head;
}

node * insert_on_head(node * head, student s)
{
  return insert(head, s, 0);
}

node * insert_on_queue(node * head, student s)
{
  return insert(head, s, length(head));
}

void print(node * head)
{
  if( head != NULL ) 
  {
    printf("%s ", head->value.family_name);
    print(head->next);
  }
}

void destroy(node * head)
{
  if( head != NULL )
  {
    free(head);
    destroy(head->next);
  }
}

int compare_by_birthdate(const void * a, const void * b)
{
  node ** n1 = (node **) a;
  node ** n2 = (node **) b;

  return (*n1)->value.birthyear - (*n2)->value.birthyear;
}

int compare_by_fullname(const void * a, const void * b)
{
  node ** n1 = (node **) a;
  node ** n2 = (node **) b;

  return strcmp((*n1)->value.family_name, (*n2)->value.family_name) + strcmp((*n1)->value.name, (*n2)->value.name);
}