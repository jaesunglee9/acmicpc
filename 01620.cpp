#include <bits/stdc++.h>
using namespace std;

int
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  unordered_map<string, int> umap_name;
  unordered_map<int, string> umap_ind;
  string s;

  for (int i = 0; i < n; i++) {
    cin >> s;
    umap_name[s] = i + 1;
    umap_ind[i+1] = s;
  }

  for (int i = 0; i < m; i++) {
    cin >> s;
    if (s[0] >= 'A' && s[0] <= 'Z' || s[0] >= 'a' && s[0] <= 'z') {
      cout << umap_name[s] << '\n';
    } else {
      int index = stoi(s);
      cout << umap_ind[index] << '\n';
    }
  }

  return 0;
}


