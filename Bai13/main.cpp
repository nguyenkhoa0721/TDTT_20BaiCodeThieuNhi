#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e9
typedef pair<int, int> pii;
typedef long long ll;
struct point
{
    int id;
    ll x;
    ll y;

    static point O;
    bool operator<(const point &rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    point(int id, ll x, ll y) : id(id), x(x), y(y) {}
    point(const point &another) : x{another.x}, y{another.y}, id{another.id} {}
    int getId() { return id; }
    static bool compareSlope(point A, point B)
    {
        double slope_a, slope_b;
        if (A.x == point::O.x)
        {
            if (A.y - point::O.y > 0)
                slope_a = DBL_MAX;
            else
                slope_a = -DBL_MAX;
        }
        else
            slope_a = (A.y - point::O.y) * 1.0 / (A.x - point::O.x);

        if (B.x == point::O.x)
        {
            if (B.y - point::O.y > 0)
                slope_b = DBL_MAX;
            else
                slope_b = -DBL_MAX;
        }
        else
            slope_b = (B.y - point::O.y) * 1.0 / (B.x - point::O.x);

        return slope_a > slope_b;
    }
};

ll location(point a, point b, point c)
{
    return (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
}

// O(n^3)
pii naive(vector<point> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int leftSide = 0;
            int rightSide = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                if (location(a[k], a[i], a[j]) > 0)
                {
                    leftSide += 1;
                }
                else
                {
                    rightSide += 1;
                }
            }

            if (leftSide == rightSide)
            {
                return make_pair(i + 1, j + 1);
            }
        }
    }
    return make_pair(-1, -1);
}
//O(n^2)
pii better(vector<point> a, int n)
{
    sort(a.begin(), a.end());
    int i = n / 2 - 1;
    for (int j = i + 1; j < n; j++)
    {
        int left_side = 0;
        int right_side = 0;
        for (int k = 0; k < n; k++)
        {
            if (k == i || k == j)
            {
                continue;
            }
            if (location(a[k], a[i], a[j]) > 0)
            {
                left_side += 1;
            }
            else
            {
                right_side += 1;
            }
        }

        if (left_side == right_side)
        {
            return make_pair(a[i].getId() + 1, a[j].getId() + 1);
        }
    }
    return make_pair(-1, -1);
}
point point::O = point(0, 0, -1);
//O(n)
pii best(vector<point> a, int n)
{
    int x, y, pos_O;
    int min_x = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        a.push_back(point(x, y, i));

        // tim O co hoanh do x nho nhat
        if (x < min_x)
        {
            min_x = x;
            pos_O = i - 1;
        }
    }

    // loai diem tree_O ra khoi mang, va tree_O tro thanh goc
    point tree_O = a[pos_O];
    if (pos_O != n - 1)
    {
        a[pos_O] = a[n - 1];
    }
    a.pop_back();
    point::O = tree_O;

    // sap xep mang theo do doc cua tree_O
    sort(a.begin(), a.end(), point::compareSlope);

    // diem trung vi tree_O2
    point tree_O2 = a[a.size() / 2];
    return make_pair(pos_O, tree_O2.getId());
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    vector<point> a;
    cin >> n;
    if (n % 2 != 0)
        cout << "-1 -1";
    else
    {
        a.clear();
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back(point(i, x, y));
        }

        //pii ans = naive();
        pii ans = better(a, n);
        //pii ans = best(a, n);
        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }
    return 0;
}