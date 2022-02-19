// Написать программу составления двоичного дерева слов по символьному файлу
// и функцию определения глубины дерева

// -- код Юли --

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char *word; // поле данных
  int count;
  struct node *left;  // левый потомок
  struct node *right; // правый потомок
  struct node *root;  // рут
} node;

typedef struct tree
{
  node *head; // ссылка на корень
  int count;   // количество элементов
} tree;

typedef struct file
{
  char *str;
  int size;
} file;

int file_size(FILE *file)
{
  fseek(file, 0, SEEK_END);
  int fsize = ftell(file);
  fseek(file, 0, SEEK_SET);
  return fsize;
}

file *read_file(char *path)
{
  FILE *f = fopen(path, "r");
  if (f == NULL)
    perror("Error opening file");

  int fsize = file_size(f);
  char *str = (char *)malloc(fsize * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  fclose(f);

  file *temp_file = (file *)malloc(sizeof(file));
  temp_file->str = str;
  temp_file->size = fsize;
  return temp_file;
}

int strcmp(char *s1, char *s2)
{
  char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++))
    if (!c1 || !c2)
      return 0;
  return c1 - c2;
}

int is_char(int ch)
{
  return (int)((97 <= ch && ch <= 122) ||
              (128 <= ch && ch <= 175) ||
              (224 <= ch && ch <= 239) ||
              (65  <= ch && ch <= 90));
}

void addTree(tree *tree, char *str)
{
  node *temp_node = (node *)malloc(sizeof(node));
  temp_node->word = str;
  if (tree->head == NULL)
  {
    tree->head = temp_node;
    temp_node->count = 1;
  }
  else
  {
    node *source = tree->head;
    do
    {
      if (strcmp(str, source->word) > 0)
        source = source->right;
      else if (strcmp(str, source->word) < 0)
        source = source->left;
      else
      {
        source->count++;
        break;
      }
    } while (source != NULL);
    source = temp_node;
  }
}

void parse_str(char *temp, int size, tree *tree)
{
  int capacity = 1, len = 0;
  char *str = (char *)malloc(sizeof(char));
  for (int i = 0; i < size; i++)
  {
    if (is_char(temp[i]))
    {
      str[len++] = temp[i];
      if (len >= capacity)
        str = (char *)realloc(str, (capacity *= 2) * sizeof(char));
      if (size - i == 1)
        goto word_end;
    }
    else
    {
    word_end:
      if (len)
      {
        str[len] = '\0';
        addTree(tree, str);
        capacity = 1;
        len = 0;
        str = (char *)malloc(sizeof(char));
      }
    }
  }
}

void init(struct tree *t)
{
  t->head = NULL;
  t->count = 0;
}

void printTree(struct node *node)
{
  printf("%d %s\n", node->count, node->word);
  if (node->left != NULL)
    printTree(node->left);
  if (node->right != NULL)
    printTree(node->right);
}


int main()
{
  file *f = read_file("newtext.txt");
  tree *my_tree;
  init(my_tree);
  parse_str(f->str, f->size, my_tree);
  printTree(my_tree->head);
}