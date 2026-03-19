#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;


// calculate bracket value
int
cb(stack<int>& s, char ch) {
  int ob;  // opening bracket
  if (ch == '0') ob = -1;
  if (ch == ')') ob = -2;
  if (ch == ']') ob = -3;

  int sum = 0;
  while (!s.empty()) {
    int n = s.top(); s.pop();
    if (n == ob) break;  // done
    if (n == 0) return 0;  // invalid sequence
    if (n < 0 && n != ob) return 0;  // unmatched brackets

    sum += n;
  }
  if (ob == -1) return sum;
  int c;  // coefficient
  if (ob == -2) c = 2;
  if (ob == -3) c = 3;
  if (sum == 0) return c;
  return sum * c;
}


void
solve(const string& str) {
  stack<int> s; s.push(-1);
  for (const char& ch: str) {
    if (ch == ']' || ch == ')') {
      s.push(cb(s, ch));
    }
    else if (ch == '(') s.push(-2);
    else if (ch == '[') s.push(-3);
    else{
      cout << 0 << '\n';
      return;
    }
  }

  cout << cb(s, '0') << '\n';
}


int
main() {
  string input; cin >> input;

  solve(input);

  return 0;
}
