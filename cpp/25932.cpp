#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;
    bool w, x, y, z;

    int arr[10];
    std::cin >> l;
    for (i=0;i<l;i++) {
        bool w = false;
        bool x = false;
        for (j=0;j<10;j++) {
            std::cin>>m;
            if (m == 17) {
                w = true;
            }
            if (m == 18) {
                x = true;
            }
            arr[j] = m;
        }
        for (j=0;j<10;j++) {
            std::cout << arr[j] << ' ';
        }
        std::cout << '\n';
        if (w && x) {
            std::cout << "both";
        } else if (w) {
            std::cout << "zack";
        } else if (x) {
            std::cout << "mack";
        } else {
            std::cout << "none";
        }
        std::cout << '\n';
        std::cout << '\n';
    }
}
