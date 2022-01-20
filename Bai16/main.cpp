#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec(1005);
int n, x, y;
int dp[1005];
bool visited[1005];

void dfs(int u)
{
    if (vec[u].size() < 1 && u != 1)
    {
        dp[u] = 1;
        visited[u] = true;
        return;
    }
    for (int i = 0; i < vec[u].size(); i++)
    {
        int v = vec[u][i];
        if (visited[v] == false)
        {
            visited[v] = true;
            dfs(v);
            dp[u] += dp[v];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    visited[1] == true;
    dfs(1);
}
