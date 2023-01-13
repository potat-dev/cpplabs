#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;
bool check(int** desk, int n, int i, int j) {
  int k, tmp_i1, tmp_i2, tmp_j;

  for (k = 0; k < j; k++) {
    if (desk[i][k] == 1) return 0;
  }
  tmp_i1 = i - 1;
  tmp_j = j - 1;

  while (tmp_i1 >= 0 && tmp_j >= 0) {
    if (desk[tmp_i1][tmp_j] == 1) return 0;
    tmp_i1--;
    tmp_j--;
  }
  tmp_i2 = i + 1;
  tmp_j = j - 1;
  while (tmp_i2 < n && tmp_j >= 0) {
    if (desk[tmp_i2][tmp_j] == 1) return 0;
    tmp_i2++;
    tmp_j--;
  }
  return 1;
}
int pherz(int** desk, int* index, int j, int n) {
  int counter = 0;
  if (j >= n) {
    // for(int k = 0; k < n; k++)
    // 	cout << index[k];
    // cout << endl;
    // for(int i = 0; i < n; i++){
    // 	for(int j = 0; j < n; j++){
    // 		cout << desk[i][j];
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;
    return 1;
  } else {
    for (int i = 0; i < n; i++) {
      if (check(desk, n, i, j)) {
        desk[i][j] = 1;
        index[j] = i;
        counter += pherz(desk, index, j + 1, n);
        desk[i][j] = 0;
        index[j] = 0;
      }
    }
    return counter;
  }
}
int main() {
  int** desk;
  int* index;

  int n, i, j;
  cout << "n = ";
  cin >> n;
  index = new int[n];
  desk = new int*[n];
  for (i = 0; i < n; i++) {
    desk[i] = new int[n];
    for (j = 0; j < n; j++) {
      desk[i][j] = 0;
      index[j] = 0;
    }
  }
  cout << "Amount = " << pherz(desk, index, 0, n) << endl;
  for (i = 0; i < n; i++) delete[] desk[i];
  delete desk;
  delete index;
}
