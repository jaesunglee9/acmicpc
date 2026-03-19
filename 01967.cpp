#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 5; // Max nodes + buffer
vector<pair<int, int>> adj[MAXN]; // Adjacency list: adj[u] = { {v1, w1}, {v2, w2}, ... }
int dist[MAXN];             // Distance array for BFS
int n;

// Performs BFS starting from 'start_node'
// Finds the node farthest away and returns {farthest_node_id, distance}
pair<int, int> bfs(int start_node) {
    fill(dist, dist + n + 1, -1); // Initialize distances to -1 (unvisited)
    queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Update farthest node found so far
        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] == -1) { // If node v hasn't been visited
                dist[v] = dist[u] + weight;
                q.push(v);
            }
        }
    }
    return {farthest_node, max_dist};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // Need to build an undirected adjacency list for BFS/DFS traversal
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Input might be parent/child, but we need general neighbors
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Add edge in both directions
    }

     if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    // Pass 1: Find the farthest node from node 1 (arbitrary start)
    pair<int, int> result1 = bfs(1);
    int farthest_node_from_1 = result1.first;

    // Pass 2: Find the farthest node from the result of Pass 1
    pair<int, int> result2 = bfs(farthest_node_from_1);
    int diameter = result2.second; // The distance is the diameter

    cout << diameter << '\n';

    return 0;
}
