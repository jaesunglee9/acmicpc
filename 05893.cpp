// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

        array<int, 1010> n = {};

	int i;
	int l = s.size();
	for (i = 0; i < l; i++) {
		n[i] = s[l - i - 1] - '0'; // flip
	}

	array<int, 1010> n1 = {};
	for (int i = 0; i < l; i++) {
		n1[i + 4] = n[i];
	}

	int carry = 0;
	for (int i = 0; i < l + 9; i++) {
		int v = n1[i] + n[i] + carry;

		if (v < 2) {
			carry = 0;
		} else {
			carry = 1;
			if (v == 2) {
				v = 0;
			} else {
				v = 1;
			}
		}
		n1[i] = v;
	}


	int hi = l + 6;
	while (hi > 0 && n1[hi] == 0) hi--;
	
	for (int i = hi; i >= 0; i--) {

		cout << n1[i];
	}

	return 0;
}


