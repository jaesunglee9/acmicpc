#include <iostream>
#include <string>

bool prime(int a) {
    if (a == 1) {
        return false;
    }
    if (a == 2) {
        return true;
    }

    bool is_prime = true;
    for(int i=2;i<a;i++) {
        if (a % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    std::cin >> l;
    m = 0;
    for (i=0;i<l;i++) {
        std::cin>>n;
        if (prime(n)) {
            m++;
        }
    }
    std::cout <<m;
}
