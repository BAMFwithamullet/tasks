#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using Pair = std::pair<int, int>; 
class GraphListVector {
    int V;
    std::vector<std::vector<Pair>> adj; 

public:
    GraphListVector(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight, bool directed = false) {
        adj[u].push_back({ v, weight });
        if (!directed) {
            adj[v].push_back({ u, weight });
        }
    }

    const std::vector<Pair>& getNeighbors(int v) const {
        return adj[v];
    }

    int getVertexCount() const {
        return V;
    }
};

std::vector<int> dijkstra(const GraphListVector& graph, int start) {
    int n = graph.getVertexCount();
    std::vector<int> dist(n, INT_MAX);
    std::vector<bool> visited(n, false);

    dist[start] = 0;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& [v, w] : graph.getNeighbors(u)) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    int N, S, F;
    std::cin >> N >> S >> F;
    S--;
    F--;

    GraphListVector graph(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int weight;
            std::cin >> weight;

            if (weight != -1 && i != j) {
                graph.addEdge(i, j, weight, true); 
            }
        }
    }

    std::vector<int> dist = dijkstra(graph, S);

    if (dist[F] == INT_MAX) {
        std::cout << -1 << '\n';
    }
    else {
        std::cout << dist[F] << '\n';
    }

    return 0;
}
