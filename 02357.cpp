#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = (int) 1e9 + 7;

template<typename T, typename F>
struct SegmentTree {
	int n;
	int leaf;
	vector<T> tree;
        F op;
	T id;

	SegmentTree(vector<T>& a, F func, T identity) : op(func), id(identity) {
		_init(a);
	}
	

	void
	_init(vector<T>& a) {
		n = a.size();
		leaf = 1;

		while (leaf < n) leaf <<= 1;

		tree.assign(leaf * 2, id);

		for (int i = 0; i < n; i++)
		{
			tree[leaf + i] = a[i];
		}

		for (int i = leaf - 1; i > 0; i--)
		{
			tree[i] = op(tree[2 * i], tree[2 * i + 1]);
		}
	}

	void
	update(int idx, T val) {
		idx += leaf;
		tree[idx] = val;

		for (idx /= 2; idx > 0; idx /= 2)
		{
			tree[idx] = op(tree[2 * idx], tree[2 * idx + 1]);
		}
	}

	T
	query(int l, int r) {
		l += leaf;
		r += leaf;

		T res = id;

		while (l <= r)
		{
			if (l % 2 == 1)
			{
				res = op(res, tree[l]);
				l++;
			}
			if (r % 2 == 0)
			{
				res = op(res, tree[r]);
				r--;
			}
			
			l /= 2;
			r /= 2;			
		}

		return res;
	}				
};

void
sol0(vector<int>& a,
     vector<pair<int, int>>& q,
     int n, int m)
{
	auto mnOp = [](int a, int b) { return min(a, b); };
	SegmentTree<int, decltype(mnOp)> mnST(a, mnOp, INF);
	auto mxOp = [](int a, int b) { return max(a, b); };
	SegmentTree<int, decltype(mxOp)> mxST(a, mxOp, -INF);

	for (int i = 0; i < m; i++)
	{
		auto [s, e] = q[i]; s--; e--;
		cout << mnST.query(s, e) << ' ' << mxST.query(s, e) << '\n';
	}

	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	vector<int> a;
	vector<pair<int, int>> q;

	cin >> n >> m;
	a.resize(n);
	q.resize(m);
	for (int i = 0; i < n; i++)
	{
	        cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> q[i].first >> q[i].second;
	}

	sol0(a, q, n, m);

	return 0;
}
	
