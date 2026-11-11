#include <iostream>
#include <vector>

void dfsRec(int v, int parent, std::vector<bool>& visited, std::vector<std::vector<int>>& adj, bool& hascycle) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsRec(neighbor, v, visited, adj, hascycle);
        }
        else if (neighbor != parent) hascycle = true;
    }
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    std::vector<bool> visited(n, false);
    bool hascycle = false;
    dfsRec(0, 0, visited, adj, hascycle);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            std::cout << "NO";
            return 0;
        }
    }

    if (hascycle) {
        std::cout << "NO";
        return 0;
    }

    std::cout << "YES";
    return 0;
}
