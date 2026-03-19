#include <iostream>
#include <string>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string str; cin >> str;
    int h = str.size() / 2;  //
    if (str[h - 1] == str[h]) {
      cout << "Do-it\n";
    }
    else {
      cout << "Do-it-Not\n";
    }
  }
  
  return 0;
}
