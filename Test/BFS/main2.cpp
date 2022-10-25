// graph edge classification in bfs

// the classification pseudocode:
// 1. check for membership in the tree (tree edge)
// 2. check for head's interval contains tail's (back edge)
// 3. check for tail's interval contains head's (forward edge)
// 4. otherwise, declare a cross edge.

// example graph represented as an adjacency list:
// 0: 1 4 7
// 1: 2
// 2: 3
// 3: 1
// 4: 5
// 5: 2 5 7
// 6: -
// 7: -

// edge classification:
// 0 -> 1: tree edge
// 0 -> 4: tree edge
// 0 -> 7: forward edge
// 1 -> 2: tree edge
// 2 -> 3: tree edge
// 3 -> 1: back edge
// 4 -> 5: tree edge
// 5 -> 2: cross edge
// 5 -> 6: tree edge
// 5 -> 7: tree edge

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
      row.resize(0);
      int n;
      // read vector
      while (fin >> n) {
        if (n == -1) break;
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

  // bfs edge classification
  void bfs(int start) {
    // initialize
    vector<int> color(adj.size(), 0);
    vector<int> d(adj.size(), 0);
    vector<int> p(adj.size(), -1);
    vector<int> f(adj.size(), 0);
    int time = 0;
    // queue
    queue<int> q;
    // start
    q.push(start);
    color[start] = 1;
    d[start] = time++;
    // until queue is empty
    while (!q.empty()) {
      // get head
      int u = q.front();
      q.pop();
      // for each neighbor
      for (int v : adj[u]) {
        // if not visited
        if (color[v] == 0) {
          // visit
          color[v] = 1;
          d[v] = time++;
          p[v] = u;
          // add to queue
          q.push(v);
        }
      }
      // finish
      color[u] = 2;
      f[u] = time++;
    }
    // print
    for (int i = 0; i < adj.size(); i++) {
      cout << i << ": " << d[i] << " " << f[i] << endl;
    }
    // edge classification
    for (int i = 0; i < adj.size(); i++) {
      for (int j : adj[i]) {
        // tree edge
        if (p[j] == i) {
          cout << i << " -> " << j << ": tree edge" << endl;
        }
        // back edge
        // head's interval contains tail's
        else if (d[i] < d[j] && d[j] < f[j] && f[j] < f[i]) {
          cout << i << " -> " << j << ": back edge" << endl;
        }
        // forward edge
        // tail's interval contains head's
        else if (d[j] < d[i] && d[i] < f[i] && f[i] < f[j]) {
          cout << i << " -> " << j << ": forward edge" << endl;
        }
        // cross edge
        else {
          cout << i << " -> " << j << ": cross edge" << endl;
        }
      }
    }
  }
};

int main() {
  Graph g("D:\\Projects\\SUAI-Labs\\Semester_3\\Lab_20\\graph.txt");
  g.print();
  g.bfs(0);
  return 0;
}