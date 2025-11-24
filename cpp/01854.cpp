#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
const int INF = int(1e9 + 7);


vector<priority_queue<int>>
kth_dijkstra(const vector<vector<pair<int, int>>>& al, int n, int k, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<priority_queue<int>> d(n);
    
    d[s].push(0);
    pq.push({0, s});

    while (!pq.empty()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d[u].size() == k && du > d[u].top()) continue;

        for (auto [v, w] : al[u]) {
            int t = du + w;

            if (d[v].size() < (size_t)k) {
                d[v].push(t);
                pq.push({t, v});
            } else if (d[v].top() > t) {
                d[v].pop();
                d[v].push(t);
                pq.push({t, v});
            }
        }
    }

    return d;
}


int
main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> al(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        al[a-1].push_back({b-1, c});
    } 

    auto res = kth_dijkstra(al, n, k, 0);

    for (int i = 0; i < n; i++) {
        if (res[i].size() < k) {
            cout << -1;
        }
        else {
            cout << res[i].top();
        }
        cout << '\n';
    }

    return 0;
}