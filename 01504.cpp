#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;

int N, E;
vector<vector<pair<int, int>>> AL;

int
dijk0(int src, int dst)
{
	vector<int> d(N + 1, INF);
	d[src] = 0;

	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
		> pq;

	pq.push({0, src});

	while (!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if (d[u] < du) continue;

		for (auto [v, w]: AL[u])
		{
			int tmp = du + w;
			if (tmp < d[v])
			{
				d[v] = tmp;
				pq.push({tmp, v});
			}
		}
	}

	return d[dst];
}

void
sol0(void)
{
	cin >> N >> E;
	AL.resize(N + 1);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		AL[a].push_back({b, c});
		AL[b].push_back({a, c});
	}

	int n1, n2;
	cin >> n1 >> n2;

	int s2n1 = dijk0(1, n1);
	int s2n2 = dijk0(1, n2);
	int n1n2 = dijk0(n1, n2);
	int n12d = dijk0(n1, N);
	int n22d = dijk0(n2, N);

	if (n1n2 == INF)
	{
		cout << -1;
	}
	else
	{
		bool s12d = (s2n1 == INF || n22d == INF);
		bool s21d = (s2n2 == INF || n12d == INF);

		if (s12d && s21d)
		{
			cout << -1;
		}
		else if (s12d)
		{
			int d21 = s2n2 + n1n2 + n12d;
			cout << d21 ;
		}
		else if (s21d)
		{
			int d12 = s2n1 + n1n2 + n22d;
			cout << d12;
		}
		else
		{
			int d21 = s2n2 + n1n2 + n12d;
			int d12 = s2n1 + n1n2 + n22d;

			cout << min(d12, d21);
		}
	}
	cout << '\n';

	return;
}


vector<int>
dijk1(int src)
{
	vector<int> d(N + 1, INF);
	d[src] = 0;

	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
		> pq;

	pq.push({0, src});

	while (!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if (d[u] < du) continue;

		for (auto [v, w]: AL[u])
		{
			int tmp = du + w;
			if (tmp < d[v])
			{
				d[v] = tmp;
				pq.push({tmp, v});
			}
		}
	}

	return d;
}

void
sol1(void)
{
	cin >> N >> E;
	AL.resize(N + 1);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		AL[a].push_back({b, c});
		AL[b].push_back({a, c});
	}

	int n1, n2;
	cin >> n1 >> n2;

	vector<int> d1 = dijk1(1);
	vector<int> dn1 = dijk1(n1);
	vector<int> dn2 = dijk1(n2);
	int s2n1 = d1[n1];
	int s2n2 = d1[n2];
	int n1n2 = dn1[n2];
	int n12d = dn1[N];
	int n22d = dn2[N];

	if (n1n2 == INF)
	{
		cout << -1;
	}
	else
	{
		bool s12d = (s2n1 == INF || n22d == INF);
		bool s21d = (s2n2 == INF || n12d == INF);

		if (s12d && s21d)
		{
			cout << -1;
		}
		else if (s12d)
		{
			int d21 = s2n2 + n1n2 + n12d;
			cout << d21 ;
		}
		else if (s21d)
		{
			int d12 = s2n1 + n1n2 + n22d;
			cout << d12;
		}
		else
		{
			int d21 = s2n2 + n1n2 + n12d;
			int d12 = s2n1 + n1n2 + n22d;

			cout << min(d12, d21);
		}
	}
	cout << '\n';

	return;
}
	

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol1();
	return 0;
}
