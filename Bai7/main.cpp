#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5 + int(1e3)

int n, a[MAXN], b[MAXN], dp[MAXN][MAXN];

// 2^n
int lcsRecursion(int m, int n)
{
    if (m == -1 || n == -1)
        return 0;
    if (a[m] == b[n])
        return 1 + lcsRecursion(m - 1, n - 1);
    else
        return max(lcsRecursion(m, n - 1), lcsRecursion(m - 1, n));
}

// n^2
int lcsDP()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> a[i];

    for (size_t i = 0; i < n; i++)
        cin >> b[i];
    // cout << "output: " << lcsRecursion(n - 1, n - 1);
    cout << lcsDP();
    return 0;
}