#include <bits/stdc++.h>
using namespace std;

double areaOfIntersection(int &x1, int &y1, int &x2, int &y2, int &R, int sqrDistance)
{
    double distance = sqrt(sqrDistance);
    if (distance >= 2 * R)
    {
        return 0;
    }
    else
    {
        double cosHalfAlpha = distance / (2 * R);
        double Alpha = 2 * acos(cosHalfAlpha);
        return Alpha * R * R - R * sin(Alpha);
    }
}
double areaOfUnion(int &x1, int &y1, int &x2, int &y2, int &R)
{
    int sqrDistance;
    sqrDistance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double intersectionArea = areaOfIntersection(x1, y1, x2, y2, R, sqrDistance);
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

    // overlap with R1 = R2 = R
    if (x1 == x2 && y1 == y2)
    {
        cout << M_PI * R * R;
    }
    else
    {
        double unionArea = areaOfUnion(x1, y1, x2, y2, R);
        double result = round(unionArea * 1000.0) / 1000.0;
        printf("%.3f", result);
    }
    return 1;
}