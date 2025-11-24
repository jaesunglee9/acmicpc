#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;

vector<vector<char>> map;
vector<vector<bool>> visited;

struct Node {
  int r, c;
};

queue<Node> q_h;
queue<Node> q_w;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pair<int, int> src;
pair<int, int> dest;

void
printmap() {
  for (auto& r : map) {
    for (auto& c : r) {
      cout << c;
    }
    cout << '\n';
  }
}

bool
in_bound(int r, int c) {
  return 0  <= r && r < R && 0 <= c && c < C;
}

void
bfs() {
  int time = 0;
  while (!q_h.empty()) {
    // next minutes water flow
    int qwsz = q_w.size();
    for (int i = 0; i < qwsz; ++i) {
      Node curr = q_w.front(); q_w.pop();
      for (int j = 0; j < 4; ++j) {
        int next_r = curr.r + dir[j][0];
        int next_c = curr.c + dir[j][1];
        if (!in_bound(next_r, next_c)) continue;
        char cell = map[next_r][next_c];
        if (cell != '.') continue;
        map[next_r][next_c] = '*';
        q_w.push({next_r, next_c});
      }
    }
    int qhsz = q_h.size();
    for (int i = 0; i < qhsz; ++i) {
      Node curr = q_h.front(); q_h.pop();
      if (map[curr.r][curr.c] == 'D') {
        cout << time;
        return;
      }
      for (int j = 0; j < 4; j++) {
        int next_r = curr.r + dir[j][0];
        int next_c = curr.c + dir[j][1];
        if (!in_bound(next_r, next_c)) continue;
        if (visited[next_r][next_c]) continue;
        char cell = map[next_r][next_c];
        if (cell == '.' || cell == 'D') {
          visited[next_r][next_c] = true;
          q_h.push({next_r, next_c});
        } 
      }
    }
    time++;
  }
  cout << "KAKTUS" << '\n';
}

void
input() {
  cin >> R >> C;
  map.resize(R, vector<char>(C));
  visited.resize(R, vector<bool>(C, false));
	
  for (int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      char type; cin >> type;
      map[i][j] = type;
      if (type == 'S') {
        src.first = i;
        src.second = j;
        q_h.push({i, j});
        visited[i][j] = true;
        map[i][j] = '.';
      }
      if (type == 'D') {
        dest.first = i;
        dest.second = j;
      }
      if (type == '*') {
        q_w.push({i, j});
      }
    }
  }
}


int 
main(void) {
  input();	
  bfs();
}
