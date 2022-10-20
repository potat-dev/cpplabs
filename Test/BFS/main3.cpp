// Ориентированный граф задан и хранится списком смежности
// В файле задается вершина, с которой начинается обход
// Выписать прямые (ребра дерева обхода bfs),
// обратные ребра и поперечные ребра (не связывают предков и потомков).



#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
 private:
  // Список смежности
  // Изначально пустой
  vector<vector<int>> adj;

 public:
  // load from file
  Graph(const string &filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
      throw runtime_error("File not found: " + filename);
    }
    // until the end of file
    while (!fin.eof()) {
      vector<int> row;
      int n;
      // read vector
      while (fin >> n) {
        row.push_back(n);
        // if the end of line
        if (fin.peek() == '\n') break;
      }
      // add vector to matrix
      adj.push_back(row);
    }
  }

  // print graph
  void print() {
    for (int i = 0; i < adj.size(); i++) {
      cout << i << ": ";
      for (int n : adj[i]) cout << n << " ";
      cout << endl;
    }
  }

  void bfs(int start) {
    // выводить прямые, обратные и поперечные ребра
    // прямые - ребра дерева обхода
    // обратные - ребра, ведущие от потомка к предку
    // поперечные - ребра, не связывающие предков и потомков

    // массив, в котором будут храниться предки
    vector<int> parents(adj.size(), -1);
    // массив, в котором будут храниться цвета вершин
    vector<int> colors(adj.size(), 0);
    // очередь для обхода
    queue<int> q;
    // добавляем стартовую вершину в очередь
    q.push(start);
    // помечаем ее как посещенную
    colors[start] = 1;
    // пока очередь не пуста
    while (!q.empty()) {
      // достаем вершину из очереди
      int v = q.front();
      q.pop();
      // для каждой смежной вершины
      for (int u : adj[v]) {
        // если вершина еще не посещена
        if (colors[u] == 0) {
          // помечаем ее как посещенную
          colors[u] = 1;
          // добавляем в очередь
          q.push(u);
          // запоминаем предка
          parents[u] = v;
        }
      }
    }
    // выводим прямые ребра
    cout << "Прямые ребра:" << endl;
    for (int i = 0; i < parents.size(); i++) {
      if (parents[i] != -1) {
        cout << parents[i] << " -> " << i << endl;
      }
    }
    // выводим обратные ребра
    cout << "Обратные ребра:" << endl;
    for (int i = 0; i < parents.size(); i++) {
      if (parents[i] != -1) {
        cout << i << " -> " << parents[i] << endl;
      }
    }
    // выводим поперечные ребра
    cout << "Поперечные ребра:" << endl;
    for (int i = 0; i < parents.size(); i++) {
      for (int j = 0; j < parents.size(); j++) {
        if (parents[i] != -1 && parents[j] != -1 && parents[i] != parents[j]) {
          cout << i << " -> " << j << endl;
        }
      }
    }

    // выводим предков
    cout << "Предки:" << endl;
    for (int i = 0; i < parents.size(); i++) {
      cout << i << ": " << parents[i] << endl;
    }
  }

};


int main() {
  Graph g("D:\\Projects\\SUAI-Labs\\Semester_3\\Lab_20\\graph.txt");
  g.print();
  cout << "test" << endl;
  g.bfs(0);
  return 0;
}