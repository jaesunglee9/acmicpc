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

  int* nums = new int[n];
  for(int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
  int* sum = new int[n+1];
  sum[0] = 0;
  for (int i = 0; i < n; i++)
    {
      sum[i+1] = sum[i] + nums[i];
    }
  for (int i = 0; i < m; i++)
    {
      int s, f;
      cin >> s >> f;
      cout << sum[f] - sum[s -1] << '\n';
    }
	

  return 0;
}


