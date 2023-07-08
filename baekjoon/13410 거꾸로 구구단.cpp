#include<iostream>
#include<cmath>

using namespace std;

//몇자리 수인지 리턴
int digits(int a) {
    int n = 0;
    while (a) {
        a /= 10;
        n++;
    }
    return n;
}

int rs(int a) {
    int n = digits(a);
    int sum = 0;
    while (a) {
        sum += (a % 10) * pow(10, n - 1);
        a /= 10;
        n--;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    int MAX = 0;
    for (int i = 1; i <= k; i++) {
        int sum = rs(i * n);
        if (MAX < sum)MAX = sum;
    }
    cout << MAX;
}