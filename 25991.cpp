#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>



int
main(void)
{
	char a, b, c, d, e;
	double f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    std::cin >> l;
    f = 0;
    for(i=0;i<l;i++) {
        std::cin >> g;
        f += g * g * g;
    }

    std::cout << std::fixed << std::setprecision(6) << std::pow(f, 1.0/3.0);
}
