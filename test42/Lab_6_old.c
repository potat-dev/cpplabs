// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв.
// Вывести оба списка

#include <stdio.h>
#include <stdlib.h>

#define WORDS_LIMIT 1000
#define WORDS_LEN 30

#define PRINT_MODE 0
// 0 - all words in one line
// 1 - every word on a new line

#define SORT_ORDER 1
//  1: A-Z
// -1: Z-A

int strcmp(const char *s1, const char *s2) {
  unsigned char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++)) if (c1 == '\0') return 0;
  return c1 - c2;
}

void strcopy(char *dest, const char *src) {
  char *p = dest;
  do *p++ = *src;
  while (*src++);
}

void main() {
  char words[WORDS_LIMIT][WORDS_LEN] = {'\0'};
  char word[WORDS_LEN] ={'\0'};
  int t = 0, words_count = 0;
  FILE *f;

  // open file
  if ((f = fopen("input.txt", "r")) == NULL)
    { printf("Error opening file"); exit(1); }
  
  // read word without duplicates
  while (fscanf(f, "%s", word) == 1) {
    int flag = 0;
    for (int i = 0; i < words_count; i++)
      if (strcmp(word, words[i]) == 0)
        { flag = 1; break; }
    if (!flag) strcopy(words[words_count++], word);
  }

  // sort alphabetically
  for (int i = 0; i < words_count + 1; i++)
    for (int j = i+1; j < words_count; j++)
      if (SORT_ORDER * strcmp(words[i], words[j]) > 0) {
        strcopy(word, words[i]);
        strcopy(words[i], words[j]);
        strcopy(words[j], word);
      }

  printf("Sorted alphabetically:\n----------------------\n");
  for (int i = 0; i < words_count; i++) if (strcmp(words[i], "\0") != 0)
    printf(PRINT_MODE ? "%s\n" : (i == words_count - 1 ? "%s" : "%s, "), words[i]);

  // counting vowels
  int curr_word = 0;
  int counts[words_count];
  for (int w = 0; w < words_count; w++) {
    int count = 0;
    for (int c = 0; words[w][c] != '\0'; c++)
      if ((words[w][c] == 'a')
      ||  (words[w][c] == 'e')
      ||  (words[w][c] == 'i')
      ||  (words[w][c] == 'o')
      ||  (words[w][c] == 'u')) count++;
    counts[curr_word] = count;
    curr_word++;
  }

  // sort by count of vowels
  for (int i = 0; i < words_count + 1; i++)
    for (int j = i+1; j < words_count; j++)
      if (SORT_ORDER * (counts[i] - counts[j]) > 0) {
        strcopy(word, words[i]);
        strcopy(words[i], words[j]);
        strcopy(words[j], word);
        t = counts[i];
        counts[i] = counts[j];
        counts[j] = t;
      }

  printf("\n\nSorted by count of vowels:\n--------------------------\n");
  for (int i = 0; i < words_count; i++) if (strcmp(words[i], "\0") != 0)
    printf(PRINT_MODE ? (counts[i] == 1 ? "%s - %d vowel\n" : "%s - %d vowels\n")
                      : (i == words_count - 1 ? "%s (%d)" : "%s (%d), "),
                      words[i], counts[i]);
}

// struct //

// typedef struct word
// {
//   int len;
//   char *word;
// } word;

// typedef struct node_t
// {
//   int value;
//   struct node_t *prev;
//   struct node_t *next;
// } node_t;

// typedef struct
// {
//   node_t *head;
//   size_t size;
// } list_t;

// void init(list_t *l)
// {
//   l->head = NULL;
//   l->size = 0;
// }

// void destroy(list_t *l)
// {
//   node_t *cur = l->head;
//   node_t *prev = NULL;
//   while (cur != NULL)
//   {
//     prev = cur;
//     cur = cur->next;
//     free(prev);
//   }
// }

// void push_back(list_t *l, int val)
// {
//   node_t *n, *cur;
//   n = (node_t *)malloc(sizeof(node_t));
//   n->value = val;
//   n->next = NULL;
//   if (l->head == NULL)
//   {
//     n->prev = NULL;
//     l->head = n;
//   }
//   else
//   {
//     cur = l->head;
//     while (cur->next != NULL)
//       cur = cur->next;
//     cur->next = n;
//     n->prev = cur;
//   }
//   l->size++;
// }