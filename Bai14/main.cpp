#include <bits/stdc++.h>
#define MAXN int(1e3) + 3
#define MAX 1e6 + 3
using namespace std;
typedef pair<int, int> pii;

int n;
double X[MAXN], Y[MAXN];
pii res;

double polygonArea(int l, int r)
{
    double area = 0.0;
    int j = r;
    for (int i = l; i <= r; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
    return abs(area / 2.0);
}

pii minDiffArea(double X[], double Y[], int n)
{
    double min = 10000000;
    pii res;
    double area1;
    double area2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (i == 0 && j == n - 1)
                break;
            area1 = polygonArea(i, j);
            area2 = polygonArea(0, n - 1) - area1;
            if (abs(area1 - area2) < min)
            {
                min = abs(area1 - area2);
                res = make_pair(i, j);
            }
        }
    }

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    res = minDiffArea(X, Y, n);
    cout << res.first + 1 << " " << res.second + 1 << endl;
}