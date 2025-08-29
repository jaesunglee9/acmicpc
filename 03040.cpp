#include <iostream>
#include <vector>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  int total = 0;
  vector<int> d(9);
  for (int i = 0; i < 9; i++) {
    cin >> d[i];
    total += d[i];
  }

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (total - d[i] - d[j] == 100) {
        for (int k = 0; k < 9; k++) {
          if (k == i || k == j) continue;
          cout << d[k] << '\n';
        }
        return 0;
      }
    }
  }
      

  return 0;
}
