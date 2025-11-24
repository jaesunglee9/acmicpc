#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r;
    long long t, u, v;

    int cards[100];

	std::cin >> l >> m;

    for (i=0;i<l;i++) {
        std::cin>>cards[i];
    }
    n=3000000;
    for (i=0;i<l-2;i++) {
        for (j=i+1;j<l-1;j++) {
            for (k=j+1;k<l;k++) {
                o = cards[i] + cards[j] + cards[k];
                if (o > m) {
                    continue;
                }
                if (m-o < n) {
                    n = m-o;
                    p = o;
                }
            }
        }
    }
    std::cout << p;
    return 0;
}
