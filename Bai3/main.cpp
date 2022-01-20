#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;

int n, m, k, c;
int a[MAXN + 5];
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[c++] = i * i + j * j;
    sort(a, a + c);
    cout << a[k - 1];
}
