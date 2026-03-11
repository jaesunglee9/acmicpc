#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
const int INF = 1e9 + 7;

enum OpCode { OP_PUSH, OP_POP, OP_SIZE, OP_EMPTY, OP_TOP };

OpCode
getOpCode(const string& str)
{
	if (str == "push") return  OP_PUSH;
	if (str == "pop") return OP_POP;
	if (str == "size") return OP_SIZE;
	if (str == "empty") return OP_EMPTY;
	if (str == "top") return OP_TOP;
	return OP_TOP;
}

void
sol0(vector<pair<OpCode, int>>& pgm, int n)
{
	vector<int> s;
	
	for (auto [op, val]: pgm)
	{
		if(op == OP_PUSH) s.push_back(val);
		else if (op == OP_POP) {
			cout << (s.empty() ? -1 : s.back()) << '\n';
			if (!s.empty()) { s.pop_back(); }
		}
		else if (op == OP_SIZE) { cout << s.size() << '\n'; }
		else if (op == OP_EMPTY) { cout << (s.empty() ? 1 : 0) << '\n'; }
		else if (op == OP_TOP) { cout << (s.empty() ? -1 : s.back()) << '\n'; }
	}

	return;
}

	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<OpCode, int>> pgm;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;  // command
		if (str == "push") {
			int e; cin >> e;
			pgm.push_back({OP_PUSH, e});
		}
		else
		{
			pgm.push_back({getOpCode(str), 0});
		}
	}

	sol0(pgm, n);
			
	return 0;
}


