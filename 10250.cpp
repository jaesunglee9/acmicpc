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

	std::cin >> n;

    for (i=0;i<n;i++) {
        std::cin >> o >> p >> q;
        std::cout << (q % o == 0 ? o : q % o) * 100 + (q % o == 0 ? q / o : q / o + 1) << '\n';

    }

	return 0;
}
