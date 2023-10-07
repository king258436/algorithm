#include<iostream>

#define MOD 1000000007
using namespace std;
using ll = long long;

ll conquer(int n, int mod) {
    if (mod == 1) {
        return n % MOD;
    }
    ll temp = conquer(n, mod / 2);
    if (mod % 2) {//홀 수일때
        return temp * temp % MOD * n % MOD;
    } else {
        return temp * temp % MOD;
    }
}

ll gcd(int a, int b) {
    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    int n;
    while (b) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ll n, s;
        cin >> n >> s;
        ll p = gcd(n, s);
        n /= p;
        s /= p;
        ans += s * conquer(n, MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans;
}