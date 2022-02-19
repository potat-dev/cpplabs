// Написать программу составления двоичного дерева слов по символьному файлу
// и функцию определения глубины дерева

#include <stdio.h>
#include <stdlib.h>

typedef struct node { // узел дерева
  char *word;         // указатель на строку слово
  int count;          // число вхождений
  struct node *left;  // левый потомок
  struct node *right; // правый потомок
} node;

typedef struct tree { // само дерево
  node *head;         // ссылка на корень
  int count;          // количество элементов
} tree;

tree* newTree() {
  tree *temp = (tree*)malloc(sizeof(tree));
  temp->head = NULL;
  temp->count = 0;
}

node* newNode(char *word) {
  node *temp = (node*)malloc(sizeof(node));
  temp->left = temp->right = NULL;
  temp->word = word;
  temp->count = 1;
  return temp;
}

int strcmp(char *s1, char *s2) {
  char c1, c2;
  while ((c1 = *s1++) == (c2 = *s2++))
    if (!c1 || !c2)
      return 0;
  return c1 - c2;
}

// Функция добавления узла к дереву
void addNode(node* p, char* w) {
  if (p == NULL) {
    p = (node*)malloc(sizeof(node));
    p->word = w;
    p->count = 1;
    p->left = p->right = NULL;
  } else {
    int cond = strcmp(w, p->word);
    if (!cond)
      p->count++;
    else if (cond < 0)
      addNode(p->left, w);
    else
      addNode(p->right, w);
  }
}

// Функция удаления поддерева
void freemem(node* tree) {
  if (tree != NULL) {
    freemem(tree->left);
    freemem(tree->right);
    free(tree->word);
    free(tree);
  }
}

// Функция вывода дерева
void printTree(node* p) {
  if (p != NULL) {
    printTree(p->left);
    printf("%s", p->word);
    if (p->count > 1) {
      printf("\t - %d times\n", p->count);
    } else {
      printf("\n");
    }
    printTree(p->right);
  }
}


int main() {
  char *arr1 = "a hello world 1";
  char *arr2 = "b hello world 2";
  char *arr3 = "c hello world 3";
  char *arr4 = "d hello world 4";

  node *tree;
  addNode(tree, arr1);
  addNode(tree, arr2);
  addNode(tree, arr3);
  addNode(tree, arr4);

  printTree(tree);
  // getchar(); getchar();
}