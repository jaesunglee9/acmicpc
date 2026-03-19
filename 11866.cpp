// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    dq.push_back(i + 1);
  }

  vector<int> a;
  while (!dq.empty()) {
    int l = dq.size();
    int idx = k % l;
    int n2pop = l - idx;
    for (int i = 0; i < n2pop; i++) {
      dq.push_front(dq.back()); dq.pop_back();
    }
    a.push_back(dq.back()); dq.pop_back();
  }
  
  cout << '<';
  for (int i = 0; i < n-1; i++) {
    cout << a[i] << ", ";
  }
  cout << a[n-1] << ">" << '\n';
  
  return 0;
}


