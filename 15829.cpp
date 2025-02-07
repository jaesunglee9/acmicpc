#include <iostream>
#include <string>

long long
val (int a, int r, int i) {
    long long res = 1;
    if (i==0) {
        return a;
    } else {
        return val(a, r, i-1) * r % 1234567891;
    }
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
    std::string line;
    std::cin >> line;

    m = 1234567891;
    t=0;
    for (i=0;i<l;i++) {
        t += val((line[i] - 'a' + 1), 31, i);
    }
    t %= m;
    std::cout << t;
}
