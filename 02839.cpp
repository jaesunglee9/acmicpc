// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
using namespace std;

const int INF = 1e9 + 7;


int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int m = n / 5;
  for (int i = m; i >= 0; i--) {
    int l = n - 5 * i;
    if ((l % 3) == 0) {
      cout << i + l / 3 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}


