// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

const int INF = 1e9 + 7;


int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<int> s;
  int k; cin >> k;
  for (int i = 0; i < k; i++) {
    int n; cin >> n;
    if (n == 0) s.pop();
    else s.push(n);
  }
  int sum = 0;
  while (!s.empty()) {
    sum += s.top();
    s.pop();
  }
    

  cout << sum << '\n';
  return 0;
}


