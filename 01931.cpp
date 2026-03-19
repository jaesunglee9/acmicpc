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
comp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a.emplace_back(x, y);
  }
  sort(a.begin(), a.end(), comp);

  int fin = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first < fin) continue;
    cnt += 1;
    fin = a[i].second;
  }

  cout << cnt << '\n';
  return 0;
}


