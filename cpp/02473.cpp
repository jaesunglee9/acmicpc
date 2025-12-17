v#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const ll INF = 3e9 + 7;

struct Mix {
	int v;
	int s1;
	int s2;
	int s3;

	bool operator<(const Mix& other) const {
		return v < other.v;
	}
};


// TLE and Memory overflow solution.
void
sol0(int n, vector<int>& a)
{
	vector<Mix> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == j || j == k || i == k) continue;
				s.push_back(Mix{a[i] + a[j] + a[k], i, j, k});
			}
		}
	}

	sort (s.begin(), s.end());

	auto it = lower_bound(s.begin(), s.end(), Mix{0, 0, 0, 0});
	if (it == s.end()) it--;

	Mix r = *it;
	Mix l = *(it - 1);
	
	int rd = abs(r.v);
	int ld = abs(l.v);

	Mix ans;
	if (ld < rd)
	{
		ans = l;
	}
	else if (ld > rd)
	{
		ans = r;
	}
	else
	{
		ans = l;
	}

	vector<int> res;
	res.push_back(a[ans.s1]);
	res.push_back(a[ans.s2]);
	res.push_back(a[ans.s3]);
	sort(res.begin(), res.end());
	for (int i = 0; i < 3; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}


void
sol1(int n, vector<int>& a)
{
	sort(a.begin(), a.end());

	ll mn = INF;
	int s[3] = {0, 0, 0};
	for (int i = 0; i < n; i++) {
		int l = i;
		int m = i + 1;
		int r = n - 1;
		while (m < r) {
			ll sum = (ll)a[l] + a[m] + a[r];

			if (llabs(sum) < mn) {
				mn = llabs(sum);
				s[0] = a[l];
				s[1] = a[m];
				s[2] = a[r];
			}

			if (sum < 0) m++;
			else if (sum > 0) r--;
			else break;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << s[i] << ' ';
	}
	cout << '\n';
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sol1(n, a);

	return 0;
}
	
	
