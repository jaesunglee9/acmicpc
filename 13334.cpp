#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void
sol0(int n, int d, vector<pair<int, int>>& l)
{
    vector<pair<int, int>> vl;  // valid interval lists
    for (int i = 0; i < n; i++)
    {
        if (l[i].second - l[i].first > d) continue;
        vl.push_back(l[i]);
    }

    sort(vl.begin(), vl.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
    {
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;

    int mx = 0;
    for (int i = 0; i < vl.size(); i++)
    {
        auto [h, o] = vl[i];
        int s = o - d;
        pq.push(h);
        while(!pq.empty() && pq.top() < s)
        {
            pq.pop();
        }
        mx = (pq.size() > mx) ? pq.size() : mx;
    }

    cout << mx << '\n';
    return;
}

int
main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, d;
    vector<pair<int, int>> l;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int h, o; 
        
        cin >> h >> o;
        if (h > o) swap(h, o);
        l.emplace_back(h, o);
    }
    cin >> d;

    sol0(n, d, l);
    return 0;
}