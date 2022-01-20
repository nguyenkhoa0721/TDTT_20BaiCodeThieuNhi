#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
const int MAXX = 1e9;

int n, k, res = -1e9;
int a[MAXN];
int uc[MAXN][MAXN];
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                uc[i][j] = uc[i - 1][j] + 1;
                uc[i][a[i] / j] = uc[i - 1][a[i] / j] + 1;
            }
        }
    }
    for (int i = k; i <= n; i++)
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (uc[i][j] - uc[i - k + 1][j] + 1 == k && uc[i - k + 1][j] != 0)
                res = max(res, j);
            if (uc[i][a[i] / j] - uc[i - k + 1][a[i] / j] + 1 == k && uc[i - k + 1][a[i] / j] != 0)
                res = max(res, a[i] / j);
        }
    cout << res;
}
