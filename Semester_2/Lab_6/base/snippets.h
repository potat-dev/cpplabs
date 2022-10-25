#include <stdio.h>
#include <stdlib.h>

struct file;
struct node;
struct list;
struct word;

// конфиги
#define NORMAL 0
#define REVERSE 1

#define ALPHABET 0
#define LENGTH 1
#define VOWELS 2
#define CONSNTS 3

#define EXIT 0
#define HELP 1
#define REMOVE 2
#define INSERT 3
#define SORT 4
#define SORTx2 5
#define PRINT 9

int file_size(FILE *file);
file *read_file(const char *path);
void init(list *list);
void destroy_word(word *word);
void destroy_node(node *node);
void destroy(list *list);
char *read_str();
int strlen(char *str);
int vowels_count(char *str);
void upd_word(word *w);
struct word *make_word(char *str, int capacity);
char lower(int ch);
void push_back(list *list, char *str, int capacity);
void merge_lists(list *source, list *destination);
struct word *get_word(list *list, int index);
struct node *get_node(list *list, int index);
void print_list(list *list);
int is_char(int ch);
int strcmp(char *s1, char *s2);
void edit_word(list *list, int index, char *str, int cap);
void swap_nodes(node *n1, node *n2);
void parse_str(char *temp, size_t size, list *list);
list *parse_file(file *file);
int compare_words(word *w1, word *w2, int order);
void insert(list *list, node *curr, char *str);
int find_word(list *list, char *str, int offset, int order);
void remove_node(list *list, int index);
void remove_nodes(list *list, int start, int end);
int need_swap(word *w1, word *w2, int sort_type, int reverse);
void sort_list(list *list, int sort_type, int reverse);
void double_sort(list *list, int sort_1, int sort_2, int order);
void double_sort_2(list *list, int sort_1, int sort_2, int order);