#include <iostream>
#include <string>


int
main(void)
{
	char a, b, c, d, e;
	float f, g, h;
	int i, j, k, l, m, n;
    long long o, p, q;

	std::string s, t, u;

    std::cin >> n >> m;

	int* arr1 = new int[n * m];
    int* arr2 = new int[n * m];
	int* arr3 = new int[n * m];

    for (i = 0; i < n; i++) {
        for (j=0;j<m;j++) {
            std::cin >> arr1[i*m + j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j=0;j<m;j++) {
            std::cin >> arr2[i*m + j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j=0;j<m;j++) {
            arr3[i*m + j] = arr1[i*m + j] + arr2[i*m + j];
        }
    }



    for (i = 0; i < n; i++) {
        for (j=0;j<m;j++) {
            std::cout << arr3[i*m + j] << ' ';
        }
        std::cout << '\n';
    }

}
