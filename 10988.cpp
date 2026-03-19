#include <iostream>
#include <string>

int
main(void)
{
	int n, i, j, k;
	std::string str;
	std::getline(std::cin, str);
	int l = str.length();
	int a = 0;
	int b = l-1;
	int c = 1;
	
	while (a <= b) {
	  if (str[a] != str[b]) {
	    c = 0;
	    break;
	  } else {
	    a += 1;
	    b -= 1;
	  }
	}
	std::cout << c;
	  
	    
	return 0;
}
		
	
