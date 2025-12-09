#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll det(const vector<vector<int>>& a) {
	



int
main(void)

{
	int n, a, b, c, d, e, f, g, h;
	cin >> n >> a >> b >> c >> d >> e >> f >> g >> h;

	int g1 = ggcd({a, b, c, d});
	int g2 = gcd({e, f, g, h});
	if (a / g1 == e / g2 && b / g1  == f / g2 && c / g1 == g / g2) {
		if (d / g1 == h / g2) { //infinite
			cout << "1\n";
		}
		else { //parallel
			cout << "2\n";
		}
	}
	else {
		cout << "0\n";
	}
		
	
      

	return 0;

}
