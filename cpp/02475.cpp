#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

    int arr[5];

	for (i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    n = 0;
    for (i = 0; i < 5; i++) {
        n += arr[i] * arr[i];
    }
    std::cout << n % 10;


	return 0;
}
