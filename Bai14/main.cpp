
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000 + 3
#define MAX 1e9 + 3
typedef pair<int, int> pii;
typedef vector<pii> vpii;
float CalculateConvexPolygonArea(vpii polygon)
{
    int n = polygon.size() - 1;
    float result = (polygon[n].first * polygon[0].first) - (polygon[n].second * polygon[0].first);
    for (int i = 0; i < n; i++)
    {
        result += (polygon[i].first * polygon[i + 1].second) - (polygon[i].second * polygon[i + 1].first);
    }
    return abs(result) / 2;
}
float CalculateDifferenceOf2Polygons(vpii polygon, int i, int j)
{
    vpii pol1;
    for (int k = i; k <= j; k++)
    {
        pol1.push_back(polygon[k]);
    }
    vpii pol2;
    for (int k = j; k < polygon.size(); k++)
    {
        pol2.push_back(polygon[k]);
    }
    for (int k = 0; k <= i; k++)
    {
        pol2.push_back(polygon[k]);
    }
    float area1 = CalculateConvexPolygonArea(pol1);
    float area2 = CalculateConvexPolygonArea(pol2);
    return abs(area1 - area2);
}
pii solution(vpii polygon)
{
    float min = MAX;
    float diff_ = min;
    pii result = make_pair(0, 0);
    float index_left, index_right;
    int n = polygon.size() - 1;
    int right;

    for (int i = 0; i < n; i++)
    {
        int mid = (n - i) / 2 + i + 1;
        float diff = CalculateDifferenceOf2Polygons(polygon, i, mid);
        if (diff < min)
        {
            min = diff;
            result = {i, mid};
        }
        right = 1;
        index_right = (mid + right) % (n + 1);
        while (diff_ < min && index_right <= i - 2)
        {
            right++;
            index_right = (mid + right) % (n + 1);
            diff_ = CalculateDifferenceOf2Polygons(polygon, i, index_right);

            if (diff_ > min)
                break;

            if (diff_ < min)
            {
                min = diff_;
                result = {i, index_right};
            }
        }
        index_left = mid;
        while (diff_ < min && index_left >= i + 2)
        {
            index_left++;
            diff_ = CalculateDifferenceOf2Polygons(polygon, i, index_left);
            if (diff_ > min)
                break;
            if (diff_ < min)
            {
                min = diff_;
                result = {i, index_left};
            }
        }
    }
    result.first++;
    result.second++;
    return result;
}
int main()
{
    int n;
    vpii polygon;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        polygon.push_back(make_pair(a, b));
    }
    pii result = solution(polygon);
    cout << result.first << " " << result.second;
    return 0;
}