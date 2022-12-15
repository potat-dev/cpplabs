// Ориентированный граф задан и хранится списком смежности
// В файле задается вершина, с которой начинается обход.
// Выписать прямые (ребра дерева обхода bfs), обратные ребра
// и поперечные ребра (не связывают предков и потомков)

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>
#include <vector>

using namespace std;

// типы ребер: 0 - дерево, 1 - обратное, 2 - кросс
enum class EdgeType { TREE, BACK, CROSS };

class Graph {
 private:
  vector<vector<int>> adj;  // список смежности
  vector<int> depth;        // глубина вершины
  vector<int> parent;       // родитель вершины
  int root;                 // корень дерева обхода

  // список ребер {{начало, конец}: тип}
  map<pair<int, int>, EdgeType> edges;

 public:
  Graph(string filename) {  // конструктор
    ifstream fin(filename);
    if (!fin.is_open()) throw runtime_error("File not found");
    fin >> root;
    adj.resize(0);

    // Считываем список смежности
    while (!fin.eof()) {
      vector<int> row;
      int x;
      while (fin >> x) {
        if (x == -1) break;
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

    while (!q.empty()) {  // пока очередь не опустеет
      int v = q.front();  // извлекаем последнюю вершину
      q.pop();            // удаляем ее из очереди
      // просматриваем все вершины, смежные с текущей
      for (int i : adj[v]) {  // итерируемся по смежным вершинам
        // если ребро существует и вершина не посещена
        if (!visited[i]) {
          q.push(i);
          visited[i] = true;  // помечаем вершину как посещенную
          depth[i] = depth[v] + 1;  // увеличиваем глубину
          parent[i] = v;            // запоминаем родителя
          // добавляем ребро в список ребер
          edges.insert({{v, i}, EdgeType::TREE});
        } else {
          // если ребро существует и его тип не определен
          if (edges.find({v, i}) == edges.end()) {
            int a = v, b = i;
            // ищем общего предка
            while (depth[b] > depth[a]) b = parent[b];
            while (depth[a] > depth[b]) a = parent[a];
            // если общий предок найден
            if (a == b) {
              edges.insert({{v, i}, EdgeType::BACK});
            } else {
              edges.insert({{v, i}, EdgeType::CROSS});
            }
          }
        }
      }
    }
  }

  void printEdges() {
    for (auto [key, value] : edges) {
      int a = key.first, b = key.second;
      switch (value) {
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

  void exportGraphviz(string filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
      cout << "Error: failed to open file for writing" << endl;
      return;
    }
    fout << "digraph G {" << endl;
    for (auto [key, value] : edges) {
      int a = key.first, b = key.second;
      switch (value) {
        case EdgeType::TREE:
          fout << a << " -> " << b << " [color=green]" << endl;
          break;
        case EdgeType::BACK:
          fout << a << " -> " << b << " [color=red]" << endl;
          break;
        case EdgeType::CROSS:
          fout << a << " -> " << b << " [color=blue]" << endl;
          break;
      }
    }
    fout << "}";
  }
};

int main() {
  Graph g("graph.txt");
  g.getEdgesBFS();
  g.printEdges();
  g.exportGraphviz("graph.dot");
}
