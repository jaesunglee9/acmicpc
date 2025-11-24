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

	std::cin >> n;

    if (620 <= n && n <= 780) {
        std::cout << "Red";
    } else if (590 <= n) {
        std::cout << "Orange";
    } else if (570 <= n) {
        std::cout << "Yellow";
    } else if (495 <= n) {
        std::cout << "Green";
    } else if (450 <= n) {
        std::cout << "Blue";
    } else if (425 <= n) {
        std::cout << "Indigo";
    } else if (380 <= n) {
        std::cout << "Violet";
    }


	return 0;
}
