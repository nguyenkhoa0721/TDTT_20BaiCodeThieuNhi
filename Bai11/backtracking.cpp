#include <bits/stdc++.h>

#define vb vector<bool>
#define pii pair<int, int>
#define vpii vector<pii>

using namespace std;

int k, m, n, ans;
vpii data(1e3);

void split(vpii chosen_data, vb &check, int i)
{
    if (i == n)
    {
        int total = 0;
        for (int j = 0; j < m + n; ++j)
            total += (check[j] ? chosen_data[j].first : chosen_data[j].second);
        ans = max(ans, total);
        return;
    }
    for (int j = 0; j < m + n; ++j)
        if (!check[j])
        {
            check[j] = true;
            split(chosen_data, check, i + 1);
            check[j] = false;
        }
}

void backtracking(vb &visited, vpii &chosen_data, int i)
{
    if (i >= m + n)
    {
        vb check(m + n, false);
        split(chosen_data, check, 0);
        return;
    }
    for (int j = 0; j < k; ++j)
    {
        if (!visited[j])
        {
            visited[j] = true;
            chosen_data.push_back(data[j]);
            backtracking(visited, chosen_data, i + 1);
            chosen_data.pop_back();
            visited[j] = false;
        }
    }
}

int main()
{
    // space complexity: O(n)
    // time complexity: O(k^(m+n) * (m+n)^n)
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i)
        cin >> data[i].first >> data[i].second;

    ans = 0;
    vb visited(k, false);
    vpii chosen_data;
    backtracking(visited, chosen_data, 0);

    cout << ans;
    return 0;
}