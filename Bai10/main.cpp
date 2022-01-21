#include <bits/stdc++.h>

#define MAX (1e6 + 2)
#define pii pair<int, int>

using namespace std;

vector<int> cnt_layer(MAX, 0);

struct Segment
{
    int a, b, id;
};

bool compare(Segment x, Segment y)
{
    return x.a < y.a;
}

struct compare_pii
{
    bool operator()(pii const &x, pii const &y)
    {
        return (x.first > y.first) || (x.first == y.first && x.second > y.second);
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, max_layer = 0;
    cin >> n;
    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i)
    {
        segments[i].id = i;
        cin >> segments[i].a >> segments[i].b;
        ++cnt_layer[segments[i].a];
        --cnt_layer[segments[i].b + 1];
    }

    for (int i = 1; i < MAX; ++i)
    {
        cnt_layer[i] += cnt_layer[i - 1];
        max_layer = max(max_layer, cnt_layer[i]);
    }

    cout << max_layer << endl;

    sort(segments.begin(), segments.end(), compare);
    vector<int> color(n);
    priority_queue<pii, vector<pii>, compare_pii> pq;

    for (int i = 0; i < max_layer; ++i)
        pq.push(pii(0, i + 1));

    for (int i = 0; i < n; ++i)
    {
        pii end_point = pq.top();
        pq.pop();
        color[segments[i].id] = end_point.second;
        pq.push(pii(segments[i].b, end_point.second));
    }

    for (int i = 0; i < n; ++i)
        cout << color[i] << " ";
    return 0;
}