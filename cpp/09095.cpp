// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int
f(int n)
{
  if (n == 3)
    {
      return 4;
    }
  if (n == 2)
    {
      return 2;
    }
  if (n == 1)
    {
      return 1;
    }
  return f(n-3) + f(n-2) + f(n-1);
}

int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0;i < n; i++)
    {
      int m;
      cin >> m;
      cout << f(m) << endl;
    }

  return 0;
}


