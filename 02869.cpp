#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    std::cin >> l >> m >> n;

    std::cout << (n - l)/(l - m) + ((n-l)%(l-m) != 0 ? 1 : 0) + 1;
}
