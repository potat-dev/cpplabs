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

void set(list_t *l, int index, char *ws, size_t sizews, int capws)
{
	node_t *temp = get_node(l, index);
	word_s *w_t = temp->word;
	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	check_word_info(w_t);
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