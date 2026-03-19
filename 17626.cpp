#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void
sol0(int n)
{
	vector<int> dp(50001, 5);

	for (int i = 1; i <= 300; i++)
	{
		if (i * i <= 50000)
		{
			dp[i * i] = 1;
		}
	}

	for (int i = 1; i <= 50000; i++)
	{
	        for (int j = 1; j <= 50000; j++)
		{
			if (i + j > 50000) continue;
			
			if (dp[i] + dp[j] < dp[i + j]) dp[i + j] = dp[i] + dp[j];
		}	
	}

	for (int i = 1; i < 50000; i++) {
		if (dp[i] == 0) cout << "incorrect\n";
	}
	
        cout << dp[n] << '\n';

	return;
}

void
sol1(int n)
{
	vector<int> dp(50001, 5);

	for (int i = 1; i <= 300; i++)
	{
		if (i * i <= 50000)
		{
			dp[i * i] = 1;
		}
	}

	for (int i = 1; i <= 50000; i++)
	{
	        for (int j = 1; j * j < i; j++)
		{
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}	
	}

        cout << dp[n] << '\n';

	return;
}

void
sol2(int n)
{
	if (n == 0)
	{
		cout << 0 << '\n';
		return;
	}
	
	vector<int> v(n + 1, 0);
	queue<int> q;

	q.push(0);
	v[0] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (cur == n)
		{
			cout << v[cur] << '\n';
			return;
		}

		for (int i = 1; ; i++)
		{
			int next = cur + (i * i);
			if (next > n) break;

			if (v[next] == 0)
			{
				v[next] = v[cur] + 1;
				q.push(next);			
			}
		}
	}
}
		
	     


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	sol2(n);

	return 0;
}
