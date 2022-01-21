#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 30;
const long long MOD = 1e9 + 7;
int erathones[MAXN];
int n;
long long f[MAXN][100];

void setup()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            f[i][j] = -1;
        }
    }
}

long long calculateF(int a, int b)
{
    if (f[a][b] != -1)
        return f[a][b];
    if (b < 10)
    {
        f[a][b] = 0;
        return 0;
    }
    if (a == 3)
    {
        long long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            int p = b * 10 + i;
            if (erathones[p] == 1)
            {
                ans++;
            }
        }
        f[a][b] = ans;
        return ans;
    }
    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        int p = b * 10 + i;
        if (erathones[p] == 1)
        {
            ans = (ans + calculateF(a - 1, p % 100)) % MOD;
        }
    }
    f[a][b] = ans;
    return ans;
}

void setupErathones()
{
    erathones[0] = 0;
    erathones[1] = 0;
    for (int i = 2; i <= 1000; i++)
    {
        erathones[i] = true;
    }
    for (int i = 2; i <= 1000; i++)
    {
        if (erathones[i] == 1)
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                erathones[j] = 0;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    setupErathones();
    setup();
    cin >> n;
    long long ans = 0;
    for (int i = 100; i < MAXN; i++)
    {
        if (erathones[i] == 1)
        {
            long long tmp = calculateF(n - 1, i % 100);
            ans = (ans + tmp) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
