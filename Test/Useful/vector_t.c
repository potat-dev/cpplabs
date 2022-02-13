#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  int size;
  int capacity;
} vector_t;

void init(vector_t* v) {
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void destroy(vector_t* v) {
  if (v->data != NULL) free(v->data);
  v->size = 0; v->capacity = 0; v->data = NULL; 
}

void push_back(vector_t* v, int n) {
  if (v->size == v->capacity) {
    if (v->capacity = 0) v->capacity = 1;
    v->capacity *= 2;
    v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
  }
  v->data[v->size] = n;
  v->size += 1;
}

void set(vector_t* v, int index, int val) {
  if (index >= 0 && index < v->size) v->data[index] = val;
}

void insert(vector_t* v, int index, int val) {
  if (index >= 0 && index < v->size) {
    // способ Линского!!! 100% рабочий!!!
    push_back(v, 0);
    for (int i = v->size-1; i != index; i--)
      v->data[i] = v->data[i-1];
    v->data[index] = val;
  }
}

void erase(vector_t* v, int index) {
  if (index >= 0 && index < v->size) {
    for (int i = index; i < v->size; i++) v->data[i] = v->data[i + 1];
    v->size--;
  }
}

int get(vector_t* v, int index) {
  if (index >= 0 && index < v->size) {
    return v->data[index];
  } else {
    return -1; // вышли за границу
  }
}

int find(vector_t* v, int val) {
  for (int i = 0; i < v->size; i++)
    if (v->data[i] == val) return i;
  return -1;
}

void print_vector(vector_t* v) {
  for (int i = 0; i < v->size; i++) printf("%d ", v->data[i]);
}

void shrink_to_fit(vector_t* v) {
  v->capacity = v->size;
  v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
}

int main (int argc, char *argv[]) {
  vector_t v;
  init(&v);

  push_back(&v, 1);
  push_back(&v, 2);
  push_back(&v, 2);
  push_back(&v, 2);
  push_back(&v, 3);
  push_back(&v, 2);
  push_back(&v, 2);
  push_back(&v, 666);
  push_back(&v, 2);
  push_back(&v, 2);
  push_back(&v, 2);
  
  print_vector(&v);
  printf("\n");

  insert(&v, 2, 9999);

  print_vector(&v);
  printf("\n");

  printf("%d %d %d ", get(&v, 2), get(&v, 7), get(&v, 0));

  printf("%d", find(&v, 9999));
}