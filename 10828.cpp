// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

const int INF = 1e9 + 7;
	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		string c; cin >> c;  // command
		if (c == "push") {
			int e; cin >> e;
			s.push(e);
		}
		if (c == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			} else {
				cout << -1 << '\n';
			}
		}		
		if (c == "size") cout << s.size() << '\n';
		if (c == "empty") cout << s.empty() << '\n';
		if (c == "top") {
			if (!s.empty()) {
				cout << s.top() << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}
			
	return 0;
}


