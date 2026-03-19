#include <iostream>
#include <string>

void
FizzBuzz (int n)
{
    bool isFB = false;
    if (n % 3 == 0) {
        std::cout << "Fizz";
        isFB = true;
    }
    if (n % 5 == 0) {
        std::cout << "Buzz";
        isFB = true;
    }

    if (!isFB) {
        std::cout << n;
    }

    std::cout << '\n';

    return;
}

// There must be at least one number in 3 consecutive entries.
int
main ()
{
    int n;

    std::string entry;
    for (int i = 0; i < 3; i++) {
        std::cin >> entry;
        if (!(entry == "Fizz" || entry == "Buzz" || entry == "FizzBuzz")) {
            n = std::stoi(entry) + (3 - i);  // n is next entry after the given input
        }
    }

    FizzBuzz (n);

    return 0;
}
