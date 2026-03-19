// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 1e9 + 7;

float avg(vector<int>& a) {
  int l = a.size();
  float count = 0;
  for (auto& ele: a) {
    count += ele;
  }

  return count / float(l);
}
  

int f(vector<int>& a, float ratio) {
  int l = a.size();
  int m = round(ratio * l / 2);
  if (2 * m >= l) return 0;

  sort(a.begin(), a.end());
  vector<int> b(a.begin() + m, a.end() - m);

  return round(avg(b));
}
  

int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << f(a, 0.3) << '\n';
  
  
  return 0;
}


