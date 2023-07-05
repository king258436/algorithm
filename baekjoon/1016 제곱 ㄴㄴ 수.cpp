#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000000];

int main() {
    long long Min, Max;
    cin >> Min >> Max;
    int cnt = 0;
    for (long long i = 2; i * i <= Max; i++) {
        long long n = Min / (i * i);
        if (Min % (i * i)) n++;
        while (n * i * i <= Max) {
            if (!arr[n * i * i - Min]) cnt++;
            arr[n * i * i - Min] = 1;
            n++;
        }
    }
    cout << Max - Min - cnt + 1;
}
