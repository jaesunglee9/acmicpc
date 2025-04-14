// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

void pre(vector<vector<int>>& t, int curr) {
	if (curr == -1) {
		return;
	}

	cout << char(curr + 'A');
	pre(t, t[curr][0]);
	pre(t, t[curr][1]);
}

void in(vector<vector<int>> & t, int curr) {
	if (curr == -1) return;
	
	in(t, t[curr][0]);
	cout << char(curr + 'A');
	in(t, t[curr][1]);
}

void post(vector<vector<int>>& t, int curr) {
	if (curr == -1) return;

	post(t, t[curr][0]);
	post(t, t[curr][1]);
	cout << char(curr + 'A');
}
	
	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> t(n, vector<int>(2,0));

	for (int i = 0; i < n; i++) {
		char cp, cl, cr;
		cin >> cp >> cl >> cr;
		int p = int(cp - 'A');
		if (cl == '.') {
			t[p][0] = -1;
		} else {
			t[p][0] = cl - 'A';
		}
		if (cr == '.') {
			t[p][1] = -1;
		} else {
			t[p][1] = cr - 'A';
		}
	}

	pre(t, 0);
	cout << endl;
	in(t, 0);
	cout << endl;
	post(t, 0);
	cout << endl;
	       
		

			      

	return 0;
}


