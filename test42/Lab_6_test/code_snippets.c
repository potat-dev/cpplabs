#include <stdio.h>
#include <stdlib.h>

int is_char(int ch)
{
	if (
		(65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
		(128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
		return 1;
	else
		return 0;
}

typedef struct word_s
{
	char *arr;
	int size;
	int capacity;
} word_s;

typedef struct node_t
{
	struct word_s *word;
	struct node_t *prev;
	struct node_t *next;
} node_t;

typedef struct list_t
{
	node_t *head;
	size_t size;
} list_t;

void init(list_t *l)
{
	l->head = NULL;
	l->size = 0;
}

void destroy(list_t *l)
{
	node_t *cur = l->head;
	word_s *word = NULL;
	node_t *prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		word = prev->word;
		free(word->arr);
		free(word);
		free(prev);
	}
}

void push_back(list_t *l, char *ws, size_t sizews, int capws)
{
	node_t *n, *cur;
	word_s *w_t;
	n = (node_t *)malloc(sizeof(node_t));
	w_t = (word_s *)malloc(sizeof(word_s));

	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	n->word = w_t;
	n->next = NULL;
	if (l->head == NULL)
	{
		n->prev = NULL;
		l->head = n;
	}
	else
	{
		cur = l->head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n;
		n->prev = cur;
	}
	l->size++;
}

void readstr(char *tmp, size_t size, list_t *list)
{
	int len = 0;
	int capacity = 1;						// емкость динамической строки
	char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка
	for (size_t i = 0; i < size; i++)
	{
		if (is_char(tmp[i]) == 1)
		{
			s[(len)++] = tmp[i];
			if (len >= capacity)
			{													 // если реальный размер больше размера контейнера, то увеличим его размер
				capacity *= 2;									 // увеличиваем емкость в два раза
				s = (char *)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной емкостью
			}
			if (i + 1 == size)
				goto last_char;
		}
		else
		{
		last_char:
			if (len != 0)
			{
				s[len] = '\0';

				push_back(list, s, len, capacity);
				len = 0;
				capacity = 1;					  // емкость динамической строки
				s = (char *)malloc(sizeof(char)); // динамическая пустая строка
			}
		}
	}
}

void merge_list_t(list_t *l, list_t *l_merge)
{
	int size = l->size;
	node_t *cur = l->head;
	for (size_t i = 0; i < size; i++)
	{
		word_s *tmp_str_word = cur->word;
		char *temp_word_arr = (char *)malloc(tmp_str_word->size * sizeof(char));
		for (size_t i = 0; i <= tmp_str_word->size; i++)
		{
			temp_word_arr[i] = tmp_str_word->arr[i];
		}
		push_back(l_merge, temp_word_arr, tmp_str_word->size, tmp_str_word->capacity);
		cur = cur -> next;
	}
}

struct word_s *get(list_t *l, int i)
{
	node_t *cur = l -> head;
	struct word_s *result = cur->word;
	int count = 0;
	// if (i < 0 || i >= l -> size)
	// 	return -1;
	while (count != i)
	{
		cur = cur -> next;
		result = cur->word;
		count++;
	}
	return result;
}

void print_list(list_t *l)
{
	for (size_t i = 0; i < l->size; i++)
	{
		printf("------------------------\n");
		word_s *temp = get(l, i);
		printf("%d || %s\n", i, temp->arr);
		printf("------------------------\n\n");
	}
	
}

// void swap_lis(struct node_t **n1, struct node_t **n2){
// 	struct word_s *temp = *(n2->word);
// 	*(n2->word) = *(n1->word);
// 	*(n1->word) = temp;
// }

void swap_lis(node_t *n1, node_t *n2){
	struct node_t *temp = n2->word;
	n2->word = n1->word;
	n1->word = temp;
}

// void swap_words(word_s *n1, word_s *n2){
// 	struct word_s *temp = n2->word;
// 	n2->word = n1->word;
// 	n1->word = temp;
// }

void sort_list_alph(list_t *l, int reverse){
	
}