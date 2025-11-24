#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<char>> board;
vector<vector<bool>> instack;
vector<vector<int>> dp;
bool isInf = false;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void
dfs(int r, int c) {
  if (isInf) return;
  if (board[r][c] == 'H') return;
  if (instack[r][c]) {isInf = true; return;}
  if (dp[r][c] != -1) return;

  instack[r][c] = true;
  int moveLen = board[r][c] - '0';
  int best = 0;
  for (int i = 0; i < 4; i++) {
    int nextR = r + dir[i][0] * moveLen;
    int nextC = c + dir[i][1] * moveLen;
    if (!(0 <= nextR && nextR < n && 0 <= nextC && nextC < m)) {
      continue;
    }
    if (board[nextR][nextC] == 'H') {
      continue;
    }
    if (instack[nextR][nextC]) {
      isInf = true;
      return;
    }

    
    dfs(nextR, nextC);
    if (isInf) return;
    best = max(best, dp[nextR][nextC] + 1);
  }
  instack[r][c] = false;
  dp[r][c] = best;
}

int
main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  board.resize(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  instack.resize(n, vector<bool>(m, false));
  dp.resize(n, vector<int>(m, -1));
  
  dfs(0, 0);
  
  if (isInf) cout << -1;
  else cout << dp[0][0] + 1;
  return 0;
}
