#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;
using ll = long long;

// sol1 stuff
enum OpCode {
    OP_NUM, OP_POP, OP_INV, OP_DUP, OP_SWP, OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD
};

struct CMD
{
	OpCode op;
	int val;
};

OpCode getOpCode(const string& s) {
    if (s == "NUM") return OP_NUM;
    if (s == "POP") return OP_POP;
    if (s == "INV") return OP_INV;
    if (s == "DUP") return OP_DUP;
    if (s == "SWP") return OP_SWP;
    if (s == "ADD") return OP_ADD;
    if (s == "SUB") return OP_SUB;
    if (s == "MUL") return OP_MUL;
    if (s == "DIV") return OP_DIV;
    if (s == "MOD") return OP_MOD;
    return OP_NUM; // Should not happen based on problem description
}

// end sol1 stuff



void
sol1(vector<CMD>& pgm, vector<int>& s)
{
	bool error = false;
	for (const CMD& cmd : pgm) {
		if (cmd.op == OP_NUM)
		{
			s.push_back(cmd.val);
		}
		else if (s.empty()) // Filter 1
		{
			error = true;
		}
		else if (cmd.op == OP_POP)
		{
			s.pop_back();
		}
		else if (cmd.op == OP_INV)
		{
		        s.back() = -s.back();
		}
		else if (cmd.op == OP_DUP)
		{
			s.push_back(s.back());
		}
		else if (s.size() < 2) // Filter 2
		{
			error = true;
		}
		else if (cmd.op == OP_SWP)
		{      
		        swap(s[s.size() - 1] , s[s.size() - 2]);
		}
		else {
			ll res, a, b;
			b = s.back(); s.pop_back();
			a = s.back(); s.pop_back();
			if (cmd.op == OP_ADD) res = a + b;
			else if (cmd.op == OP_SUB) res = a - b;
			else if (cmd.op == OP_MUL) res = 1LL * a * b;
			else if (b == 0) error = true;
			else if (cmd.op == OP_DIV) res = a / b;
			else if (cmd.op == OP_MOD) res = a % b;
			else assert(false);
			
			if (!error && abs(res) > 1e9) error = true;
			else s.push_back(res);
		}
		if (error) break;
	}
	if (s.size() != 1) error = true;

	if (error) {
		cout << "ERROR" << '\n';
	}
	else {
		cout << s.back() << '\n';
	}
}



int
main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		int n;
		string str;
		vector<CMD> pgm;

		while (cin >> str)
		{
			if (str == "QUIT") return 0;
			if (str == "END") break;
			if (str == "NUM")
			{
				int x; cin >> x;
				pgm.push_back({OP_NUM, x});
			}
			else
			{
				pgm.push_back({getOpCode(str), -1});
			}

		}

		cin >> n;

		// running program for n times
		for (int i = 0; i < n; i++) {
			int v;
			vector<int> s;
			s.reserve(1005);
						
			cin >> v;
			s.push_back(v);
			sol1(pgm, s);
		}
		cout << '\n';
	}
	return 0;
}
