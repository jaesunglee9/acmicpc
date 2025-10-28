#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

struct DS {
    int
    n;

    vector<int>
    root, size;
    
    vector<ll> weight;  // weight[i] is relative weight of compared to its parent

    DS(int n) : n(n), root(n), size(n, 1), weight(n) {
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int
    find(int x) {
        // returns the root index, 
        while (x != root[x]) {
            weight[x] = weight[root[x]] + weight[x];
            root[x] = root[root[x]];

            x = root[x];
        }
        return x;
    }


    ll
    rw(int x) {
        ll
        res = 0;
        
        while (x != root[x]) {
            res += weight[x];
            x = root[x];
        }
        return res;
    }


    bool 
    disjoint(int a, int b) {
        return find(a) != find(b);
    }

    int
    comp(int a, int b, int w) {
        int ra = find(a), rb = find(b);
        if (a == b) return 1;
        if (w < 0 || w > 1000000) return 2;

        ll tmp = rw(b) - rw(a) - w;

        if (tmp > 0) {
            // root of b will be new root of a
            weight[find(a)] = tmp;
            root[ra] = rb;
        }
        else {
            weight[find(b)] = -tmp;
            root[rb] = ra;
        }

        return 0;
    }

    ll
    ask(int a, int b) {
        return rw(b) - rw(a);
    }
};

int
main(void) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) { break; }
        DS ds(n);
        char ch;
        int a, b, w;
        for (int i = 0; i < m; i++) {
            cin >> ch;
            if (ch == '!') {
                cin >> a >> b >> w;
                a--; b--;
                ds.comp(a, b, w);
            }
            else if (ch == '?') {
                cin >> a >> b;
                a--; b--;
                if (ds.disjoint(a, b)) {
                    cout << "UNKNOWN\n";
                }
                else {
                    cout << ds.ask(a, b) << '\n';
                }
            }
        }
    }
    return 0;
}




