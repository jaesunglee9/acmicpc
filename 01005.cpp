// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;


// based on kahn's algorithm
int
f(int n, int k, int w, const vector<int>& d,const vector<vector<int>>& g) {
  vector<int> in_degree(n+1, 0);
  for (int i = 1; i <= n; i++) {
    for (auto y : g[i]) {
      in_degree[y] += 1;
    }
  }

  vector<int> completion_time(n+1, 0);

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in_degree[i] == 0) {
      q.push(i);
      completion_time[i] = d[i];
    }
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : g[u]) {
      completion_time[v] = max(completion_time[v], completion_time[u] + d[v]);
      in_degree[v] -= 1;
      if (in_degree[v] == 0) {
        q.push(v);
      }
    }
  }
    
  return completion_time[w];
}
  
    


int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    
    vector<int> d(n+1, -INF); // d[0] is not used. For ease of indexing.
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
    }

    vector<vector<int>> g(n+1);  // reverse edge graph. index from 1 to n 
    for (int i = 0; i < k; i++) {
      int x, y; cin >> x >> y;
      g[x].push_back(y);
    }
    
    int w; cin >> w;

    cout << f(n, k, w, d, g) << '\n';
  }  
  
  return 0;
}


