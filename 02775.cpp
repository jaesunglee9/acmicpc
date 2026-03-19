#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

int
people(int k, int n) {
    if (k == 0) {
        return n;
    }

    if (n == 1) {
        return 1;
    }

    return people(k-1, n) + people (k, n-1);
}
int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    std::cin >> l;
    for (i=0;i<l;i++) {
        std::cin >> m >> n;
        std::cout << people(m, n) << '\n';
    }

    return 0;
}
