// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n;
  cin >> m;
  
  vector<vector<int>> g(n+1);
  queue<int> q;
  vector<bool> visited(n+1, false);

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int count = 0;
  q.push(1);
  visited[1] = true;
  while (!q.empty())
    {
    int node = q.front();
    q.pop();
    count += 1;
    for (auto& adj : g[node])
      {
	if (visited[adj] == false)
	  {
	    visited[adj] = true;
	    q.push(adj);
	  }
      }
    }

  cout << count - 1;
  return 0;
}


