#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

void
run(vector<string>& pgm, stack<int>& s) {
  bool okay = true;
  for (string& str : pgm) {
    auto cmd = str.substr(0, 3);
    if (cmd == "NUM") {
      int x = stoi(str.substr(4));
      s.push(x);
    }
    if (cmd == "POP") {
      if (s.empty()) {
        okay = false;
        break;
      }
      
      s.pop();
    }
    if (cmd == "INV") {
      if (s.empty()) {
        okay = false;
        break;
      }
      
      int n = s.top(); s.pop();
      s.push(-n);
    }
    if (cmd == "DUP") {
      if (s.empty()) {
        okay = false;
        break;
      }
      
      int n = s.top();
      s.push(n);
    }
    if (cmd == "SWP") {
      if (s.size() < 2) {
        okay = false;
        break;
      }
      
      int n1 = s.top(); s.pop();
      int n2 = s.top(); s.pop();
      s.push(n1);
      s.push(n2);
    }
    if (cmd == "ADD") {
      if (s.size() < 2) {
        okay = false;
        break;
      }
      
      int n1 = s.top(); s.pop();
      int n2 = s.top(); s.pop();
      int res = n1 + n2;
      if (abs(res) > 1e9) {
        okay = false;
        break;
      }
      
      s.push(res);
    }
    if (cmd == "SUB") {
      if (s.size() < 2) {
        cout << "ERROR";
        return;
      }
      int n1 = s.top(); s.pop();
      int n2 = s.top(); s.pop();
      int res = n2 - n1;
      if (abs(res) > 1e9) {
        cout << "ERROR";
        return;
      }
      s.push(res);
    }

    if (cmd == "MUL") {
      if (s.size() < 2) {
        okay = false;
        break;
      }
      
      long long n1 = s.top(); s.pop();
      long long n2 = s.top(); s.pop();
      long long res = n1 * n2;
      if (llabs(res) > 1e9) {
        okay = false;
        break;
      }
      s.push(int(res));
    }
    if (cmd == "DIV") {
      if (s.size() < 2) {
        okay = false;
        break;
      }
      
      int n1 = s.top(); s.pop();
      int n2 = s.top(); s.pop();
      if (n1 == 0) {
        okay = false;
        break;
      }
      int res = n2 / n1;
      if (abs(res) > 1e9) {
        okay = false;
        break;
      }
      s.push(res);
    }
    if (cmd == "MOD") {
      if (s.size() < 2) {
        okay = false;
        break;
      }
      
      int n1 = s.top(); s.pop();
      int n2 = s.top(); s.pop();
      if (n1 == 0) {
        okay = false;
        break;
      }
      int res = n2 % n1;
      if (abs(res) > 1e9) {
        okay = false;
        break;
      }
      s.push(res);
    }
  }

  if (!okay || s.size() != 1) {
    cout << "ERROR";
    return;
  }
  else {
    cout << s.top();
    return;
  }

}


int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  
  string line;
  while (getline(cin, line) && line != "QUIT") {
    vector<string> pgm;
    pgm.push_back(line);
    // getting program
    while (getline(cin, line) && line != "END") {
      pgm.push_back(line);
    }

    int n; cin >> n; cin.ignore();

    // running program for n times
    for (int i = 0; i < n; i++) {
      int v; cin >> v;
      stack<int> s;
      s.push(v);
      run(pgm, s);
    }
    cout << endl;
  }

  return 0;
}
