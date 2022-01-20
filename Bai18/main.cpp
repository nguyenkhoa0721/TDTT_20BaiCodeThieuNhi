#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;
const int MAXX = 1e9;

int n, k, res = -MAXX;
int a[MAXN];
int uc[MAXN][MAXN];

void reverse(int idx)
{
    for (int i = 0; i <= idx / 2; i++)
    {
        swap(a[i], a[idx - i]);
    }
}

void sol(int prev, int step)
{
    bool flag = false;
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] != 1)
        {
            flag = true;
            break;
        }
    if (step > n * 2 - 2)
    {
        return;
    }
    if (flag == false)
    {
        res = min(res, step);
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (i == prev)
        {
            continue;
        }
        reverse(i);
        sol(i, step + 1);
        reverse(i);
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    res = n * 2 - 2;
    sol(-1, 0);
    cout << res;
}
