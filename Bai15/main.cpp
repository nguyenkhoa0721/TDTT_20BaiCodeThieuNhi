#include <bits/stdc++.h>
using namespace std;
int x_1, y_1, x_2, y_2, R;
double dis, alpha;

double areaOfIntersection()
{
    alpha = 2.0 * acos(dis / (2.0 * R));
    return alpha * R * R - R * R * sin(alpha);
}
double solution()
{
    dis = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
    return dis >= 2 * R ? 2 * M_PI * R * R : 2 * M_PI * R * R - areaOfIntersection();
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> R;

    if (x_1 == x_2 && y_1 == y_2)
    {
        cout << M_PI * R * R;
    }
    else
    {
        cout << setprecision(3) << fixed << solution();
    }
    return 0;
}