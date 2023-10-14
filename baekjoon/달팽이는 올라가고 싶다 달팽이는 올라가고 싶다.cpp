#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;
    v -= a;
    int sum = a - b;
    cout << 1 + (int) ceil((double) v / (double) sum);
}
