#include <iostream>
#include <iomanip>

using namespace std;
const float pi = 3.1415927;

int
main(void) {
  ios::sync_with_stdio(false);cin.tie(0);

  std::cout << std::fixed << std::setprecision(2);

  for (int i = 1; ; i++) {
    float d, s;
    int r;
    cin >> d >> r >> s;
    if (r == 0) break;

    float c = pi * d;
    float dInch = c * r;
    float dMile = dInch / (12 * 5280);
    float mph = dMile / s * 3600;

    cout << "Trip #" << i << ": " << dMile << " " << mph << '\n';
  }

  return 0;
}
