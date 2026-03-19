// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

bool
comp(const vector<int>& a,const vector<int>& b) {
  if (a[1] == b[1]) {
    return a[0] < b[0];
  } else {
    return a[1] < b[1];
  }
}

int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> a;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a.push_back({x, y});
  }

  sort(a.begin(), a.end(), comp);
  for (const auto& p: a) {
    cout << p[0] << " " << p[1] << '\n';
  }
             
  
  return 0;
}


