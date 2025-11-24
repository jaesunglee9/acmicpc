#include <iostream>
#include <string>

int
main(void)
{
	int n, i, j, k;
	std::string s;
	std::getline(std::cin, s);
	int l = s.length();
	int a = 0;
	int b = l-1;
	int c = 1;
	
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 32;
		}
	}

	int freq[26] = {0};
	for (i = 0; s[i] != '\0'; i++) {
		freq[s[i] - 'A'] += 1;
	}
	
	int max_freq = 0;
	char most_freq;
	bool isTie = false;

	for (i = 0; i < 26; i++) {
		if (freq[i] > max_freq) {
			max_freq = freq[i];
			most_freq = 'A' + i;
			isTie = false;
		} else if (freq[i] == max_freq) {
			isTie = true;
		}
	}

	if (isTie) {
		std::cout << '?' << std::endl;
	} else {
		std::cout << most_freq << std::endl;
	}
	  
	    
	return 0;
}
		
	
