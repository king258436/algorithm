#include <cmath>
#include <iostream>

using namespace std;
int n;

int IsPrime(int a) {
    for (int i = 2; i <= (int)sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int first = n / 2;
        int second = n / 2;
        while (!IsPrime(first) || !IsPrime(second)) {
            first--;
            second++;
        }
        cout << first << ' ' << second << '\n';
    }
}