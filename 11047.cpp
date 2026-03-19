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
  cin >> n >> m;
  int* coins = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  int count = 0;
  for (int i = n - 1; i >= 0; i--){
    int coin = coins[i];
    if (m >= coin) {
      count += m / coin;
      m %= coin;
    }
  }
  cout << count<< '\n';
  return 0;
}


