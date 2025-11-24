#if 1
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

const int q = int(1e9 + 7);

int N;

vector<int> H;
vector<vector<int>> DP;



void
solve() {
  if (H[0] == -1 || H[0] == 0) {
    DP[0][0] = 1;
  }
  else DP[0][0] = 0;

  for (int i = 0; i < N - 1; i++) {
    int maxi = min(i, N - 1 - i);
    for (int j = 0; j <= maxi; j++) {
      if (DP[i][j] == 0) continue;
      int maxii = min(i+1, N - 1 - i - 1);
      for (int dj = -1; dj <= 1; dj++) {
        int nj = j + dj;
        if (0 <= nj && nj <= maxii
            &&(H[i + 1] == -1 ||  nj == H[i+1])) {
          DP[i + 1][nj] = (DP[i + 1][nj] + DP[i][j]) % q;
        }
      }
    }
  }

  cout << DP[N-1][0] << '\n';
}



int
main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  
  DP.resize(N, vector<int>(5001, 0));

  solve();
  return 0;
}

#endif
