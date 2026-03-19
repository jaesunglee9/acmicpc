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

  int n;
  cin >> n;

  long fib[41] = {0};

  fib[1] = 1;
  for (int i = 2; i < 41; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  int m;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m == 0) {
      cout << 1 << ' ' << 0 << '\n';
    } else {
      cout << fib[m-1] << ' ' << fib[m] << '\n';
    }
  }

  return 0;
}


