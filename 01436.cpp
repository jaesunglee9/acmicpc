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

  int i = 0;
  int l = 0;
  while (i < n) {
    string sl = to_string(l);
    if (sl.find("666") != string::npos) {
      i += 1;
    }

    ++l;
  }
  cout << l - 1;

  return 0;
}


