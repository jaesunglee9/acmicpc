// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

// is pure, and color, true = blue, false = zero
tuple<bool, bool> pure(bool* p, int width, int view)
{ 
       	bool prev = p[0];
	for (int i = 0; i < view; i++) {
		for (int j = 0; j < view; j++) {
			bool curr = p[i * width + j];
			if (prev != curr) {
				return make_tuple(false, false);
			}
		}
	}
	
	return make_tuple(true, prev);
}	

	
tuple<int, int> get_count(bool* p, int width,  int view)
{
	bool is_pure;
	bool color;
	tie (is_pure, color) = pure(p, width, view);
		
	if (is_pure) {
		if (color) {
			return make_tuple(0, 1);
		} else {
 			return make_tuple(1, 0);
		}
	} else {
		int subview = view / 2;
		int w_count = 0;
		int b_count = 0;

		int w, b;
		tie (w, b) = get_count(p, width, subview);
		w_count += w;
		b_count += b;
		tie (w, b) = get_count(p + subview, width, subview);
		w_count += w;
		b_count += b;
		tie (w, b) = get_count(p + subview * width, width, subview);
		w_count += w;
		b_count += b;
		tie (w, b) = get_count(p + subview * width + subview, width, subview);
		w_count += w;
		b_count += b;
		
		return make_tuple(w_count, b_count);
	}
}
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	bool *p = new bool[n * n];
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		p[i] = (x == 1);
	}

	int w_count, b_count;
        tie(w_count, b_count) =  get_count(p, n,  n);
	cout << w_count << '\n' << b_count << '\n';

	return 0;
}


