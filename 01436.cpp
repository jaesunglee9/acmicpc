#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

bool compareStrings(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) {
        return a < b; // Lexicographical order
    }
    return a.length() < b.length(); // Sort by length
}

int
main()
{
  int n;
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string input;
  std::vector<std::string> words;

  for (int i = 0; i < n; i++) {
    std::getline(std::cin, input);
    if (std::find(words.begin(), words.end(), input) != words.end()) {
      continue;
    }
    words.push_back(input);
  }

  std::sort(words.begin(), words.end(), compareStrings);

  for (int i = 0; i < words.size(); i++) {
    std::cout << words[i] << std::endl;
  }

  return 0;
}

