#include <iostream>
#include <algorithm>


using namespace std;

int
main(void) {
  int l, a, b, c, d;
  cin >> l >> a >> b >> c >> d;

  int t1 = a / c;
  if (a % c != 0) {
    t1 += 1;
  }

  int t2 = b / d;
  if (b % d != 0) {
    t2 += 1;

  }

  cout << l - max(t1, t2) << '\n';

  return 0;

}
