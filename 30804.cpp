#include <iostream>
#include <vector>

using namespace std;

void
sol0(int n, vector<int>& t)
{
    int mx = 0;
    int l = 0;
    int r = 0;
    vector<int> dp(10);
    dp[t[l]] = 1;
    int cnt = 1;

    while (r < n)
    {
        if (cnt > 2)
        {
            dp[t[l]]--;
            if (dp[t[l]] == 0) cnt--;
            l++;
        }
        else
        {
            mx = (r - l + 1 > mx) ? r - l + 1 : mx;
            r++;
            dp[t[r]]++;
            if (dp[t[r]] == 1) cnt++;
        }
    }

    cout << mx << '\n';

    return;
}


int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> t(n + 5);
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    sol0(n, t);

    return 0;
}