#include <iostream>

int
combination (int n, int k)
{
    int res;

    if (k == 0 || k == n) {
        res = 1;
    } else {
        res = combination (n - 1, k - 1) + combination (n - 1, k);
    }
    return res;
}



int
main (void)
{
    int n, k;

    std::cin >> n >> k;

    std::cout << combination (n, k);

    return 0;
}
