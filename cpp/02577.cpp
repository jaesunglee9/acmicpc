#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    char carr[31];
    int digits[10] = {0};

	std::cin >> m >> n >> o;
    p = m * n * o;

    while (p > 0) {
        digits[p % 10] += 1;
        p /= 10;
    }


    for (i = 0; i < 10; i++) {
        std::cout << digits[i] << '\n';
    }

	return 0;
}
