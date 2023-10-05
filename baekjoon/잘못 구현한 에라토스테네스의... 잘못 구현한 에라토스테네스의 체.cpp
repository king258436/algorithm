#include<iostream>

typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum = n;
    for (ll i = 2; i < n; i++) {
        ll cur = 1 + (n - 1) / i;
        ll next = (n - 1) / ((n - 1) / i);
        sum += (next - i + 1) * cur;
        i = next;
    }
    if (n != 1) sum++;
    cout << sum;
}