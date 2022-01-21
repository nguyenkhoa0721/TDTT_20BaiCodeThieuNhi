#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pp pair<int, int>
pp p[1005];
int n, idx = 1e9, s;

float calP(pp x, pp y, int miny)
{
    return (y.X - x.X) * (x.Y - miny + y.Y - miny) * 0.5;
}

int above(pp k, pp x, pp y)
{
    int miny = min(min(min(x.Y, y.Y), k.Y), 0);

    if (calP(x, k, miny) + calP(k, y, miny) + calP(y, x, miny) > 0)
        return true;

    return false;
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].X >> p[i].Y;
        if (p[i].X < idx)
        {
            idx = p[i].X;
            s = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int up = 0, down = 0;
        if (p[s].X != p[i].X)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || j == s)
                    continue;
                if (above(p[j], p[s], p[i]))
                    up++;
                else
                    up--;

                if (up >= n / 2 || down >= n / 2)
                    break;
            }
            if (up == down)
            {
                cout << s + 1 << " " << i + 1;
                break;
            }
        }
    }
}
