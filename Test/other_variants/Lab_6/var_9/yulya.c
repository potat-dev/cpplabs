///Написать программу составления двоичного дерева слов по символьному файлу и функцию определения глубины дерева
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char *word; // поле данных
    int count;
    struct tnode *left;  // левый потомок
    struct tnode *right; // правый потомок
    struct tnode *root;  // рут

} tnode;

typedef struct tree
{
    tnode *head; // ссылка на корень
    int count;   // количество элементов
} tree;

typedef struct file
{
    char *str;
    int size;
} file;

size_t file_size(FILE *file)
{
    fseek(file, 0, SEEK_END);
    size_t fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fsize;
}

file *read_file(char *path) // "test.txt"
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
        perror("Error opening file");
    // read string from file
    size_t fsize = file_size(f);
    char *str = (char *)malloc(fsize * sizeof(char));
    for (size_t i = 0; i < fsize; i++)
        str[i] = fgetc(f);
    fclose(f);
    // create file structure
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
                 (65 <= ch && ch <= 90));
}
void addTree(tree *tree, char *str)
{
    tnode *temp_node = (tnode *)malloc(sizeof(tnode));
    temp_node->word = str;
    if (tree->head == NULL)
    {
        tree->head = temp_node;
        temp_node->count = 1;
    }
    else
    {
        tnode *source = tree->head;
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
// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!// Юля лох !!!!
void parse_str(char *temp, size_t size, tree *tree)
{
    int capacity = 1, len = 0;
    char *str = (char *)malloc(sizeof(char));
    for (size_t i = 0; i < size; i++)
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



// пиши тут
// yulya.work();
// denis.tea();

void printTree(struct tnode *node)
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
    tree my_tree;
    init(&my_tree);
    parse_str(f->str, f->size, &my_tree);
    printTree((&my_tree)->head);
}