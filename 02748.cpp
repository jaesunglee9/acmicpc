#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> FIB(100);

void
fill_fib() {
  FIB[0] = 0;
  FIB[1] = 1;
  for (int i = 2; i < 100; i++) {
    FIB[i] = FIB[i-1] + FIB[i-2];
  }
}

int
main() {
  ios::sync_with_stdio(false);cin.tie(0);

  fill_fib();

  int n; cin >> n;

  cout << FIB[n] << '\n';
  

  return 0;
}
