#include <iostream>

using namespace std;

int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  int balance, amount;
  char transaction;

  while (1) {
    cin >> balance >> transaction >> amount;
    if (balance == 0 && transaction == 'W' && amount == 0) break;

    if (transaction == 'D') {
      cout << balance + amount << '\n';
    }
    else {
      int res = balance - amount;
      if (res < -200) {
        cout << "Not allowed\n";
      }
      else {
        cout << res << '\n';
      }
    }
  }


  return 0;
}
