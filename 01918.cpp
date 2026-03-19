#include <iostream>
#include <vector>
#include <string>

using namespace std;

string
parse(string exp, int idx)
{
	string ret = "";
	
	if (idx == '(')
	{
		return parse(exp, idx + 1);
	}

	if (

void
sol0(string exp)
{
	int n = exp.size();

	cout << parse(exp, 0);

	return;
}


int
main(void)
{
	string exp;	

	cin >> exp;

	sol0(exp, n);
	return 0;
}
