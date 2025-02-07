#include <iostream>
#include <string>

int len(int n) {
    int res = 0;
    while (n > 0) {
        res += 1;
        n /= 10;
    }
    return res;
}

int dsum(int n){
    int res = n;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    std::cin >> l;
    m = 1;
    while (m < l) {
        if (dsum(m) == l) {
            std::cout << m;
            return 0;
        }
        m++;
    }

    std::cout << 0;


}
