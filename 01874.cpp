#include <iostream>
#include <vector>
#include <stack>
#include <string>


using namespace std;


int
sol0(int n, vector<int>& input, vector<int>& solution)
{
	stack<int> s0, s1, s;
	for (int i = n; i >= 1; i--) {
		s0.push(i);
		s.push(input[i-1]);
	}

	while (1) {
		if (s1.empty()) {
			if (s.empty()) {
				return 0;
			}

			if (!s0.empty()) {
				if (s0.top() > s.top()) {
					return -1;
				}
				else {
					s1.push(s0.top());
					s0.pop();
					solution.push_back('+');
				}
			}
		}

		if (s1.top() < s.top()) {
			if (s0.top() > s.top()) {
				return -1;
			}
			else {
				s1.push(s0.top());
				s0.pop();
				solution.push_back('+');
			}
		}
		else if (s1.top() == s.top()) {
			s1.pop();
			s.pop();
			solution.push_back('-');
		} 
		else {
			return -1;
		}
	}

      
}

string
sol1(int n, vector<int>& input)
{
	int now = 1;
	bool flag = true;
	stack<int> st;
	string sol;

	for (int i = 0; i < n; i++) {
		while (now <= input[i]) {
			st.push(now);
			sol.append("+\n");
			now += 1;
		}
		if (st.top() == input[i]) {
			st.pop();
			sol.append("-\n");
		} else flag = false;
	}
	
	if (!flag) sol = "NO\n";
    
	return sol;
}


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<int> a;
	vector<char> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		a.push_back(t);
	}
	
	cout << sol1(n, a);

	return 0;
}
