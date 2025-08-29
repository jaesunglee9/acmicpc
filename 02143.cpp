#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;


int T, N, M;

vector<int> A, B;

void
s0() {

  
  vector<vector<int>> aps(N, vector<int>(N));
  vector<vector<int>> bps(M, vector<int>(M));

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    aps[0][i] = sum;
  }

  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j++) {
      aps[i][j] = aps[i-1][j] - A[i-1];
    }
  }

  sum = 0;
  for (int i = 0; i < M; i++) {
    sum += B[i];
    bps[0][i] = sum;
  }

  for (int i = 1; i < M; i++) {
    for (int j = i; j < M; j++) {
      bps[i][j] = bps[i-1][j] - B[i-1];
    }
  }

  unordered_map<int, int> um;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      um[T - aps[i][j]] += 1;
    }
  }

  ll cnt = 0;
  for (int i = 0; i < M; i++) {
    for (int j = i; j < M; j++) {
      cnt += um[bps[i][j]];
    }
  }

  cout << cnt << '\n';
}


void
s1() {
  vector<ll> as, bs;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      as.emplace_back(sum);
    }
  }
  for (int i = 0; i < M; i++) {
    int sum = 0;
    for (int j = i; j < M; j++) {
      sum += B[j];
      bs.emplace_back(sum);
    }
  }
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());

  int l = 0;  // for as
  int r = bs.size() - 1;  // bs

  ll cnt = 0;
  while (l < as.size() && r >= 0) {
    int sum = as[l] + bs[r];
    if (sum == T) {
      ll ca = 1;
      ll cb = 1;
      while (l + 1 < as.size() && as[l] == as[l+1]) {
        ca++;
        l++;
      }
      while (r-1 >= 0 && bs[r] == bs[r-1]) {
        cb++;
        r--;
      }
      cnt += (ca * cb);
      l++;
      r--;
    }
    else if (sum > T) {
      r--;
    }
    else {
      l++;
    }
  }

  cout << cnt << '\n';
}




int
main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> T;
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  B.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
    

  

  // s0();  // my solution using hashmaps
  s1();  // another approach on boj. my implementation. using two pointers.

  return 0;

}
