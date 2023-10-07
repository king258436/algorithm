#include<iostream>

using namespace std;
using ll = long long;

ll multi(ll a, ll b, ll c) {

    if (b == 1) {
        return a % c;
    }
    ll temp = multi(a, b / 2, c) % c;
    if (b % 2 == 0) {
        return temp * temp % c;
    } else {
        return temp * temp % c * a % c;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << multi(a, b, c);
}