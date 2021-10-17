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