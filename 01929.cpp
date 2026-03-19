// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;



int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n; cin >> m >> n;

  
  vector<bool> p(n+1, true);
  p[0] = p[1] = false;
  
  for (int i = 2; i * i <= n; i++) {
    if (p[i] == true) {
      for (int j = i*i; j <= n; j+=i) {
        p[j] = false;
      }
    }
  }

  for (int i = m; i <= n; i++){
    if (p[i]) {
      cout << i << '\n';
    }
  }
      
    
  
  return 0;
}


