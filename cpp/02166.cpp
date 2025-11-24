// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

double triangleArea(double x1, double y1,
		    double x2, double y2,
		    double x3, double y3) {
	return (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	double xs, ys, x1, x2, y1, y2;
	cin >> xs >> ys >> x1 >> y1;

	double area = 0;
	for (int i = 2; i < n; i++) {
		cin >> x2 >> y2;
		area += triangleArea(xs, ys, x1, y1, x2, y2);
		x1 = x2;
		y1 = y2;
	}

	cout << fixed<< setprecision(1) << fabs(area) << '\n';
	return 0;
}


