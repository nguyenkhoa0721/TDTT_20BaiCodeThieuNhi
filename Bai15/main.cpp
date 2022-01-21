#include <bits/stdc++.h>
using namespace std;
int x1, y1, x2, y2, R;
double dis, alpha;

double areaOfIntersection()
{
    alpha = 2 * acos(dis / (2 * R));
    return alpha * R * R - R * R * sin(alpha);
}
double solution()
{
    int dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return dis >= 2 * R ? 0 : 2 * M_PI * R * R - areaOfIntersection();
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2 >> R;

    if (x1 == x2 && y1 == y2)
    {
        cout << M_PI * R * R;
    }
    else
    {
        cout << setprecision(3) << fixed << solution();
    }
    return 0;
}