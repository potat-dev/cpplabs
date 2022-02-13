// list  ->  содержит указатель на начало связанного списка node
// node  ->  содержит ссылку на number и ссылки на пред/след элемент

// struct File

typedef struct file {
  char *str;
  int size;
} file;

int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
}

file *read_file(char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL)
    perror("Error opening file");

  int fsize = file_size(f);
  char *str = (char*) malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  fclose(f);

  file *temp_file = (file*) malloc(sizeof(file));
  temp_file -> str = str;
  temp_file -> size = fsize;
  return temp_file;
}

// struct Node

typedef struct node {
  int n;
  struct node *next;
} node;

// struct List

typedef struct list {
  int  size;
  node *head;
} list;

void init(list *list) {
  list -> head = NULL;
  list -> size = 0;
}

void destroy(list *list) {
  node *curr = list -> head;
  node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr -> next;
    free(prev);
  }
}

void push_back(list *list, char *str, int capacity) {
  int num = 0; // -- str
  node *n = (node*) malloc(sizeof(node));
  node *curr;

  n -> n = 0;
  n -> next = NULL;

  if(list -> head == NULL) {
    list -> head = n;
  } else {
    curr = list -> head;
    while (curr -> next != NULL)
      curr = curr -> next;
    curr -> next = n;
  }
  list -> size++;
}

// other

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