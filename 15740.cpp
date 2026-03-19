// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

// a >= b
bool comp(const string& a,const string& b) {
	if (a.size() != b.size()) {
		return a.size() > b.size();
	}
        return a >= b;
}

string add(const string& a, const string& b) {
	string res;
	int carry = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;

	while ( i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) {
			sum += a[i]- '0';
			i--;
		}
		if (j >= 0) {
			sum += b[j] - '0';
			j--;
		}

		res += (sum % 10) + '0';
		carry = sum / 10;
	}

	reverse(res.begin(), res.end());

	return res;
}

string sub(const string& a, const string& b) {
	string res;
	int borrow = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 || j >= 0) {
		int diff = 0;
		if (i >= 0) {
			diff += a[i] - '0';
			i--;
		}
		if (j >= 0) {
			diff -= b[j] - '0';
			j--;
		}
		diff -= borrow;
		borrow = 0;
		if (diff < 0) {
			diff += 10;
			borrow += 1;
		}
		res += diff + '0';
	}
	reverse(res.begin(), res.end());
	while ( res.size() > 1 && res[0] == '0') {
		res.erase(res.begin());
	}
	return res;
}
	



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	// determine the sign
	char as = '\0';
	char bs = '\0';
	if (a[0] == '-'){
		as = a[0];
		a.erase(a.begin());
	}
	
	if (b[0] == '-'){
		bs = b[0];
		b.erase(b.begin());
	}

	if (as == bs) {
		string res = add(a,b);
		if (as == '-' && res != "0") {
			cout << as;
		}
		cout << res << '\n';
	} else {
		if (comp (a, b)) { // a >= b
			string res = sub(a, b);
			if (as == '-' && res != "0") {
				cout << as;
			}
			
			cout << res << '\n';
		} else {
			string res = sub(b,a);
			if (bs == '-'&& res != "0") {
				cout << bs;
			}
			
			cout << res  << '\n';
		}
	}
       
	return 0;
}


