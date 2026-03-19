#include <iostream>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int a, b, c, d, p;
  cin >> a >> b >> c >> d >> p;

  int x = a * p;
  int y;
  if (p <= c) {
    y = b;
  }
  else {
    y = b + (p - c) * d;
  }

  cout << (x > y ? y : x) << '\n';

  return 0;
}
