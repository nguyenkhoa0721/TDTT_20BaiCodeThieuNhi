#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200 + 10
int n;
int M;
int a[MAXN], prefixSum[MAXN];
ll dp[MAXN][MAXN];

ll sum(int i, int j)
{
    return (prefixSum[j]-prefixSum[i]) % M;
}

ll solve(int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = LLONG_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k + 1, j) + sum(i, k) * sum(k + 1, j));
    }
    return dp[i][j];
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> M;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    prefixSum[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    cout << solve(0, n - 1);
    return 0;
}