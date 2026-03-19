#include <iostream>
#include <string>

int ceil(int a, int b) {
    return (a / b + int ((a % b) != 0));
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    std::cin >> l >> m >> n >> o >> p >> q >> k >> r >> s;
    std::cout << ceil(m,r) + ceil(n,r) + ceil(o,r) + ceil(p,r) + ceil(q,r) + ceil(k,r) << '\n';
    std::cout << l / s << ' ' << l % s;
}
