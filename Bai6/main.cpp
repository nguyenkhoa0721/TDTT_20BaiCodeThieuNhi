#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e6 + 60;
const int MAXN = 1e3 + 30;
int cnt1[MAXV], cnt2[MAXV], cnt3[MAXV];
int n, l, r;
pair<int, int> a[MAXN];

void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int left = a[i].first;
        int right = a[i].second;
        if (left > r || right < l || cnt3[min(right, r)] - cnt3[max(left, l) - 1] == min(right, r) - max(left, l) + 1)
        {
            ans = max(ans, right - left);
        }
    }
    cout << ans;
}

void init()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
        cnt1[x]++;
        cnt1[y + 1]--;
    }

    cnt1[0] = cnt2[0];
    for (int i = 1; i < MAXV; i++)
    {
        cnt2[i] = cnt2[i - 1] + cnt1[i];
    }

    cnt3[0] = 0;

    for (int i = 1; i < MAXV; i++)
    {
        cnt2[i] == 1 ? cnt3[i] = 0 : cnt3[i] = 1;
    }
    for (int i = 1; i < MAXV; i++)
    {
        cnt3[i] = cnt3[i - 1] + cnt3[i];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    solution();
    return 0;
}
