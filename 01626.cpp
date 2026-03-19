#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

struct DS {
    int n;

    vector<int> root, size;

    DS(int n) : n(n), root(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int
    find(int x) {
        while (x != root[x]) {
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }

    bool
    disjoint(int a, int b) {
        return find(a) != find(b);
    }

    void
    merge(int a, int b) {
        if (!disjoint(a, b)) return;

        int ra = find(a), rb = find(b);
        if (size[ra] < size[rb]) swap(ra, rb);
        root[rb] = ra;
        size[ra] += size[rb];
    }
};

struct Edge {
    int u, v, w, id;
    bool in_mst = false;
};

struct WG {
    int n_v, n_e;
    vector<Edge> edges;

    WG(int n_v, int n_e) : n_v(n_v), n_e(n_e) {
        edges.reserve(n_e);
    }

    void
    add_edge(int a, int b, int c, int id) {
        a--; b--;
        edges.push_back({a, b, c, id, false});  // Last is for checking membership in mst
    }

    void
    sort_edges() {
        sort(edges.begin(), edges.end(), [](const Edge& a,const Edge& b) {
            return a.w < b.w;
        });
    }

    int
    build_mst() {
        sort_edges();
        DS ds(n_v);
        ll total = 0;
        int used = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            int u, v;
            u = edges[i][0];
            v = edges[i][1];
            if 
        }

    }
};


int
main(void) {
    ios::sync_with_stdio(0);cin.tie(0);
    int v, e; cin >> v >> e;
    WG g(v, e);
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }



}

