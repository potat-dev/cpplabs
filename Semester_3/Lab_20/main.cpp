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
  vector<vector<int>> adj;

 public:
  // load from file
  Graph(const string &filename) {
    ifstream fin(filename);
    // until the end of file
    while (!fin.eof()) {
      vector<int> row;
      int n;
      // read vector
      while (fin >> n) {
        row.push_back(n);
        // if the end of line
        if (fin.peek() == '\n') {
          break;
        }
      }
      // add vector to matrix
      adj.push_back(row);
    }
  }

  // print graph
  void print() {
    for (int i = 0; i < adj.size(); i++) {
      cout << i << ": ";
      for (int j = 0; j < adj[i].size(); j++) {
        cout << adj[i][j] << " ";
      }
      cout << endl;
    }
  }

  // bfs
  void bfs(int start) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(start);
    visited[start] = true;
    // until queue is empty
    while (!q.empty()) {
      int v = q.front();  // get first
      q.pop();
      // for each neighbour
      for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u]) {  // if not visited!
          q.push(u);
          visited[u] = true;
          cout << v << " -> " << u << endl;
        }
      }
    }
  }
};

int main() {
  Graph g("graph.txt");
  g.print();
  cout << endl;
  g.bfs(0);
  return 0;
}