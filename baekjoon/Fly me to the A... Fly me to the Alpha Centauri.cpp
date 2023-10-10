#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll d = y - x;
        ll rd = (ll) sqrt(d);
        ll dd = d - (ll) pow(rd, 2);
        ll cnt = rd * 2 - 1;
        cnt = cnt + (ll) ceil((double) dd / (double) rd);
        cout << cnt << '\n';
    }
}