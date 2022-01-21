#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double areaOfIntersection(int &x1, int &y1, int &x2, int &y2, int &R, int dis)
{
    double cosHalfAlpha = dis / (2 * R);
    double Alpha = 2 * acos(cosHalfAlpha);
    return Alpha * R * R - R * R * sin(Alpha);
}
double areaOfUnion(int &x1, int &y1, int &x2, int &y2, int &R)
{
    int dis;
    dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (dis >= 2 * R)
    {
        return 0;
    }
    double intersectionArea = areaOfIntersection(x1, y1, x2, y2, R, dis);
    return 2 * M_PI * R * R - intersectionArea;
}
double round(double val)
{
    if (val < 0)
        return ceil(val - 0.5);
    return floor(val + 0.5);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int x1, y1, x2, y2;
    int R;
    cin >> x1 >> y1 >> x2 >> y2 >> R;

    if (x1 == x2 && y1 == y2)
    {
        cout << M_PI * R * R;
    }
    else
    {
        // double unionArea = areaOfUnion(x1, y1, x2, y2, R);
        // double result = round(unionArea * 1000.0) / 1000.0;
        cout << setprecision(3) << fixed << areaOfUnion(x1, y1, x2, y2, R);
    }
    return 1;
}