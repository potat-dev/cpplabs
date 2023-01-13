#include <stdio.h>

#include <iostream>

using namespace std;
void rucksack(int* w, int* c, int v, int cur_v, int* set, int n, int cur_i,
              int cur_val, int& max_val, int* max_set) {
  // n это количество предметов
  // v  это вместимость рюкзака
  // w это массив весов предметов
  // c это массив стоимостей предметов
  // cur_v это текущий вес
  // cur_i это текущий индекс предмета
  // cur_val это текущая стоимость
  // max_val это максимальная стоимость
  // set это массив, в котором хранится текущий набор предметов
  // max_set это массив, в котором хранится максимальный набор предметов
  // (максимальная стоимость)

  if (v == 0 || cur_i == n) {  // если вместимость рюкзака равна 0 или текущий
                               // индекс предмета равен количеству предметов
    // if there is no more capacity or no more items, check if the current value
    // is greater than the maximum value
    if (cur_val > max_val) {
      // if it is, set the maximum value to the current value
      max_val = cur_val;
      // and set the maximum set to the current set
      for (int k = 0; k < n; k++) {
        max_set[k] = set[k];
        // cout << set[k] << ' ';
      }
      // cout << ": " << *max_val << endl;
    }
  } else {
    // if there is still capacity and items to consider
    for (int i = 0; i <= v / w[cur_i]; i++) {  // v / w[cur_i] это количество
                                               // предметов, которые можно
                                               // положить в рюкзак
      // for each item, check the value of all possible combinations of that
      // item
      cur_v += w[cur_i] * i;  // добавляем вес предмета к текущему весу
      cur_val +=
          c[cur_i] * i;  // добавляем стоимость предмета к текущей стоимости
      set[cur_i] = i;  // добавляем количество предмета к текущему набору
      // recursively call the function to check the next item
      rucksack(w, c, v - w[cur_i] * i, cur_v, set, n, cur_i + 1, cur_val,
               max_val, max_set);
      //  cur i + 1 это следующий индекс предмета
      // v - w[cur_i] * i это оставшаяся вместимость рюкзака
      // cur_v это текущий вес
      // then set the current value and set back to the values before the
      // function call

      // возращаем текущий вес и текущий набор к значениям до вызова функции
      set[cur_i] = 0;
      cur_v -= w[cur_i] * i;
      cur_val -= c[cur_i] * i;
    }
  }
}

int main() {
  int n = 7;
  int w[n] = {3, 4, 2, 3, 5, 2, 4};
  int c[n] = {11, 20, 17, 32, 1, 10, 20};
  // int w[n] = {8, 4, 2, 3, 5, 2, 4};
  // int c[n] = {110, 20, 17, 32, 1, 10, 20};

  int max_value = 0;
  int* set = new int[n];
  int* max_set = new int[n];
  for (int i = 0; i < n; i++) {
    set[i] = max_set[i] = 0;
  }
  int i, v;
  cout << "V = ";
  cin >> v;
  // Что такое V?
  // Это вместимость рюкзака.
  // V = 10
  rucksack(w, c, v, 0, set, n, 0, 0, max_value, max_set);
  for (int k = 0; k < n; k++) cout << max_set[k] << ' ';
  cout << endl;
  delete set;
  delete max_set;
}

// Объясни сложность алгоритма:

// Сложность алгоритма O(2^n)
// Почему?
// Потому что в функции rucksack есть цикл for (int i = 0; i <= v / w[cur_i];
// i++), который выполняется 2^n раз. Почему 2^n? Потому что в цикле for (int i
// = 0; i <= v / w[cur_i]; i++) мы перебираем все возможные комбинации
// предметов. Например, если у нас есть 3 предмета, то мы перебираем все
// возможные комбинации из 3 предметов. Таких комбинаций 2^3 = 8.