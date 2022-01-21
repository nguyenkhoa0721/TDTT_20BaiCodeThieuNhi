#include <iostream>
#include <cmath>
using namespace std;

struct Pair
{
    int x1;
    int x2;
};

// (X[i], Y[i]) are coordinates of i'th point.
double polygonArea(double X[], double Y[], int l, int r)
{

    double area = 0.0;

    //tinh dien tich theo cong thuc shoelace
    int j = r;
    for (int i = l; i <= r; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; // j bang dinh truoc do cua i
    }

    return abs(area / 2.0);
}

Pair minDiffArea(double X[], double Y[], int n)
{
    double min = 10000000;
    Pair res;
    double area1;
    double area2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (i == 0 && j == n - 1)
                break;
            area1 = polygonArea(X, Y, i, j);
            area2 = polygonArea(X, Y, 0, n - 1) - area1;
            if (abs(area1 - area2) < min)
            {
                min = abs(area1 - area2);
                res.x1 = i;
                res.x2 = j;
                //cout << i <<" "<< j << " "<< area1 <<" "<< area2 <<endl ;
            }
        }
    }

    return res;
}

// Driver program to test above function
int main()
{
    int n;
    double X[1000];
    double Y[1000];
    Pair res;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    res = minDiffArea(X, Y, n);
    cout << res.x1 << " " << res.x2 << endl;
}