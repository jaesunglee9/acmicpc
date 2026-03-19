// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int INF = 1e9 + 7;

char
match(char ch) {
  if (ch == ')') return '(';
  if (ch == ']') return '[';
  return '0';
}

int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  while (getline(cin, str) && str != ".") {
    stack<int> s;
    bool isbal = true;
    for (const char& ch: str) {
      if (ch == '(' || ch == '[') s.push(ch);
      if (ch == ')' || ch == ']') {
        if (s.empty() || s.top() != match(ch)) {
          isbal = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) isbal = false;

    cout << (isbal ? "yes" : "no" ) << '\n';

  }
        
      
  return 0;
}


