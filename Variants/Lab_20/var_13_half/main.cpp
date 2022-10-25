// Неориентированный граф задан матрицей смежности. В файле задается вершина
// с которой начинается обход. Выполнить нерекурсивный алгоритм dfs и выписать
// количество связей для каждой вершины в порядке обхода (d-номер вершины)

// доп: выводить весь стек на каждой итерации

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

#define DOP

using namespace std;

class Graph {
 private:
  vector<vector<int>> adj;  // Список смежности (изначально пустой)
  int root;  // Корень

 public:
  Graph(const string &filename) {  // Считывание графа из файла
    ifstream fin(filename);
    if (!fin.is_open()) throw runtime_error("File not found: " + filename);

    fin >> root;  // Считываем корень
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

#ifdef DOP
  void printStack(stack<int> s) {
    cout << "[";
    while (!s.empty()) {
      cout << s.top();
      s.pop();
      if (!s.empty()) cout << ", ";
    }
    cout << "]" << endl;
  }
#endif

  void dfs() {
    int iter = 0;
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
      ++iter;
#ifdef DOP
      cout << "(iter " << iter << ") stack: ";
      printStack(st);
#endif
      int top = st.top();
      st.pop();
      if (!visited[top]) {
        visited[top] = true;
        // Добавление в стек соседних вершин
        int count = 0;
        for (int i = 0; i < adj[top].size(); i++) {
          if (adj[top][i] == 1) {
            st.push(i);
            count++;
          }
        }
        cout << "(iter " << iter << ") vertex " << top;
        cout << ": d = " << count << endl;
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