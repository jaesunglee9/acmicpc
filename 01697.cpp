// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxlen = 100001;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> d(maxlen, -1);
	queue<int> q;

	int n, k;
	cin >> n >> k;
	
   
        d[n] = 0;
	q.push(n);
	
        while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int next: {x - 1, x + 1, 2 * x}) {
			if (next < 0 || next >= maxlen) continue;
			if (d[next] != -1) continue;

			d[next] = d[x] + 1;
			q.push(next);
		}
	}
			
	
	
	cout << d[k] << '\n';
	return 0;
}


