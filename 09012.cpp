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
	for (int i = 0; i < n; i++) {
		stack<int> s;
		bool isVPS = true;
		string str;
		cin >> str;
		for (const auto& ch: str) {
			if (ch == '(') { s.push(')'); }
			else {
				if (s.empty()) {
					isVPS = false;
					break;
				} else {
					char c = s.top(); s.pop();
					if (c != ch) {
						isVPS = false;
						break;
					}
				}
			}
		}
		if (!s.empty()) {
			isVPS = false;
		}
		if (isVPS) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
				
	return 0;
}


