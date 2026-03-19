#include <iostream>
#include <iomanip>


using namespace std;
typedef long long ll;
const int inf = 1e9+7;

int
main(void) {
	int k, p, x; cin >> k >> p >> x;

	
	int m = 1;
	float minpay = inf;

	while (1) {
		float time = float(k) / m ;
		float pay = x * m + time * p;
		if (pay >= minpay) break;
		minpay = pay;
		m++;
	}

	std::cout << std::fixed << std::setprecision(3) << minpay << '\n';
	return 0;

}
	
	
