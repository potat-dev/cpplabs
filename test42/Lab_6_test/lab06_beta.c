#include <stdio.h>
#include <stdlib.h>
#include "../../code_snippets.c"
// Написать программу, составляющую по двум символьным файлам линейные упорядоченные списки различных слов и функцию конкатенации списков. Выдать объединенный список на экран.


int main(int argc, char *argv[])
{
	int num;
	FILE *f1;
	FILE *f2;

	// Exception check
	if (
		(f1 = fopen("mylabs/lab06/t1.txt", "r")) == NULL || (f2 = fopen("mylabs/lab06/t2.txt", "r")) == NULL)
	{
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

	char *s1 = (char *)malloc(f1size * sizeof(char));
	char *s2 = (char *)malloc(f2size * sizeof(char));

	for (size_t i = 0; i < f1size; i++)
		s1[i]=fgetc(f1);
	for (size_t i = 0; i < f2size; i++)
		s2[i]=fgetc(f2);
	
	list_t l1, l2, lmerge;
	init(&l1);init(&l2);init(&lmerge);
	
	readstr(s1, f1size, &l1);
	readstr(s2, f2size, &l2);

	merge_list_t(&l1, &lmerge);
	merge_list_t(&l2, &lmerge);

	swap_lis((&lmerge)->head, (&lmerge)->head->next);
	// swap_lis(&lmerge->head, &lmerge->head->next);
	print_list(&lmerge);

	destroy(&l1);destroy(&l2);destroy(&lmerge);

	free(s1);
	free(s2);
	fclose(f1);
	fclose(f2);
	return 0;
}