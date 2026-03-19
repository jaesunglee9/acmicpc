#include <iostream>
#include <string>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  string str; cin >> str;

  bool isR = false;
  int l = 0;
  int r = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '@') {
      if (isR) r++;
      else l++;
    }

    if (str[i] == '(') {
      while (str[i] != ')') i++;
      isR = true;
    }
  }

  cout << l << ' ' << r << '\n';

  return 0;
}
