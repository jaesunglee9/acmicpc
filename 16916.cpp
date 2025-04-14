// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, p;
	getline(cin, s);
	getline(cin, p);

	if (strstr((char*)s.c_str(), (char*)p.c_str()) == NULL) cout << 0 << endl;
	else cout << 1 << endl;

 
	

	return 0;
}


