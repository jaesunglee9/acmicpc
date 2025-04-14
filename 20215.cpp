// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double a , b;
	cin >> a >> b;

	cout << fixed << setprecision(15) <<(a + b) - sqrt(a*a + b*b) << '\n';
	return 0;
}


