// graph edge classification in bfs
// breadth first edge classification

// example graph represented as an adjacency list:
// 0: 1 4 7
// 1: 2
// 2: 3
// 3: 1
// 4: 5
// 5: 2 5 7
// 6: -
// 7: -

// start vertex: 0

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

  // breadth first edge classification
  void bfs(int start) {
    // initialize
    vector<int> color(adj.size(), 0);
    vector<int> parent(adj.size(), -1);
    vector<int> distance(adj.size(), -1);
    queue<int> q;
    // start vertex
    color[start] = 1;
    distance[start] = 0;
    q.push(start);
    // until queue is empty
    while (!q.empty()) {
      // get vertex
      int u = q.front();
      q.pop();
      // for each neighbor
      for (int v : adj[u]) {
        // if not visited
        if (color[v] == 0) {
          // mark as visited
          color[v] = 1;
          // set parent
          parent[v] = u;
          // set distance
          distance[v] = distance[u] + 1;
          // add to queue
          q.push(v);
          // print edge
          cout << u << " -> " << v << ": tree edge" << endl;
        } else {
          // if parent
          if (parent[u] == v) {
            // print edge
            cout << u << " -> " << v << ": back edge" << endl;
          } else {
            // if distance
            if (distance[u] < distance[v]) {
              // print edge
              cout << u << " -> " << v << ": forward edge" << endl;
            } else {
              // print edge
              cout << u << " -> " << v << ": cross edge" << endl;
            }
          }
        }
      }
      // mark as visited
      color[u] = 2;
    }
  }
};

int main() {
  Graph g("D:\\Projects\\SUAI-Labs\\Semester_3\\Lab_20\\graph.txt");
  cout << endl << "example graph:" << endl;
  g.print();
  cout << endl << "edge classification:" << endl;
  g.bfs(0);
  return 0;
}