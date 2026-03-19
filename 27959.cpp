#include <iostream>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false);cin.tie(0);

  int n, m; cin >> n >> m;

  if (100 * n - m >= 0) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }

  return 0;
}
