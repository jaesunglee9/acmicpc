#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = (int) 1e9 + 7;

// can CFG be used for Floyd Warshall algorithm?

void
sol0(int n, vector<vector<int>>& am)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || i == k || k == j) continue;

                am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
            }
        }
    }

    int mnkb = INF;
    int mnkbi;
    for (int i = n; i >= 1; i--)
    {
        int kb = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            kb += am[i][j];
        }
        if (kb <= mnkb) { 
            mnkb = kb;
            mnkbi = i;
        }
    }

    cout << mnkbi << '\n';

    return;
}

// bfs solution

int
main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> am(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        am[u][v] = 1;
        am[v][u] = 1;
    }

    sol0(n, am);

    return 0;
}