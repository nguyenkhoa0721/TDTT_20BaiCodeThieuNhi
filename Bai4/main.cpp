#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e3;
const int MAXX = 10e6;
int minn = MAXX, maxx = -MAXX;
int a[MAXN + 5], n, m;
int tmp = 0;
int chatNhiPhan(int l, int r)
{
    if (l > r)
    {
        return tmp;
    }
    int mid = (l + r) / 2;
    if (a[mid] + a[mid - 1] <= m)
    {
        tmp = (mid + 1) * (mid);
        chatNhiPhan(mid + 1, r);
    }
    else
    {
        chatNhiPhan(l, mid - 1);
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << chatNhiPhan(0, n);
}
