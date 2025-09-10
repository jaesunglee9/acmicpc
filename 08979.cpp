#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct st {
	int id;
	int p;
	int g;
	int s;
	int b;
};


inline bool cc(const st& a, const st& b) {
	if (a.g == b.g) {
		if (a.s == b.s) {
			return a.b > b.b;
		}

		return a.s > b.s;
	}

	return a.g > b.g;
}

inline bool ce(const st& a, const st& b) {
	return (a.g == b.g && a.s == b.s && a.b == b.b);
}

void
printa(vector<st>& a) {
	cout << "id g s b p\n";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].id << ' ' << a[i].g << ' ' << a[i].s << ' '
		     << a[i].b << ' ' << a[i].p << '\n';
	}
}

	       

int
main(void) {
	int n, k; cin >> n >> k;
	vector<st> a;
	for (int i = 0; i < n; i++) {
		int id, g, s, b; cin >> id >> g >> s >> b;

		a.push_back({id, 0, g, s, b});
	}

	sort(a.begin(), a.end(), cc);
	
	a[0].p = 1;
	for (int i = 1; i < n; i++) {
		if (!ce(a[i - 1], a[i])) {
		        a[i].p = i + 1;
		}
		else {
		        a[i].p = a[i-1].p;
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i].id != k) continue;

		cout << a[i].p << '\n';
		break;
	}

	return 0;
}


