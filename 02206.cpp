#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
const int INF = int(1e9 + 7);

int N, M;
vector<vector<int>> MAP;
vector<vector<int>> D[2];  // INF, 0

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};


int 
bfs(void)
{
	queue<tuple<int, int, int>> q;

	q.push({0, 0, 0});
	D[0][0][0] = 1;

	while (!q.empty()) {
		auto [r, c, w] = q.front();
		q.pop();

		if (r == N - 1 && c == M - 1) return D[w][r][c];

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			
			if (MAP[nr][nc] == 1) {
				if (w == 0 && D[1][nr][nc] > D[0][r][c] + 1) {
					D[1][nr][nc] = D[0][r][c] + 1;
					q.push({nr, nc, 1});
				}
			}
			else {
				if (D[w][nr][nc] == INF) {
					D[w][nr][nc] = D[w][r][c] + 1;
					q.push({nr, nc, w});
				}
			}
		}
	}

	return -1;
}

	     

		
    


int
main(void)
{
	cin >> N >> M;
	MAP.resize(N, vector<int>(M));
	for (int i = 0; i < 2; i++) {
		D[i].assign(N, vector<int>(M, INF));
	}
	
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = str[j] - '0';
		}
	}

        cout << bfs() << '\n';

	return 0;
}

	

	

	
