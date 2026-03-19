// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;
	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		string c; cin >> c;  // command
		if (c == "push") {
			int e; cin >> e;
			q.push(e);
		}
		if (c == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			} else {
				cout << -1 << '\n';
			}
		}		
		if (c == "size") cout << q.size() << '\n';
		if (c == "empty") cout << q.empty() << '\n';
		if (c == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
		if (c == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}
			
	return 0;
}


