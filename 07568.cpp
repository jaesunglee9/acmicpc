// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

int
f(const vector<vector<int>>& a, int n) {
  int sum = 0;
  for (const auto& p : a) {
    if (a[n][0] < p[0] && a[n][1] < p[1]) sum += 1;
  }

  return sum + 1;
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

  for (int i = 0; i < n; i++) {
    cout << f(a, i) << " ";
  }
  cout << endl;
  return 0;
}


