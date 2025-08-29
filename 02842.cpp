#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int INF = int(1e9 + 7);

int N;

pair<int, int> P; // P
vector<vector<int>> T;  // Town
vector<vector<int>> A;  // Alt
vector<int> AA;  // Array of altitudes  
vector<pair<int, int>> KP;


bool
can_deliver(int low, int high) {
	int dr[] = { 1, 1,  1, 0,  0, -1, -1, -1};
	int dc[] = { 1, 0, -1, 1, -1,  1,  0, -1 };
        queue<pair<int, int>> q;
	q.push(P);
	vector<vector<bool>> v(N, vector<bool>(N, false));

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		if (!(low <= A[p.first][p.second] && A[p.first][p.second] <= high)
                    || v[p.first][p.second]) continue;
		v[p.first][p.second] = true;
		for (int i = 0; i < 8; i++) {
			int next_r = p.first + dr[i];
			int next_c = p.second + dc[i];
			if (0 <= next_r && next_r < N && 0 <= next_c && next_c < N) {
				q.push({ next_r, next_c });
			}
		}
	
	}

	for (auto& p : KP) {
		if (!v[p.first][p.second]) {
			return false;
		}
	}

	return true;
}	


void
s0() {
  int mp = INF;
  int l = 0;
  int r = 0;
  while (r < AA.size() && l < AA.size() && l <= r) {
    if (can_deliver(AA[l], AA[r])) {
      mp = min(mp, AA[r] - AA[l]);
      l++;
    }
    else {
      r++;
    }
  }

  cout << mp << '\n';
}


int
main() {
  ios::sync_with_stdio(false);cin.tie(0);

  cin >> N;
  T.resize(N, vector<int>(N));
  A.resize(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    for (int j = 0; j < N; j++) {
      T[i][j] = str[j];
      if (str[j] == 'P') {
        P = {i, j};
      }
      if (str[j] == 'K') {
        KP.emplace_back(i, j);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      AA.push_back(A[i][j]);
    }
  }
  sort(AA.begin(), AA.end());
  AA.erase(unique(AA.begin(), AA.end()), AA.end());

  s0();
  
  return 0;
}
