#include<iostream>
#include<cmath>
#include<vector>
#include<stdio.h>

using namespace std;
int n;
vector<pair<double, double>> vec;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
    double ret = 0;
    ret += x1 * y2 + x2 * y3 + x3 * y1;
    ret += (-x2 * y1 - x3 * y2 - x1 * y3);
    return ret / 2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    double result = 0;
    for (int i = 1; i < n - 1; i++) {
        result += ccw(vec[0].first, vec[i].first, vec[i + 1].first, vec[0].second, vec[i].second, vec[i + 1].second);
    }
    printf("%0.1lf", abs(result));
}