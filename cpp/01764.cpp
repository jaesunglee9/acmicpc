// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_set<string> unheard;
  unordered_set<string> unseen;
  vector<string> res;

  int n, m;
  cin >> n >> m;

  string s;

  for (int i = 0; i < n; i++) {
    cin >> s;
    unheard.insert(s);
  }

  for (int i = 0; i< m; i++) {
    cin >> s;
    unseen.insert(s);
  }

  int count = 0;
  for (const auto& e: unheard) {
    if (unseen.count(e) != 0) {
      res.push_back(e);
      count++;
    }
  }

  sort(res.begin(), res.end());

  cout << count << '\n';
  for (const auto& e: res) {
    cout << e << '\n';
  }
  return 0;
}


