// Ориентированный граф задан и хранится матрицей смежности.
// В файле задается вершина, с которой начинается обход.

// Построить дерево обхода с помощью bfs.
// После того, как известно дерево обхода, необходимо определить типы ребер
// направленного графа.

// Ребра древа обхода - это ребра, которые входят в дерево обхода.
// Прямые ребра - это ребра, которые ведут из родительской вершины в дочернюю.
// Обратные ребра - ребра, ведущие от потомка к предку.
// Поперечные ребра - ребра, не связывающие предков и потомков.

// Вывести на экран типы ребер.

// As you already established, seeing a node for the first time creates a tree edge. The problem with BFS instead of DFS, as David Eisenstat said before me, is that back edges cannot be distinguished from cross ones just based on traversal order.
// Instead, you need to do a bit of extra work to distinguish them. The key, as you'll see, is to use the definition of a cross edge.
// The simplest (but memory-intensive) way is to associate every node with the set of its predecessors. This can be done trivially when you visit nodes. When finding a non-tree edge between nodes a and b, consider their predecessor sets. If one is a proper subset of the other, then you have a back edge. Otherwise, it's a cross edge. This comes directly from the definition of a cross edge: it's an edge between nodes where neither is the ancestor nor the descendant of the other on the tree.
// A better way is to associate only a "depth" number with each node instead of a set. Again, this is readily done as you visit nodes. Now when you find a non-tree edge between a and b, start from the deeper of the two nodes and follow the tree edges backwards until you go back to the same depth as the other. So for example suppose a was deeper. Then you repeatedly compute a=parent(a) until depth(a)=depth(b).
// If at this point a=b then you can classify the edge as a back edge because, as per the definition, one of the nodes is an ancestor of the other on the tree. Otherwise you can classify it as a cross edge because we know that neither node is an ancestor or descendant of the other.

// pseudocode:

//   foreach edge(a,b) in BFS order:
//     if !b.known then:
//       b.known = true
//       b.depth = a.depth+1
//       edge type is TREE
//       continue to next edge
//     while (b.depth > a.depth): b=parent(b)
//     while (a.depth > b.depth): a=parent(a)
//     if a==b then:
//       edge type is BACK
//     else:
//       edge type is CROSS

#include <fstream>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

using namespace std;

class Graph {
 private:
  // Матрица смежности
  vector<vector<int>> adj;
  // Номер вершины, с которой начинается обход
  int root;
  // глубина вершины
  vector<int> depth;
  // родитель вершины
  vector<int> parent;

  // список ребер
  // (начало, конец, тип)
  // типы ребер:
  // 0 - дерево
  // 1 - обратное
  // 2 - кросс
  vector<vector<int>> edges;

 public:
  // Конструктор
  Graph(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
      throw runtime_error("File not found");
    }
    fin >> root;
    // Инициализируем матрицу смежности
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

  // Обход в ширину
  void bfs() {
    // Очередь для хранения вершин
    queue<int> q;
    // Вектор для хранения информации о посещении вершины
    vector<bool> visited(adj.size(), false);
    // Начинаем с корня
    q.push(root);
    visited[root] = true;
    depth[root] = 0;
    parent[root] = -1;
    // Пока очередь не пуста
    while (!q.empty()) {
      // Извлекаем вершину
      int v = q.front();
      q.pop();
      // Просматриваем все вершины, смежные с v
      for (int i = 0; i < adj[v].size(); i++) {
        // Если есть ребро и вершина еще не посещена
        if (adj[v][i] == 1 && !visited[i]) {
          // Добавляем ее в очередь
          q.push(i);
          visited[i] = true;
          depth[i] = depth[v] + 1;
          parent[i] = v;
          // Выводим ребро
          cout << v << " " << i << " TREE" << endl;
        }
      }
    }
  }

  void printEdgeTypes() {
    for (int i = 0; i < adj.size(); i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j] == 1) {
          // copy of i and j
          int a = i;
          int b = j;
          // while (b.depth > a.depth): b=parent(b)
          while (depth[b] > depth[a]) {
            b = parent[b];
          }
          // while (a.depth > b.depth): a=parent(a)
          while (depth[a] > depth[b]) {
            a = parent[a];
          }
          // if a==b then:
          //   edge type is BACK
          if (a == b) {
            cout << i << " " << j << " BACK" << endl;
          } else {
            //   edge type is CROSS
            cout << i << " " << j << " CROSS" << endl;
          }
        }
      }
    }
  }
};

int main() {
  // cout << "test" << endl;
  Graph g("D:/Projects/SUAI-Labs/Semester_3/Lab_20/graph.txt");
  // cout << "test" << endl;
  g.bfs();
  g.printEdgeTypes();
  // cout << "test" << endl;
  
  return 0;
}
