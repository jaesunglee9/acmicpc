#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;
vector<pair<int, int>> frame;
vector<int> t_ins;
int n_curr = 0;

void print_frame() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << frame[i].first << ' ' <<frame[i].second;
  }
  cout << '\n';
}

void print_time() {
  for (int i = 0; i <= n; i++) {
    cout << t_ins[i] << ' ';
  }
  cout << '\n';
}

void
add(int s, int t) {
  int min_vote = 1000000;
  int min_s_idx = 0;
  
  for (int i = 1; i <= n; i++) {
    if (frame[i].first == s) {
      frame[i].second += 1;
      return;
    }

    if (frame[i].first < 1) continue;

    int vote = frame[i].second;
    if (vote < min_vote) {
      min_vote = vote;
      min_s_idx = i;
    }
    else if (vote == min_vote) {
      if (t_ins[min_s_idx] > t_ins[i]) min_s_idx = i;
    }
  }

  if (n_curr < n) {
    for (int i = 1; i <= n; i++) {
      if (frame[i].first == 0) {
        frame[i].first = s;
        frame[i].second = 1;
        t_ins[i] = t;
        n_curr += 1;
        break;
      }
    }
  }
  else {
    frame[min_s_idx].first= s;
    frame[min_s_idx].second = 1;
    t_ins[min_s_idx] = t;

  }
}

int
main() {
  cin >> n >> m;
  frame.resize(n+1);
  t_ins.resize(m+1, 0);
  t_ins[0] = 99999;

  for (int i = 0; i < m; i++) {
    int num; cin >> num;
    add(num, i+1);
  }
  
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    res.push_back(frame[i].first);
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < n; i++) {
    if (res[i] > 0) cout << res[i] << ' ';
  }
  cout << '\n';
  return 0;
}
