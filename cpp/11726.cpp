// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main ()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int* res = new int[1001];
  res[2] = 2;
  res[1] = 1;
  for ( int i = 3; i < 1001 ; i++) {
    res[i] = (res[i-1] + res[i-2]) % 10007;
  }
  
  cout << res[n] << '\n';
  return 0;
}


