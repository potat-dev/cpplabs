// Ориентированный граф задан и хранится матрицей смежности
// В файле также задается вершина, с которой начинается обход
// Построить дерево обхода с помощью bfs
// Определить типы ребер графа и вывести их на экран

// доп:
// сгенерировать изображение графа с помощью graphviz
// раскрасить вершины в зависимости от типа ребер

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

  void getEdgesBFS() {  // обход в ширину
    queue<int> q;       // очередь для хранения вершин
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

    // определяем типы остальных ребер
    // использован алгоритм из ответа на StackOverflow
    // https://stackoverflow.com/a/29710587/15301038

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
  }

  void printEdges() {
    for (auto edge : edges) {
      int a = edge.first.first, b = edge.first.second;
      switch (edge.second) {
        case EdgeType::TREE:
          cout << a << " --> " << b << " tree" << endl;
          break;
        case EdgeType::BACK:
          cout << b << " <-- " << a << " back" << endl;
          break;
        case EdgeType::CROSS:
          cout << a << " --- " << b << " cross" << endl;
          break;
      }
    }
  }

#ifdef DOP
  void exportGraphviz(string filename) {
    ofstream fout(filename);
    if (!fout.is_open()) throw runtime_error("File not found");
    fout << "digraph G {" << endl;
    for (auto edge : edges) {
      int a = edge.first.first, b = edge.first.second;
      switch (edge.second) {
        case EdgeType::TREE:
          fout << "  " << a << " -> " << b << " [color=green]" << endl;
          break;
        case EdgeType::BACK:
          fout << "  " << b << " -> " << a << " [color=red]" << endl;
          break;
        case EdgeType::CROSS:
          fout << "  " << a << " -> " << b << " [color=blue]" << endl;
          break;
      }
    }
    fout << "}";
  }
#endif
};

// получаем имя файла из аргументов командной строки
// в допе еще и сохраняем граф в формате Graphviz
int main(int argc, char* argv[]) {
#ifndef DOP
  if (argc != 2) cout << "Usage: " << argv[0] << " <filename>" << endl;
#else
  if (argc != 3) cout << "Usage: " << argv[0] << " <filename> <output>" << endl;
#endif
  else {
    Graph g(argv[1]);
    g.getEdgesBFS();
    g.printEdges();
#ifdef DOP
    g.exportGraphviz(argv[2]);
#endif
  }
}