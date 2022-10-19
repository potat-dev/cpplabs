// Неориентированный граф задан матрицей смежности. В файле задается вершина
// с которой начинается обход. Выполнить нерекурсивный алгоритм dfs и выписать
// количество связей для каждой вершины в порядке обхода (d-номер вершины)

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
 private:
  vector<vector<int>> adj;  // Список смежности (изначально пустой)
  int root;  // Корень

 public:
  Graph(const string &filename) {  // Считывание графа из файла
    ifstream fin(filename);
    if (!fin.is_open())
      throw runtime_error("File not found: " + filename);

    fin >> root; // Считываем корень
    // Пока не дошли до конца файла
    while (!fin.eof()) {
      vector<int> row(0, 0);
      int n;
      // Считывание вектора
      while (fin >> n) {
        row.push_back(n);
        // Если конец строки
        if (fin.peek() == '\n') break;
      }
      // Добавление вектора в матрицу
      adj.push_back(row);
    }
  }

  void dfs() {
    vector<bool> visited(adj.size(), false);
    stack<int> st;

    st.push(root);
    while (!st.empty()) {
      int top = st.top();
      st.pop();
      if (!visited[top]) {
        visited[top] = true;
        cout << "(vertex " << top << ") - ";
        // Добавление в стек соседних вершин
        int count = 0;
        for (int i = 0; i < adj[top].size(); i++) {
          if (adj[top][i] == 1) {
            st.push(i);
            count++;
          }
        }
        cout << count << endl;
      }
    }
  }
};

int main() {
  Graph g("input.txt");
  cout << endl;
  g.dfs();
  return 0;
}