// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

void
mark(vector<vector<int>>& a,const pair<int,int>& u) {
  a[u.first][u.second] = 1;
}
    
vector<pair<int,int>>
adj(vector<vector<int>>& a,const pair<int,int>& u) {
  vector<pair<int, int>> res;
  int n = a.size();
  int m = a[0].size();
  int x = u.first;
  int y = u.second;

  for (auto& xadj : {x-1, x+1}) {
    if (0 <= xadj && xadj <= n-1 && a[xadj][y] == 0) {
      res.emplace_back(xadj, y);
    }
  }

  for (auto& yadj : {y - 1, y+1}) {
    if (0 <= yadj && yadj <= m-1 && a[x][yadj] == 0) {
      res.emplace_back(x, yadj);
    }
  }

  return res;
}

struct
pair_hash {
  int
  operator()(const pair<int, int>& x) const {
    return x.first ^ x.second;
  }
};

           


int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n; cin >> m >> n;
  vector<vector<int>> a(n, vector<int>(m));
  unordered_set<pair<int,int>, pair_hash> currs;
  unordered_set<pair<int,int>, pair_hash> nexts;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) nexts.insert({i, j});
    }
  }

  int day = 0;
  while (!nexts.empty()) {
    currs = nexts;
    nexts.clear();
    for (auto& ele : currs) {
      mark(a, ele);
      auto viable_adj = adj(a, ele);
      for (auto& v : viable_adj) {
        mark(a, ele);
        nexts.insert(v);
      }
    }
    day += 1;
  }
  
  for (auto& row : a)
    for (auto cell : row)
      if (cell == 0) {
        cout << -1 << '\n';
        return 0;
      }
  
  cout << day-1 << '\n';
  
  return 0;
}


