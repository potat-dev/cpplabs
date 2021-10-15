// // обычная сортировка - старая версия
// void sort_list_old(list *list, int sort_type, int reverse) {
//   for (int i = 0; i < list->size; i++) {
//     for (int j = i+1; j < list->size; j++) {
//       struct node *node1 = get_node(list, i);
//       struct node *node2 = get_node(list, j);
//       int swap = 0;
//       switch (sort_type) {
//         case ALPHABET:
//           swap = compare_words(node1->word, node2->word, reverse) < 0;
//           break;
//         case LENGTH:
//           swap = reverse ^ (node1->word->size > node2->word->size);
//           break;
//         case VOWELS:
//           swap = reverse ^ (node1->word->vowels > node2->word->vowels);
//           break;
//         case CONSNTS:
//           swap = reverse ^ (node1->word->consnts > node2->word->consnts);
//           break;
//         default:
//           printf("Invalid sorting configuration!");
//       }
//       if (swap) swap_nodes(node1, node2);
//     }
//   }
// }

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