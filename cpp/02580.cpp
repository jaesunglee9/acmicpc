#include <iostream>
#include <vector>
#include <unordered_set>
#include <optional>
#include <utility>

using namespace std;


void
constrain(vector<vector<unordered_set<int>>>& board, const pair<int, int>& cell, int n) {
  int r = cell.first;
  int c = cell.second;
  
  for (int i = 0; i < 9; i++) {
    board[r][i].erase(n);
    board[i][c].erase(n);
  }

  int sr, sc;
  if (r < 3) sr = 0;
  else if (r < 6) sr = 3;
  else sr = 6;

  if (c < 3) sc = 0;
  else if (c < 6) sc = 3;
  else sc = 6;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[sr + i][sc + j].erase(n);
    }
  }

  board[r][c] = {n};
}


int
check(const vector<vector<unordered_set<int>>>& board, pair<int, int>& minc) {
  int minn = 20;  // needs to be larger than 9
  /* 1 implies that the board is done,
     0 implies board is not complete, and
     -1 implies board is in impossible state
  */
  int status = 1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int cell = board[i][j].size();
      cout << cell << '\n';

      if (cell > 1) {
        status = 0;
        if (cell < minn) {
          minc.first = i;
          minc.second = j;
          minn = cell;
        }
      } 
      if (cell == 0) {
        status = -1;
        return status;
      }
    }
  }

  return status;
}



optional<vector<vector<unordered_set<int>>>>
dfs(const vector<vector<unordered_set<int>>>& board){
  pair<int, int> next;
  int status = check(board, next);

  if (status < 0) return nullopt;
  else if (status > 0) return board;
  else {
    for (auto& e : board[next.first][next.second]) {
      vector<vector<unordered_set<int>>> new_board = board;
      constrain(new_board, next, e);
      auto res = dfs(new_board);
      if (res != nullopt) return res;
    }
  }

  return nullopt;
}


int
main(void) {
  ios::sync_with_stdio(false); cin.tie(0);

  vector<vector<unordered_set<int>>>
      board(9, vector<unordered_set<int>>(9));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 1; k <= 9; k++) {
          board[i][j].insert(k);
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int input; cin >> input;
      if (input > 0) constrain(board, {i, j}, input);
    }
  }

  auto res = dfs(board);
  if (res) {
    auto ans = res.value();
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << *ans[i][j].begin() << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
