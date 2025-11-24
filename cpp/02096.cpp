#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int inf = int(1e9 + 7);

int N;
vector<int> A;

int
main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  A.resize(3);
  cin >> A[0] >> A[1] >> A[2];

  vector<int> maxs = A;  // max score
  vector<int> mins = A;

  for (int i = 1; i < N; i++) {
    cin >> A[0] >> A[1] >> A[2];
    vector<int> pmaxs = maxs;  // prev max score
    vector<int> pmins = mins;

    maxs[0] = max(pmaxs[0], pmaxs[1]) + A[0];
    maxs[1] = max({pmaxs[0], pmaxs[1], pmaxs[2]}) + A[1];
    maxs[2] = max(pmaxs[1], pmaxs[2]) + A[2];

    mins[0] = min(pmins[0], pmins[1]) + A[0];
    mins[1] = min({pmins[0], pmins[1], pmins[2]}) + A[1];
    mins[2] = min(pmins[1], pmins[2]) + A[2];
  }

  cout << *max_element(maxs.begin(), maxs.end()) << ' ' << *min_element(mins.begin(), mins.end()) << '\n';

  return 0;
}
