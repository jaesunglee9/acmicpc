#include <iostream>

int
main(void)
{
	int n, i, j, k;
	std::cin >> n;

	for (i = 1; i <= n; i++) {
	  for (j = (n-i)-1; j >= 0; j--) {
			std::cout << ' ';
		}
		for (j = 1; j <= 2 * i - 1; j++) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
	for (i = 1; i <= n-1; i++) {
		for (j = 1; j <= i; j++) {
			std::cout << ' ';
		}
		for (j = 2*(n - i) - 1; j >= 1; j--) {
		  std::cout << '*';
		}
		std::cout << '\n';
	}
	return 0;
}
		
	
