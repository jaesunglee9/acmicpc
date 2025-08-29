// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

vector<vector<unordered_set<int>>>
grid2puzzle(vector<vector<int>>& grid) {
  vector<vector<unordered_set<int>>> res(9, vector<unordered_set<int>>(9));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) { res[i][j] = {1,2,3,4,5,6,7,8,9}; }
      else { res[i][j] = { grid[i][j] }; }
    }
  }

  return res;
}

bool
isvalid(vector<vector<unordered_set<int>>>& puzzle) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if 

void
        print(vector<vector<unordered_set<int>>>& puzzle) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      for (const auto& ele : puzzle[i][j]) {
        cout << ele;
      }
    }
    cout << '\n';
  }
}

// constraint propagation & search
vector<vector<unordered_set<int>>>
f(const vector<vector<int>>& grid) {
  auto puzzle = grid2puzzle(grid);
  auto res = search(constrain(puzzle));

  return res;
}

int
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> a(9);
  for (int i = 0; i < 9; i++) {
    string str; cin >> str;
    for (const auto& ch : str) {
      a[i].push_back(int(ch));
    }
  }

  // if any square contains -1, that means no solution
  auto res = f(a);
  print(res);     
  return 0;
}


