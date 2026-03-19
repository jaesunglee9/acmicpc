#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
typedef long long ll;

int n, k;

vector<string> wl;

int mnr = 0;
bool al[26] = {false};

int
f() {
  if (k < 0) return 0;
  int cnt = 0;
  for (auto& w : wl) {
    bool able = true;
    for (auto& ch : w) {
      if (al[ch - 'a'] == false) {
        able = false;
        break;
      }
    }
    if (able) cnt++;
  }
  return cnt;
}


void
dfs(int idx, int depth) {
  if (depth == k) {
    int nr = f();
    mnr = (mnr < nr ? nr : mnr);
    return;
  }

  for (int i = idx; i < 26; i++) {
    if (al[i] == true) continue;

    al[i] = true;
    dfs(i+1, depth+1);
    al[i] = false;
  }
}

int
main() {
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string str; cin >> str;
    str = str.substr(4);
    for (int j = 0; j < 4; j++) {
      str.pop_back();
    }
    wl.push_back(str);
  }

  al['a' - 'a'] = al['c' - 'a'] = al['i'-'a'] = al['n'-'a'] = al['t'-'a'] = true;
  k -= 5;

  dfs(0, 0);
  cout << mnr << '\n';
  
  return 0;
}
