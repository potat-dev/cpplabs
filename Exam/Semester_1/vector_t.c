#include <stdio.h>
#include <stdlib.h>

typedef struct vector_t {
  int* data;
  int size;
  int capacity;
} vector_t;

// 9.1 init, destroy 
void init(vector_t* v) {
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void destroy(vector_t* v) {
  free(v->data);
  init(v);
}

// 9.2 push_back
void push_back(vector_t* v, int val) {
  if (v->size == 0) {
    v->capacity = 1;
    v->data = (int*) malloc(v->capacity * sizeof(int));
  } else if (v->size == v->capacity) {
    v->capacity *= 2;
    v->data = (int*) realloc(v->data, v->capacity * sizeof(int));
  }
  v->data[v->size++] = val;
}

// 9.3 insert, set
void insert(vector_t *v, int index, int val) {
  if (index >= 0 && index < v->size && v->data != NULL) {
    push_back(v, 0);
    for (int i = v->size-1; i > index; i--)
      v->data[i] = v-> data[i-1]; // сдвтгаем все элементы вправо
    v->data[index] = val;
  }
}

void set(vector_t* v, int index, int val) {
  if (index >= 0 && index < v->size && v->data != NULL)
    v->data[index] = val;
}

// 9.4 erase, get
void erase(vector_t* v, int index) {
  if (index >= 0 && index < v->size && v->data != NULL) {
    for (int i = index; i < v->size-1; i++)
      v->data[i] = v->data[i + 1];
    v->size--;
  }
}

int get(vector_t* v, int index) {
  if (index >= 0 && index < v->size && v->data != NULL)
    return v->data[index];
  else
    return -1; // можно возвращать структуру result
    // или возврашать 0/1 при ошибке/успехе
    // и записывать в переменную по указателю
}

// 9.5 find, print
int find(vector_t* v, int value) {
  if (v->data != NULL)
    for (int i = 0; i < v->size; i++)
      if (v->data[i] == value) return i;
  return -1;
}

void print(vector_t* v) {
  if (v->data != NULL) {
    for (int i = 0; i < v->size; i++)
      printf("%d ", v->data[i]);
    printf("\n");
  }
}

// реализовать к экзамену: shrink_to_fit(), pop_back()
void shrink_to_fit(vector_t* v) {
  v->capacity = v->size;
  if (v->capacity && v->data != NULL)
    v->data = (int*) realloc(v->data, v->capacity * sizeof(int));
  else
    init(v);
}

int pop_back(vector_t* v) {
  if (v->size && v->data != NULL) {
    v->size--;
    shrink_to_fit(v);
  }
}

void main() {
  vector_t vector;
  init(&vector);

  insert(&vector, 0, 999);

  for (int i = 0; i < 10; i++)
    push_back(&vector, i);
  print(&vector);

  insert(&vector, 7, 777);
  print(&vector);

  set(&vector, 7, 42);
  print(&vector);

  printf("%d %d\n", get(&vector, 7), find(&vector, 42));
  
  erase(&vector, 6);
  print(&vector);

  erase(&vector, (&vector)->size-1);
  print(&vector);

  pop_back(&vector);
  print(&vector);

  destroy(&vector);
}

// output:
// 0 1 2 3 4 5 6 7 8 9     
// 0 1 2 3 4 5 6 777 7 8 9 
// 0 1 2 3 4 5 6 42 7 8 9  
// 42 7
// 0 1 2 3 4 5 42 7 8 9    
// 0 1 2 3 4 5 42 7 8
// 0 1 2 3 4 5 42 7