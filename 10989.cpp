#include <iostream>

int
main (void)
{
    int n;
    std::cin >> n;

    int arr[10000] = {0};

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr[num - 1] += 1;
    }

    for (int i = 0; i < 10000; i++) {
        int m = arr[i];
        while (m > 0) {
            std::cout << i + 1 << '\n';
            m -= 1;
        }
    }

    return 0;
}
