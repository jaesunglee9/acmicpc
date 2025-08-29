#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int N;
vector<string> W;
vector<char> A;
vector<int> C;  // for choice;
vector<bool> V(10, false);

int BEST = 0;
int MD;

int
calc() {
  int sum = 0;
  for (string& str : W) {
    int tmp = 0;
    for (int i = 0; i < str.size(); i++) {
      char ch = str[i];
      for (int j = 0; j < A.size(); j++) {
        if (str[i] == A[j]) {
          tmp = tmp * 10 + C[j];
          break;
        }
      }
    }
    sum += tmp;
  }
  return sum;
}


// using DFS,
void
solve(int depth) {
  if (depth == MD) {
    int tmp = calc();
    BEST = max(BEST, tmp);
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (V[i] == true) continue;

    C[depth] = i;
    V[i] = true;
    solve(depth + 1);
    V[i] = false;
  }
}


int
main() {
  ios::sync_with_stdio(false);cin.tie(0);
  
  cin >> N;
  vector<int> tmp;
  tmp.resize(26, false);
  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    for (auto& ch : str) {
      tmp[ch - 'A'] = true;
    }
    W.push_back(str);
  }
  for (int i = 0; i < 26; i++) {
    if (tmp[i] == true) {
      A.push_back('A' + i);
    }
  }
  MD = A.size();
  C.resize(MD, -1);

  solve(0);
  
  cout << BEST << '\n';
  return 0;
}
