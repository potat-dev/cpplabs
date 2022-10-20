// Ориентированный граф задан и хранится матрицей смежности
// В файле также задается вершина, с которой начинается обход
// Построить дерево обхода с помощью bfs
// Определить типы ребер графа и вывести их на экран

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>
#include <vector>

using namespace std;

enum class EdgeType { TREE, BACK, CROSS };

class Graph {
 private:
  vector<vector<int>> adj;  // матрица смежности
  vector<int> depth;        // глубина вершины
  vector<int> parent;       // родитель вершины
  int root;                 // корень дерева обхода

  // список ребер {(начало, конец): тип}
  // типы ребер: 0 - дерево, 1 - обратное, 2 - кросс
  map<pair<int, int>, EdgeType> edges;

 public:
  Graph(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) throw runtime_error("File not found");
    fin >> root;
    adj.resize(0);
    // Считываем матрицу смежности
    while (!fin.eof()) {
      vector<int> row;
      int x;
      while (fin >> x) {
        row.push_back(x);
        if (fin.peek() == '\n') break;
      }
      adj.push_back(row);
    }
    depth.resize(adj.size());
    parent.resize(adj.size());
  }

  void bfs() {     // обход в ширину
    queue<int> q;  // очередь для хранения вершин
    vector<bool> visited(adj.size(), false);

    q.push(root);
    visited[root] = true;
    depth[root] = 0;
    parent[root] = -1;

    while (!q.empty()) {
      int v = q.front();  // извлекаем последнюю вершину
      q.pop();            // удаляем ее из очереди
      // просматриваем все вершины, смежные с текущей
      for (int i = 0; i < adj[v].size(); i++) {
        // если ребро существует и вершина не посещена
        if (adj[v][i] == 1 && !visited[i]) {
          q.push(i);
          visited[i] = true;  // помечаем вершину как посещенную
          depth[i] = depth[v] + 1;  // увеличиваем глубину
          parent[i] = v;            // запоминаем родителя
          // добавляем ребро в список ребер
          edges.insert({{v, i}, EdgeType::TREE});
        }
      }
    }
  }

  void printEdgeTypes() {
    // использован алгоритм из ответа на StackOverflow
    // https://stackoverflow.com/a/29710587/15301038

    // проходим по всем ребрам
    for (int i = 0; i < adj.size(); i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        // если ребро существует и его тип не определен
        if (adj[i][j] == 1 && edges.find({i, j}) == edges.end()) {
          int a = i, b = j;
          // ищем общего предка
          while (depth[b] > depth[a]) b = parent[b];
          while (depth[a] > depth[b]) a = parent[a];
          // если общий предок найден
          if (a == b) {
            edges.insert({{i, j}, EdgeType::BACK});
          } else {
            edges.insert({{i, j}, EdgeType::CROSS});
          }
        }
      }
    }

    for (auto edge : edges) {
      int a = edge.first.first, b = edge.first.second;
      switch (edge.second) {
        case EdgeType::TREE:
          cout << a << " --> " << b << " tree" << endl;
          break;
        case EdgeType::BACK:
          cout << a << " <-- " << b << " back" << endl;
          break;
        case EdgeType::CROSS:
          cout << a << " --- " << b << " cross" << endl;
          break;
      }
    }
  }
};

// получаем имя файла из аргументов командной строки
int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  } else {
    Graph g(argv[1]);
    g.bfs();
    g.printEdgeTypes();
  }
}
