#include <bits/stdc++.h>
using namespace std;

const int MAXN = 9;
const int MAXX = 111111112;
bool a[MAXN];
bool o[MAXN];
int n, res = MAXX;

int arrToInt()
{
    int res = 0;
    for (int i = MAXN - 1; i >= 0; i--)
    {
        res += a[i];
        if (i == 0)
            return res;
        res *= 10;
    }
}
void sol(int k)
{
    if (k == MAXN)
    {
        int tmp = arrToInt();
        if (tmp % n == 0 && tmp != 0)
        {
            if (tmp < res)
            {
                res = tmp;
                for (int i = 0; i < MAXN; i++)
                    o[i] = a[i];
            }
        }
        return;
    }
    sol(k + 1);
    a[k + 1] = true;
    sol(k + 1);
    a[k + 1] = false;
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n;

    sol(-1);

    if (res == MAXX)
        res = 0;

    bool flag = false;
    for (int i = MAXN - 1; i >= 0; i--)
    {
        if (flag == false && o[i] != 0)
            flag = true;
        if (flag == true)
            cout << o[i];
    }
}