#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<pair<int, int>> ATH;


struct SegTree {
  int h;
  int ls;  // leaf start index
  vector<int> tree;
  SegTree(int a) {
    h = 1;
    int nl = 1;
    while (nl < a) {
      h += 1;
      nl *= 2;
    }
    tree.resize(1 << h, 0);
    ls = (1 << (h-1));
  }

  ll
  query(int l, int r) {
    ll sum = 0;
    l += ls;
    r += ls;
    while (l <= r) {
      if (l % 2 == 1) sum += tree[l++];
      if (r % 2 == 0) sum += tree[r--];
      l /= 2;
      r /= 2;
    }

    return sum;
  }

  void
  update(int idx, int val) {
    idx += ls;
    tree[idx] += val;
    while (idx > 1) {
      idx /= 2;
      tree[idx] = tree[2*idx] + tree[2*idx + 1];
    }
  }
};
  




// power comparison
bool pcmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second;
}

int
main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    ATH.emplace_back(i, a);  
  }

  // coordinate compression
  sort(ATH.begin(), ATH.end(), pcmp);
  for (int i = 0; i < N; i++) {
    ATH[i].second = i;
  }
  sort(ATH.begin(), ATH.end());

  vector<ll> res;

  // Why use segtree? from first to last, on each lookup of athelete, we get his best
  // index, and this best index is inserted to st. on each lookup, we search from 0 to i,
  SegTree st(N);
  for (int i = 0; i < N; i++) {
    int p = ATH[i].second;
    res.push_back(st.query(p+1, N-1) + 1);
    st.update(p, 1);
  }

  for (int i = 0; i < N; i++) {
    cout << res[i] << '\n';
  }
  
  return 0;
}
