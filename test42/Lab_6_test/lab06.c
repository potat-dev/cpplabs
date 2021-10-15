#include <stdio.h>
#include <stdlib.h>
// Написать программу, составляющую по двум символьным файлам линейные упорядоченные списки различных слов и функцию конкатенации списков. Выдать объединенный список на экран.


typedef struct {
int value ;
	node_t * prev ;
	node_t * next ; 
} node_t ;

typedef struct {
node_t * head ; 
size_t size ; 
} list_t ;


int main(int argc, char *argv[])
{
	int num;
	FILE *f1;
	FILE *f2;
	

	// Exception check
	if (
		(f1 = fopen("mylabs/lab06/t1.txt", "r")) == NULL || (f2 = fopen("mylabs/lab06/t2.txt", "r")) == NULL
	){
		printf("Error! opening files");
		exit(1);
	}


	// https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c

	fseek(f1, 0, SEEK_END); // seek to end of file
	fseek(f2, 0, SEEK_END);
	size_t f1size = ftell(f1); // get current file pointer
	size_t f2size = ftell(f2);
	fseek(f1, 0, SEEK_SET); // seek back to beginning of file
	fseek(f2, 0, SEEK_SET);

	char * s1 = (char *) malloc(f1size * sizeof(char));
	char * s2 = (char *) malloc(f2size * sizeof(char));
	char word[15] = {0};
	
	cin = 0;
	char ** m = (char **) malloc ( cin * sizeof (char *));
	while(fscanf(f1, "%s", word)==1){
		m = (*char) realloc();
		printf("%s\n", word);
		// m [ i ] = ( int *) malloc ( N * sizeof (int ));
	}
	printf("%d\n", f1size);
	printf("%d\n", f2size);
	// for (size_t i = 0; i < f1size; i++)
	// {
	// 	/* code */
	// }
	

	



	free(s1);
	free(s2);
	fclose(f1);
	fclose(f2);
	return 0;
}