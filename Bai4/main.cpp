#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, s, a[N];

int FM_2pointer(int a[], int n, int s)
{
    int l = 0, r = n - 1;
    int result = 0;

    while (l < r)
    {
        if (a[l] + a[r] <= s)
        {
            result += (r - l);
            l++;
        }
        else
            r--;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    cout << FM_2pointer(a, n, s) << endl;

    return 0;
}
