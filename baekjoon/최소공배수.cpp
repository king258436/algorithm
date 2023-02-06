#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b) {
    long long int temp;
    long long int c;
    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    long long int a, b, g, result;
    cin >> a >> b;
    g = gcd(a, b);
    result = (a * b)/g;
    cout << result;
}