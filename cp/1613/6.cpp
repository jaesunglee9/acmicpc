#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct E {
	int l;
	int lcenter;
	int rcenter;
	int r;
	int cost; // cheapest
};


int
main(void)

{
	ios::sync_with_stdio(0);cin.tie(0);

	
	int n; cin >> n;
	vector<E> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		E e = {x, x, x, x, 0};
		a.push_back(e);
	}
	
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		a[i].cost = cost;
	}

	for (int i = 0; i < n; i++) {
		a[i].l -= 1;
		a[i].r += 1;
	}
        int idx = 0;
	int i = 1;
	while (i < n) {
		if (a[i-1].r >= a[i].lcenter) {
			
	while (1) {
		


	}




	
	return 0;
}
	

	
