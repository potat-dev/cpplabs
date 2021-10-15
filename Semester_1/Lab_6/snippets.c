#include <stdio.h>
#include <stdlib.h>

///// туду тудуду: /////
// вставка (инсерт)
// удаление по индексу
// удаление диапазона
// поиск
// поиск с оффсетом
// поиск с конца
// поменять 1; 0; -1 на -1; 0; 1
// поменять везде l на list

// конфиги
#define NORMAL   0
#define REVERSE  1
#define ALPHABET 0
#define LENGTH   1
#define VOWELS   2
#define CONSNTS  3

// list  ->  содержит указатель на начало связанного списка node
// node  ->  содержит ссылку на word и ссылки на пред/след элемент
// word  ->  содержит массив char и длину/кол-во глассных в слове

typedef struct word {
  char *arr;
  int size;
  int capacity;
  int vowels;
  int consnts;
} word;

typedef struct node {
  struct word *word;
  struct node *prev;
  struct node *next;
} node;

typedef struct list {
  node  *head;
  size_t size;
} list;

void init(list *l) {
  l -> head = NULL;
  l -> size = 0;
}

void destroy_node(node *node) {
  free(node->word->arr);
  free(node->word);
  free(node);
}

void destroy(list *list) {
  node *curr = list->head;
  node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
    destroy_node(prev);
  }
}

int vowels_count(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((str[i] == 'a')
    ||  (str[i] == 'e')
    ||  (str[i] == 'i')
    ||  (str[i] == 'o')
    ||  (str[i] == 'u')) count++;
  return count;
}

void upd_word(word *w) {
  w->vowels = vowels_count(w->arr);
  w->consnts = w->size - w->vowels;
}

void push_back(list *l, char *str, size_t size, int capacity) {
  word *w = (word*) malloc(sizeof(word));
  node *n = (node*) malloc(sizeof(node));
  node *curr;

  w -> arr = str;
  w -> size = size;
  w -> capacity = capacity;
  w -> vowels = vowels_count(str);
  w -> consnts = size - (w -> vowels);
  n -> word = w;
  n -> next = NULL;

  if(l -> head == NULL) {
    n -> prev = NULL;
    l -> head = n;
  } else {
    curr = l -> head;
    while (curr -> next != NULL)
      curr = curr -> next;
    curr -> next = n;
    n -> prev = curr;
  }
  l -> size++;
}

void merge_lists(list *source, list *destination) {
  node *curr = source -> head;
  for (int i = 0; i < source -> size; i++) {
    word *temp_word = curr -> word;
    char *temp_str = (char*) malloc(temp_word -> size * sizeof(char));
    for (size_t i = 0; i < temp_word -> size; i++)
      temp_str[i] = temp_word -> arr[i];
    push_back(destination, temp_str,
              temp_word -> size, temp_word -> capacity);
    curr = curr -> next;
  }
}

struct word *get_word(list *l, int i) {
  int count = 0;
  node *curr = l -> head;
  word *result = curr -> word;
  while (count++ != i) {
    curr = curr -> next;
    result = curr -> word;
  }
  return result;
};

struct node *get_node(list *l, int i) {
  int count = 0;
  node *curr = l -> head;
  while (count++ != i)
    curr = curr -> next;
  return curr;
};

void print_list(list *l) {
  for (size_t i = 0; i < l->size; i++) {
    word *temp = get_word(l, i);
    printf("%d -- %s\n", i, temp->arr);
    printf("---------------------\n");
  }
}

int is_char(int ch) {
  return (int)
  ((97 <= ch && ch <= 122) ||
  (128 <= ch && ch <= 175) ||
  (224 <= ch && ch <= 239) ||
  (65  <= ch && ch <= 90));
}

int strcmp(char *s1, char *s2) {
  char c1, c2;
  while ((c1 == *s1++) == (c2 = *s2++))
    if (c1 == '\0')
      return 0;
  return c1 - c2;
}

void swap_nodes(node *n1, node *n2) {
  struct word *temp = n2 -> word;
  n2 -> word = n1 -> word;
  n1 -> word = temp;
}

void parse_str(char *temp, size_t size, list *list) {
  int capacity = 1, len = 0;
  char *str = (char*) malloc(sizeof(char));
  for (size_t i = 0; i < size; i++) {
    if (is_char(temp[i])) {
      str[len++] = temp[i];
      if (len >= capacity)
        str = (char*) realloc(str, (capacity *= 2) * sizeof(char));
      if (size - i == 1)
        goto word_end;
    } else {
      word_end:
      if (len) {
        str[len] = '\0';
        push_back(list, str, len, capacity);
        capacity = 1; len = 0;
        str = (char*) malloc(sizeof(char));
      }
    }
  }
}

// новая функция сравнения слов
int compare_words(word *w1, word *w2, int order) {
  //  1 - порядок правильный
  //  0 - слова идентичны
  // -1 - порядок неправильный
  int min_size = w1->size < w2->size ? w1->size : w2->size;
  for (int i = 0; i < min_size; i++)
    if (w1->arr[i] != w2->arr[i])
      return order ^ (w1->arr[i] > w2->arr[i]) ? -1 : 1;
  if (w1->size == w2->size) return 0;
  else return order ^ (w1->size > w2->size) ? -1 : 1;
}

// обычная сортировка
void sort_list(list *list, int sort_type, int reverse) {
  for (int i = 0; i < list->size; i++) {
    for (int j = i+1; j < list->size; j++) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, j);
      int swap = 0;
      switch (sort_type) {
        case ALPHABET:
          swap = compare_words(node1->word, node2->word, reverse) < 0;
          break;
        case LENGTH:
          swap = reverse ^ (node1->word->size > node2->word->size);
          break;
        case VOWELS:
          swap = reverse ^ (node1->word->vowels > node2->word->vowels);
          break;
        case CONSNTS:
          swap = reverse ^ (node1->word->consnts > node2->word->consnts);
          break;
        default:
          printf("Invalid sorting configuration!");
      }
      if (swap) swap_nodes(node1, node2);
    }
  }
}

// проверяет, нужно ли менять слова местами
int need_swap(word *w1, word *w2, int sort_type, int reverse) {
  //  1 - порядок правильный
  //  0 - слова идентичны
  // -1 - порядок неправильный
  switch (sort_type) {
    case ALPHABET:
      return compare_words(w1, w2, reverse);
    case LENGTH:
      if (w1->size == w2->size) return 0;
      else return (reverse ^ (w1->size > w2->size)) ? -1 : 1;
    case VOWELS:
      if (w1->vowels == w2->vowels) return 0;
      else return (reverse ^ (w1->vowels > w1->vowels)) ? -1 : 1;
    case CONSNTS:
      if (w1->consnts == w2->consnts) return 0;
      else return (reverse ^ (w1->consnts > w1->consnts)) ? -1 : 1;
    default:
      printf("Invalid sorting configuration!");
  }
}


// новая обычная сортировка
// НЕ РАБОТАЕТ, ПОЧИНИТЬ! 
void sort_list1(list *list, int sort_type, int reverse) {
  for (int i = 0; i < list->size; i++) {
    for (int j = i+1; j < list->size; j++) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, j);
      if (need_swap(node1->word, node2->word, sort_type, reverse) < 0)
        swap_nodes(node1, node2);
    }
  }
}


// двойная сортировка
void double_sort(list *list, int sort_1, int sort_2, int order) {
  for (int i = 0; i < list->size; i++) {
    for (int j = i+1; j < list->size; j++) {
      struct node *node1 = get_node(list, i);
      struct node *node2 = get_node(list, j);
      int swap = need_swap(node1->word, node2->word, sort_1, order);
      switch (sort_1) { // оптимизировать
        case ALPHABET:
          if (swap >= 0)
            swap = need_swap(node1->word, node2->word, sort_2, order);
          break;
        case LENGTH:
        case VOWELS:
        case CONSNTS:
          if (!swap)
            swap = need_swap(node1->word, node2->word, sort_2, order);
          break;
        default:
          printf("Invalid sorting configuration!");
      }
      if (swap < 0) swap_nodes(node1, node2);
    }
  }
}