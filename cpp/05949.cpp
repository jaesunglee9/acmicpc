#include <iostream>
#include <string>

using namespace std;

int
main(void) {
  int n; cin >> n;

  string str = "";

  int cnt = 0;

  while (n) {
    if (cnt == 3) {
      str = "," + str;
      cnt = 0;
    }
    else {
      str = to_string(n % 10) + str;
      n /= 10;
      cnt++;
    }
  }

  cout << str << '\n';
  return 0;
}
  
