// list  ->  содержит указатель на начало связанного списка node
// node  ->  содержит ссылку на number и ссылки на пред/след элемент

int len = 0;
char *read_str() {
  len = 0;
  int capacity = 1;
  char *s = (char *)malloc(sizeof(char));
  char c = getchar();
  while (c == '\n') c = getchar();
  while (c != '\n') {
    s[(len)++] = c;
    if (len >= capacity) {
      capacity *= 2;
      s = (char *)realloc(s, capacity * sizeof(char));
    }
    c = getchar();
  }
  s[len] = '\0';
  return s;
}

int is_int(int ch) {
  return (int)('0' <= ch && ch <= '9');
}

void parse_str(char *temp, size_t size, list *list) {
  int capacity = 1, len = 0;
  char *str = (char*) malloc(sizeof(char));
  for (size_t i = 0; i < size; i++) {
    if (is_int(temp[i])) {
      str[len++] = temp[i];
      if (len >= capacity)
        str = (char*) realloc(str, (capacity *= 2) * sizeof(char));
      if (size - i == 1)
        goto word_end;
    } else {
      word_end:
      if (len) {
        str[len] = '\0';
        push_back(list, str, capacity);
        capacity = 1; len = 0;
        str = (char*) malloc(sizeof(char));
      }
    }
  }
}

list *parse_file(file *file) {
  list *temp_list = (list*) malloc(sizeof(list));
  init(temp_list);
  parse_str(file -> str, file -> size, temp_list);
  free(file -> str);
  free(file);
  return temp_list;
}