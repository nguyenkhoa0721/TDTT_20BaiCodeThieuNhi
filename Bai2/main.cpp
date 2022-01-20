#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e3;
#define ll long long
int n;
int c;
int res;
bool isPrime[MAX + 5];
int prime[MAX + 5];

void sieve(int N)
{
    bool isPrime[N + 1];
    for (int i = 0; i <= N; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 0; i <= N; i++)
    {
        if (isPrime[i])
        {
            prime[c++] = i;
        }
    }
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n;
    sieve(2*n);
    for (int i = 0; i < c; i++)
        for (int j = i; j < c; j++)
        {
            int sum = prime[i] + prime[j];
            if (sum % 2 == 0)
            {
                if (sum <= 2 * n)
                    res++;
                else
                    break;
            }
        }
    cout << res;
}