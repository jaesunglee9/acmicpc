#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

    int arr[7];
    for (i=0; i< 7; i++) {
        std::cin >> arr[i];
    }

    n = 0;
    m = 100;
    for (i=0;i<7;i++) {
        if (arr[i] % 2 == 1) {
            n += arr[i];
            if (arr[i] < m) {
                m = arr[i];
            }
        }
    }

    if (n == 0) {
        std::cout << -1;
    } else {
        std::cout << n << '\n' << m;
    }
	return 0;
}
