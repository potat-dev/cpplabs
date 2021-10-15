#include <stdio.h>

void main () {
  int ptr = 42;
  int *ptrr = &ptr;
  int **ptrrr = &ptrr;
  int ***ptrrrr = &ptrrr;
  int ****ptrrrrr = &ptrrrr;
  int *****ptrrrrrr = &ptrrrrr;
  int ******ptrrrrrrr = &ptrrrrrr;
  int *******ptrrrrrrrr = &ptrrrrrrr;
  int ********ptrrrrrrrrr = &ptrrrrrrrr;
  int *********ptrrrrrrrrrr = &ptrrrrrrrrr;
  int **********ptrrrrrrrrrrr = &ptrrrrrrrrrr;
  int ***********ptrrrrrrrrrrrr = &ptrrrrrrrrrrr;
  int ************ptrrrrrrrrrrrrr = &ptrrrrrrrrrrrr;
  int *************ptrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrr;
  int **************ptrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrr;
  int ***************ptrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrr;
  int ****************ptrrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrrr;
  int *****************ptrrrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrrrr;
  int ******************ptrrrrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrrrrr;
  int *******************ptrrrrrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrrrrrr;
  int ********************ptrrrrrrrrrrrrrrrrrrrrr = &ptrrrrrrrrrrrrrrrrrrrr;

  printf("Answer is: %d", ********************ptrrrrrrrrrrrrrrrrrrrrr);
}