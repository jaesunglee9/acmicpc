#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r;
    long long t, u, v;

	std::cin >> n >> o >> p;
    std::cout << n + o - p << '\n';
    q = 1;
    r = o;
    while (r > 9) {
        r = r / 10;
        q += 1;
    }
    while (q > 0) {
        n *= 10;
        q--;
    }

    std::cout << n + o - p;


	return 0;
}
