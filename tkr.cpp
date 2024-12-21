include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Hàm BFS
void bfs(const unordered_map<int, vector<int>>& graph, int dinhdau) {
    unordered_set<int> visited;
    queue<int> q;

    visited.insert(dinhdau);
    q.push(dinhdau);

    cout << "BFS Traversal: ";

    // Duy?t BFS
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int neighbor : graph.at(vertex)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int>> graph;
    int sodinh, socanh;


    cout << "Nhap so luong dinh: ";
    cin >> sodinh;

    cout << "Nhap so luong canh: ";
    cin >> socanh;


    cout << "Nhap các canh (dinh dang: u v, trong dó u và v là các dinh):" << endl;
    for (int i = 0; i < socanh; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }

    int dinhdau;
    cout << "Nhap dinh bat dau: ";
    cin >> dinhdau;

    bfs(graph, dinhdau);

    return 0;
}
