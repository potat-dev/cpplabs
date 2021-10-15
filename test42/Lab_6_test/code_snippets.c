#include <stdio.h>
#include <stdlib.h>

//File
typedef struct file_s
{
	char *arr;
	int size;
} file_s;
size_t file_size(FILE *f)
{
	// https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
	fseek(f, 0, SEEK_END);	 // seek to end of file
	size_t fsize = ftell(f); // get current file pointer
	fseek(f, 0, SEEK_SET);	 // seek back to beginning of file
	return fsize;
}

file_s *read_file(char *filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("Error! opening files");
		exit(1);
	}

	size_t fsize = file_size(f);
	char *s = (char *)malloc(fsize * sizeof(char));
	for (size_t i = 0; i < fsize; i++)
		s[i] = fgetc(f);

	file_s *tstur = (file_s *)malloc(sizeof(file_s));
	;
	tstur->arr = s;
	tstur->size = fsize;
	fclose(f);
	return tstur;
}

// STRINGS
char lower(int c)
{
	return c > 64 && c < 91 ? c + 32 : c;
}
int is_char(int ch)
{
	if (
			(65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
			(128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
		return 1;
	else
		return 0;
}
int is_glasn(int ch)
{
	ch = lower(ch);
	if (
			ch == 'a' ||
			ch == 'e' ||
			ch == 'u' ||
			ch == 'i' ||
			ch == 'o' ||
			ch == 'y')
		return 1;
	else
		return 0;
}
int cstrlenc(char *str, int dlinna)
{
	// print_array(str, dlinna);
	for (int i = 0; i < dlinna; i++)
	{
		if (str[i] == '\0' || str[i] == '\n')
			return i;
	}
	return dlinna;
}

// STRUCTS
typedef struct word_s
{
	char *arr;
	int size;
	int glasn;
	int sogl;
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
struct node_t *get_node(list_t *l, int i)
{
	int count = 0;
	node_t *curr = l->head;
	while (count++ != i)
	{
		curr = curr->next;
	}
	return curr;
};

void init(list_t *l)
{
	l->head = NULL;
	l->size = 0;
}

void destroy_node(node_t *node)
{
	free(node->word->arr);
	free(node->word);
	free(node);
}

void destroy(list_t *l)
{
	node_t *cur = l->head;
	node_t *prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		destroy_node(prev);
	}
}

void check_word_info(word_s *word)
{
	int sogl = 0, glasn = 0;
	for (size_t i = 0; i < word->size; i++)
	{
		if (is_char(word->arr[i]) == 1)
			if (is_glasn(is_char(word->arr[i])) == 1)
				glasn++;
			else
				sogl++;
	}
	word->sogl = sogl;
	word->glasn = glasn;
}

struct word_s *gen_word(char *ws, size_t sizews, int capws)
{
	word_s *w_t = (word_s *)malloc(sizeof(word_s));

	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	check_word_info(w_t);
	return w_t;
}

void push_front(list_t *l, char *ws, size_t sizews, int capws)
{
	node_t *n = (node_t *)malloc(sizeof(node_t));
	word_s *w_t = gen_word(ws, sizews, capws);
	n->word = w_t;
	n->next = l->head;
	l->head->prev = n;
	l->head = n;
	l->size++;
}

void push_back(list_t *l, char *ws, size_t sizews, int capws)
{

	node_t *n, *cur;

	word_s *w_t = gen_word(ws, sizews, capws);
	n = (node_t *)malloc(sizeof(node_t));

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

void insert(list_t *l, node_t *cur, char *ws, size_t sizews, int capws)
{
	node_t *n = (node_t *)malloc(sizeof(node_t));
	word_s *w_t = gen_word(ws, sizews, capws);
	n->word = w_t;
	n->next = cur->next;
	n->prev = cur;
	cur->next->prev = n;
	cur->next = n;
	l->size++;
}

void erase(list_t *l, node_t *cur)
{
	if (cur == l->head)
	{
		l->head = cur->next;
		if (cur->next != NULL)
			cur->next->prev = NULL;
		destroy_node(cur);
	}
	else
	{
		cur->prev->next = cur->next;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
		destroy_node(cur);
	}
	l->size--;
}

void list_remove(list_t *l, int index)
{
	node_t *cur = get_node(l, index);
	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	if (index == 0)
		if (l->head->next != NULL)
			l->head = l->head->next;
		else
			l->head = NULL;
	destroy_node(cur);
	l->size--;
}

word_s *get(list_t *l, int i)
{
	node_t *cur = l->head;
	struct word_s *result = cur->word;
	int count = 0;
	// if (i < 0 || i >= l -> size)
	// 	return -1;
	while (count != i)
	{
		cur = cur->next;
		result = cur->word;
		count++;
	}
	return result;
}

void set(list_t *l, int index, char *ws, size_t sizews, int capws)
{
	node_t *temp = get_node(l, index);
	word_s *w_t = temp->word;
	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	check_word_info(w_t);
}

void readstr(char *tmp, size_t size, list_t *list)
{
	int len = 0;
	int capacity = 1;												// емкость динамической строки
	char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка
	for (size_t i = 0; i < size; i++)
	{
		if (is_char(tmp[i]) == 1)
		{
			s[(len)++] = tmp[i];
			if (len >= capacity)
			{																									 // если реальный размер больше размера контейнера, то увеличим его размер
				capacity *= 2;																	 // увеличиваем емкость в два раза
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
				capacity = 1;											// емкость динамической строки
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
		cur = cur->next;
	}
}

void print_list(list_t *l)
{
	for (size_t i = 0; i < l->size; i++)
	{
		printf("------------------------\n");
		word_s *temp = get(l, i);
		printf("%lu || %s\n", i, temp->arr);
		printf("------------------------\n\n");
	}
}

void swap_word(node_t *n1, node_t *n2)
{
	struct word_s *temp = n2->word;
	n2->word = n1->word;
	n1->word = temp;
}

int compare_words(char *w1, char *w2, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (w1[i] != w2[i])
			return 0;
	}
	return 1;
}

int find_word(list_t *l, int offset, char *temp, size_t temp_size)
{
	for (size_t i = offset; i < l->size; i++)
	{
		word_s *getted_word = get(l, i);
		if (getted_word->size == temp_size && compare_words(temp, getted_word->arr, temp_size))
			return i;
	}
	return -1;
}

void remove_duplicates(list_t *l)
{
	for (size_t i = 0; i < l->size; i++)
	{
		node_t *curr = get_node(l, i);
		int founded_word;
		while ((founded_word = find_word(l, i + 1, curr->word->arr, curr->word->size)) != -1)
			list_remove(l, founded_word);
	}
}

// 1 - w1 < w2  ||  A<B
int check_alphabet(char *w1, char *w2, size_t size)
{
	printf("  (%s %s) ", w1, w2);
	for (int i = 0; i < size; i++)
	{
		if (w1[i] > w2[i])
		{
			return 0;
		}
		else if (w1[i] < w2[i])
		{
			return 1;
		}
		else
			continue;
	}
	return 1;
}

void sort_list_alph(list_t *l, int reverse)
{
	for (size_t j = 0; j < l->size; j++)
	{
		for (size_t i = (l->size - 1); i > j; i--)
		{
			struct node_t *node1 = get_node(l, i);
			struct node_t *node2 = get_node(l, i - 1);
			int min_node = node1->word->size < node2->word->size ? node1->word->size : node2->word->size;
			int need_to_sort = check_alphabet(node1->word->arr, node2->word->arr, min_node);

			need_to_sort = reverse == 0 ? !need_to_sort : need_to_sort;
			if (need_to_sort)
			{
				swap_word(node1, node2);
			}
		}
	}
}

void sort_list_size(list_t *l, int reverse)
{
	for (size_t j = 0; j < l->size; j++)
	{ // TODO: спросить Янковского за size_t
		for (size_t i = (l->size - 1); i > j; i--)
		{
			struct node_t *node1 = get_node(l, i);
			struct node_t *node2 = get_node(l, i - 1);
			int need_to_sort = node1->word->size < node2->word->size ? 0 : 1;

			need_to_sort = reverse == 0 ? !need_to_sort : need_to_sort;
			if (need_to_sort)
			{
				swap_word(node1, node2);
			}
		}
	}
}

void sort_list_count_glasn(list_t *l, int reverse)
{
	for (size_t j = 0; j < l->size; j++)
	{
		for (size_t i = (l->size - 1); i > j; i--)
		{
			struct node_t *node1 = get_node(l, i);
			struct node_t *node2 = get_node(l, i - 1);
			int need_to_sort = node1->word->glasn < node2->word->glasn ? 0 : 1;

			need_to_sort = reverse == 0 ? !need_to_sort : need_to_sort;
			if (need_to_sort)
			{
				swap_word(node1, node2);
			}
		}
	}
}

void sort_list_count_sogl(list_t *l, int reverse)
{
	for (size_t j = 0; j < l->size; j++)
	{
		for (size_t i = (l->size - 1); i > j; i--)
		{
			struct node_t *node1 = get_node(l, i);
			struct node_t *node2 = get_node(l, i - 1);
			int need_to_sort = node1->word->sogl < node2->word->sogl ? 0 : 1;

			need_to_sort = reverse == 0 ? !need_to_sort : need_to_sort;
			if (need_to_sort)
			{
				swap_word(node1, node2);
			}
		}
	}
}