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
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	while (q.size() > 1) {
		q.pop();
	        q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';
	

	return 0;
}


