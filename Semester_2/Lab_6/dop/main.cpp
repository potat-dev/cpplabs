// По символьному файлу составить два линейных списка слов,
// упорядоченных по алфавиту и по количеству гласных букв
// вывести оба списка

// доп: сделать управление функциями
// (0 - выход из цикла, 1 - удаление элемента, 2 - вставка элемента)

#include "snippets.h"

int main() {
  file *file = read_file("input.txt");
  list *words = parse_file(file);

  int running = 1;
  while (running) {
    int option, id, id2, order;
    char *str;
    node *curr;

    printf("Enter option >> ");
    scanf("%d", &option);

    switch (option) {
      case HELP:  // working!
        printf("\nAvailable commands:\n");
        printf(
            "0 - EXIT\n1 - HELP\n2 - REMOVE\n3 - INSERT\n4 - SORT\n5 - "
            "SORTx2\n9 - PRINT\n\n");
        break;

      case EXIT:  // working!
        running = 0;
        break;

      case REMOVE:  // working!
        printf("Enter node index to delete: ");
        scanf("%d", &id);
        remove_node(words, id);
        break;

      case INSERT:  // working!
        printf("Enter index: ");
        scanf("%d", &id);
        printf("Enter word: ");
        str = read_str();
        curr = get_node(words, id);
        insert(words, curr, str);
        break;

      case SORT:                                // working!
        printf("Enter sort type and order: ");  // see type in snippets
        scanf("%d %d", &id, &order);
        sort_list(words, id, order);
        break;

      case SORTx2:  // working!
        printf("Enter sort types and order: ");
        scanf("%d %d %d", &id, &id2, &order);
        double_sort(words, id, id2, order);
        break;

      case PRINT:  // working!
        print_list(words);
        break;

      default:
        printf("Unknown command: %d !!!\n", option);
        printf("Enter 1 to get help\n");
        break;
    }
  }

  destroy(words);
}