#include <iostream>
#include <string>
#include <set>

int
main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;

  std::string op;
  int e;

  int s[20] = {0};

  for (int i = 0; i < n; i++) {
    std::cin >> op;
    if (std::cin.peek() != '\n') {
      std::cin >> e;
    } else {
      e = 0;
    }

    if (op == "add") {
      s[e - 1] = 1;
    } else if (op == "remove") {
      s[e - 1] = 0;
    } else if (op == "check") {
      std::cout << s[e - 1] << '\n';
    } else if (op == "toggle") {
      s[e - 1] ^= 1;
    } else if (op == "all") {
      for (int j = 0; j < 20; j++) {
	s[j] = 1;
      }
    } else if (op == "empty") {
      for (int j = 0; j < 20; j++) {
	s[j] = 0;
      }
    }
  }

  return 0;
}
