#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V; // 頂點數量
    vector<vector<int>> adj; // 鄰接表 (Adjacency List)
    // 輔助遞迴函式
    void dfs(int v, vector<bool>& visited, stack<int>& s) {
        visited[v] = true;
        // 遞迴拜訪所有鄰居
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, s);
            }
        }
        // 關鍵點：該節點及其所有後代都處理完後，才把它丟進 Stack
        s.push(v);
    }

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void topologicalSort() {
        stack<int> s;
        vector<bool> visited(V, false);
        // 對所有節點執行 DFS
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, visited, s);
            }
        }
        // 印出結果：從 Stack pop 出來
        cout << "拓撲排序結果為: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    // 建立一個有 6 個節點的 DAG
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
