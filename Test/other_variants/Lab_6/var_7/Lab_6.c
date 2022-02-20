// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// Вывести оба списка

#include <stdio.h>
#include <stdlib.h>

typedef struct file
{
  char *str;
  int size;
} file;

typedef struct word_t
{
  char *arr;
  int size;
  int capacity;
  int glasn;
} word_t;

typedef struct node_word
{
  struct word_t *w;
  struct node_word *prev;
  struct node_word *next;
} node_word;

typedef struct list_word
{
  node_word *head;
  int size;
} list_word;

void init(list_word *l)
{
  l->head = NULL;
  l->size = 0;
}

void delN(node_word *n)
{
  free(n->w->arr);
  free(n->w);
  free(n);
}

void destroy(list_word *l)
{
  node_word *current = l->head;
  node_word *prev = NULL;
  while (current != NULL)
  {
    prev = current;
    current = current->next;
    delN(prev);
  }
}

int strlen(char *str)
{
  int count = 0;
  for (int i = 0; str[i] != 0; i++)
    count++;
  return count;
}

int glasn_count(char *str)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((str[i] == 'a' || str[i] == 'A') || (str[i] == 'e' || str[i] == 'E') ||
        (str[i] == 'i' || str[i] == 'I') || (str[i] == 'o' || str[i] == 'O') ||
        (str[i] == 'u' || str[i] == 'U'))
      count++;
  return count;
}

struct word_t *make_word(char *str, int capacity)
{
  word_t *tmp = (word_t *)malloc(sizeof(word_t));
  tmp->arr = str;
  tmp->size = strlen(str);
  tmp->capacity = capacity;
  tmp->glasn = glasn_count(tmp->arr);
  return tmp;
}

void push_back(list_word *l, char *str, int capacity)
{
  word_t *w = make_word(str, capacity);
  node_word *n = (node_word *)malloc(sizeof(node_word));
  node_word *current;

  n->w = w;
  n->next = NULL;

  if (l->head == NULL)
  {
    n->prev = NULL;
    l->head = n;
  }
  else
  {
    current = l->head;
    while (current->next != NULL)
      current = current->next;
    current->next = n;
    n->prev = current;
  }
  l->size++;
}

struct word_t *get_word(list_word *l, int index)
{
  int count = 0;
  node_word *current = l->head;
  word_t *result = current->w;
  while (count++ != index)
  {
    current = current->next;
    result = current->w;
  }
  return result;
};

struct node_word *getN(list_word *l, int index)
{
  int count = 0;
  node_word *current = l->head;
  while (count++ != index)
    current = current->next;
  return current;
};

void print_list(list_word *l)
{
  for (int i = 0; i < l->size; i++)
  {
    word_t *tmp = get_word(l, i);
    printf("| %s ", tmp->arr);
  }
  printf("|\n");
}

int is_char(int c)
{
  return (int)((97 <= c && c <= 122) ||
               (128 <= c && c <= 175) ||
               (224 <= c && c <= 239) ||
               (65 <= c && c <= 90));
}

void swap(node_word *n1, node_word *n2)
{
  struct word_t *tmp = n2->w;
  n2->w = n1->w;
  n1->w = tmp;
}

void parse_str(char *tmp, int size, list_word *l)
{
  int capacity = 1, len = 0;
  char *str = (char *)malloc(sizeof(char));
  for (int i = 0; i < size; i++)
  {
    if (is_char(tmp[i]))
    {
      str[len++] = tmp[i];
      if (len >= capacity)
        str = (char *)realloc(str, (capacity *= 2) * sizeof(char));
      if (size - i == 1)
        goto w_end;
    }
    else
    {
    w_end:
      if (len)
      {
        str[len] = '\0';
        push_back(l, str, capacity);
        capacity = 1;
        len = 0;
        str = (char *)malloc(sizeof(char));
      }
    }
  }
}

list_word *parse(file *file)
{
  list_word *temp_list = (list_word *)malloc(sizeof(list_word));
  init(temp_list);
  parse_str(file->str, file->size, temp_list);
  free(file->str);
  free(file);
  return temp_list;
}

// сравнение слов
int cmp_word(word_t *w1, word_t *w2)
{
  int minS;
  if (w1->size < w2->size)
    minS = w1->size;
  else
    minS = w2->size;
  for (int i = 0; i < minS; i++)
    if (w1->arr[i] != w2->arr[i])
      if (w1->arr[i] > w2->arr[i])
        return -1;
      else
        return 1;
  if (w1->size == w2->size)
    return 0;
  else if (w1->size > w2->size)
    return -1;
  else
    return 1;
}

// проверяет нужно ли менять слова местами
int need_swap(word_t *w1, word_t *w2, int type)
{
  if (type == 1)
    return cmp_word(w1, w2);
  else if (type == 2)
    if (w1->glasn == w2->glasn)
      return 0;
    else
      return (w1->glasn > w2->glasn) ? -1 : 1;
  else
    printf("error sorting\n");
}

// сортировка
void sort(list_word *l, int sort_type)
{
  for (int i = 0; i < l->size; i++)
  {
    for (int j = i + 1; j < l->size; j++)
    {
      struct node_word *n1 = getN(l, i);
      struct node_word *n2 = getN(l, j);
      if (need_swap(n1->w, n2->w, sort_type) < 0)
        swap(n1, n2);
    }
  }
}

int file_size(FILE *file)
{
  fseek(file, 0, SEEK_END);
  int fsize = ftell(file);
  fseek(file, 0, SEEK_SET);
  return fsize;
}

file *read_file(char *path)
{
  FILE *f = fopen(path, "r");
  if (f == NULL)
    perror("Error opening file");
  int fsize = file_size(f);
  char *str = (char *)malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  fclose(f);
  file *temp_file = (file *)malloc(sizeof(file));
  temp_file->str = str;
  temp_file->size = fsize;
  return temp_file;
}

void main()
{
  file *f = read_file("test.txt");
  list_word *alph_words = parse(f);
  list_word *glasn_words = alph_words;
  printf("\nbefore sorting:\n");
  print_list(alph_words);
  printf("\nsorting by alphabet:\n");
  sort(alph_words, 1);
  print_list(alph_words);
  printf("\nsorting by glasn count:\n");
  sort(glasn_words, 2);
  print_list(glasn_words);
  destroy(alph_words);
}