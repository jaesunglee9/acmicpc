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

  int x;
  cin >> x;

  int rem = x % 3;
  if (rem == 0) {
    cout << 'S';
  } else if (rem == 1) {
    cout << 'U';
  } else if (rem == 2) {
    cout << 'O';
  }
  
  return 0;
}


