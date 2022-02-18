//Во всех заданиях располагать узлы списка/дерева в динамической памяти. Предусмотреть функции вывода на экран списка/дерева.
//Написать программу составления двоичного дерева слов по символьному файлу и функцию определения глубины дерева.
//удалить минимальное слово из правого поддерева
#include<stdio.h>
#include<stdlib.h>
#define MAX 110

        int sizefile(FILE* file) {
    if ((fopen_s(&file, "newtext.txt", "r") != NULL) || (file == NULL)) {
        printf("ERROR");
        return 0;
    }
    else {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        fclose(file);
        if (pos <= 1) {
            return 0;
        }
        else {
            return pos;
        }
    }
}
       
      typedef struct Tree {
          struct Tree* left;
          struct Tree* right;
          char word[MAX];    
          int count;
          struct Tree* root;
      } Node;
     
      Node* add(Node* tree, char slovo[MAX]) {
          int p = 0;
          if (tree == NULL) {
              Node* tmp = (Node*)malloc(sizeof(Node));
              if (tmp != NULL) {
                  while (slovo[p] != '\0') {
                      tmp->word[p] = slovo[p];
                      p++;
                  }
                  tmp->word[p] = '\0';  
                  tmp->left = tmp->right = tmp->root = NULL;
                  tree = tmp;
              }
          }  
          else {
              if (slovo[0] < tree->word[0]) {
                  tree->right = add(tree->right, slovo);
              }
              else if (slovo[0] > tree->word[0]) {
                  tree->left = add(tree->left, slovo);
              }
              else if(slovo[0] == tree->word[0]) {
                  int y = 0; int x = 0;
                  while (slovo[y] == tree->word[y]) {
                      ++y;
                  }if (slovo[y] < tree->word[y]) {
                      tree->right = add(tree->right, slovo);
                  }
                  else if (slovo[y] > tree->word[y]) {
                      tree->left = add(tree->left, slovo);
                  }
              }
              else {
                  printf("error in the function\n");
              }
              
          }
          return(tree);
          
      }

      int DeepTree(Node* tree) {
          int deepR = 0;
          int deepL= 0;
          if (tree == NULL) {
              printf("error in the memory");
              return 0;
          }
          if (tree->left != NULL) {
              deepL = DeepTree(tree->left);
              deepL++;

          }
          if (tree->right != NULL) {
              deepR = DeepTree(tree->right);
              deepR++;
          }
          if (deepR > deepL) {
              return deepR;
          }
          else {
              return deepL;
          }
              
         
      }

      void Print(Node* root, int y) {


          int p = 0;
          char str[50];

          if (root == NULL) {
              return;
          }Print(root->left, y + 10);
          for (int i = 0; i < y; i++) {
              printf(" ");
          }
          
          if (root->word) {
              while (root->word[p] != '\0') {
                  str[p] = root->word[p];
                  p++;
              }
              str[p] = '\0';
              printf("%s\n", str);
          }
          Print(root->right, y+10 );

      }

        int main() {

            char* string = NULL;
            int k = 0;
            char tmp[100];
            long size;
            char* tmp2 = NULL;
            char* lefttmp = NULL;
            char* righttmp = NULL;
            FILE* filewords;
            if ((fopen_s(&filewords, "newtext.txt", "r") != NULL) || (filewords == NULL)) {
                printf("ERROR");
            }
            else {
                size = sizefile(filewords);
                if (size > 3) {
                    string = (char*)malloc(size + 2);
                    if (string != NULL) {
                        fgets(string, size + 2, filewords);
                        fclose(filewords);
                        string[size] = ' ';
                        string[size + 1] = '\0';
                    }
                    else {
                        printf("error\n");
                        free(string);
                        fclose(filewords);
                    }
                }
                else {
                    printf("Line size too small\n");
                    free(string);
                    fclose(filewords);
                }
            }
            printf("%s\n\n\n", string);
            int end = 0;
            int cop = 0;
            int cup = 0;
            int sp = 0;
            struct Tree* stTree = NULL;
            if (string != NULL) {
                while (string[end] != '\0') {
                    
                    if (string[end] == ' ') {
                        cop = 0;
                        while (cup <= end) {
                            tmp[cop] = string[cup];
                            cup++; cop++;
                        }
                        tmp[cop] = '\0';
                   
                        stTree = add(stTree, tmp);
                     
                       
                    }
                    ++end;
                }
            } 
            sp = 10;
          int dee = DeepTree(stTree);
            Print(stTree, sp);
           printf("\n\nThe depth of this tree is:   %d\n\n\n", dee);
            free(string);
            return 0;
          
        }
                
            
        
