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

  int* ms = new int[n+1]();
  for (int i = 2; i < n+1; i++)
    {
      ms[i] = ms[i-1] + 1;
      if (i % 2 == 0)
	{
	  ms[i] = (ms[i] < ms[i / 2] + 1 ? ms[i] : ms[i/2] + 1);
	}
      if (i % 3 == 0)
	{
	  ms[i] = (ms[i] < ms[i / 3] + 1 ? ms[i] : ms[i/3] + 1);
	}
    }
  
  cout << ms[n];
    
  return 0;
}


