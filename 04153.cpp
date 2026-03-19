#include <iostream>
#include <string>

int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n, o, p, q, r, s;
    long long t, u, v;

    int arr[3];
    while (1) {
        std::cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            break;
        }
        bool is_right = false;
        for (i=0;i<3;i++) {
            if (arr[i%3] * arr[i%3] + arr[(i+1)%3] * arr[(i+1)%3] == arr[(i+2)%3] * arr[(i+2)%3]) {
                is_right = true;
                break;
            }
        }
        if (is_right) {
            std::cout << "right" << '\n';
        } else {
            std::cout << "wrong" << '\n';
        }
    }
}
