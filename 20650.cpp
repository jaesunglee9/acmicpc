// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	array<int, 7> n;

	for (int i = 0; i < 7; i++) {
		int input;
		cin >> input;
		n[i] = input;
	}

	sort(n.begin(), n.end());
	int a = n[0];
	int b = n[1];
	int abc = n[6];
	int bc = abc - a;
	int c = bc - b;
	
	cout << a << ' ' << b << ' ' << c << '\n';
		
	return 0;
}


