#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int
main(void) {
	ios::sync_with_stdio(false);cin.tie(0);
	string str; cin >> str;

	string tmp = "";
	int n = str[0] - '0';
	if (n == 0 && str.size() == 1) {
		tmp = "0";
	}
	else {
		while (n > 0) {
			tmp.push_back('0' + n % 2);
			n /= 2;
		}
		reverse(tmp.begin(), tmp.end());
	}
	cout << tmp;

	string str0 = "000";
	string str1 = "001";
	string str2 = "010";
	string str3 = "011";
	string str4 = "100";
	string str5 = "101";
	string str6 = "110";
	string str7 = "111";
	
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '0') cout << str0;
		else if (str[i] == '1') cout << str1;
		else if (str[i] == '2') cout << str2;
		else if (str[i] == '3') cout << str3;
		else if (str[i] == '4') cout << str4;
		else if (str[i] == '5') cout << str5;
		else if (str[i] == '6') cout << str6;
		else if (str[i] == '7') cout << str7;
	}

	cout << '\n';
	return 0;
}
