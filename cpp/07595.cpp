#include <iostream>
#include <string>

void
print_triangle(int n) {
    for(int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r;
    long long t, u, v;

    char carr[31];

	while((std::cin >> n) && n != 0) {
        print_triangle(n);
    }
}
