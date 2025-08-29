// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;


int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 1) { cout << a[0] << '\n'; return 0; }
  if (n == 2) { cout << a[0] + a[1] << '\n'; return 0; }
        

  vector<vector<int>> dp(n, vector<int>(2, -1));
  dp[0][0] = a[0];
  dp[1][0] = a[1];
  dp[1][1] = dp[0][0] + a[1];
  
  for (int i = 2; i < n; i++) {
    dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + a[i];
    dp[i][1] = dp[i-1][0] + a[i];
  }

  cout << max(dp[n-1][0], dp[n-1][1]) << '\n';

  return 0;
}


