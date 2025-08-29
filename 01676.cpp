// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
using namespace std;

const int INF = 1e9 + 7;


int f(int n) {
    int five = 0;
    for (int i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    return five;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	cout << f(n) << '\n';
	return 0;
}


