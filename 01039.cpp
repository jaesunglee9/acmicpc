#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

string STR_N;
int K;
int MAX = -1;

int M;
vector<vector<int>> DP;

int
solve(int depth) {
  if (depth == K) {
    return stoi(STR_N);
  }

  int n = stoi(STR_N);
  int& res = DP[n][depth];
  if (res != -1) return res;

  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      if (i == 0 && STR_N[j] == '0') continue;
      swap(STR_N[i], STR_N[j]);
      res = max(res, solve(depth + 1));
      swap(STR_N[i], STR_N[j]);
    }
  }
  return res;
}


int
main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> STR_N >> K;
  M = STR_N.size();
  if (M < 2) {
    cout << -1 << '\n';
    return 0;
  }
  
  
  DP.resize(1000001, vector<int>(11, -1));
  cout << solve(0) << '\n';
  
  return 0;
}
