#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1

typedef struct vector {
  size_t size;
  size_t capacity;
  char *datum;
} Vector;

void purge(Vector *vector);
void prepare(Vector *vector);
void pop(Vector *vector);
void push(Vector *vector, char datum);
char peek(Vector *vector);
void proliferate(Vector *vector);
void print(Vector *vector);

int main(void) {
  Vector list;
  prepare(&list);

  push(&list, 'a');
  push(&list, 'c');
  push(&list, 'd');
  push(&list, 'a');
  push(&list, 'l');
  push(&list, 'd');
  print(&list);

  printf("peek: %c\n", peek(&list));

  pop(&list);
  pop(&list);
  print(&list);
  pop(&list);
  print(&list);

  purge(&list);
}

void purge(Vector *vector) {
    free(vector->datum);
}

void prepare(Vector *vector) {
  vector->size = 0;
  vector->capacity = CAPACITY;
  vector->datum = calloc(CAPACITY, sizeof(char));
}

void pop(Vector *vector){
  vector->size--;
}

void push(Vector *vector, char datum){
  proliferate(vector);
  vector->datum[vector->size++] = datum;
}

char peek(Vector *vector){
  return vector->datum[vector->size - 1];
}

void proliferate(Vector *vector){
  if(vector->size >= vector->capacity) {
    vector->capacity *= 2;
    vector->datum = realloc(vector->datum, sizeof(char) * vector->capacity);
  }
}

void print(Vector *vector) {
  for(size_t i = 0; i < vector->size; ++i) {
    printf("%c", vector->datum[i]);
  }
  puts("");
}

/*remove and add to end*/
