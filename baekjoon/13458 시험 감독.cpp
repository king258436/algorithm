#include<iostream>

using namespace std;

int main() {
    int n;
    int arr[1000000], b, c;
    long long result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; i++) {
        if (arr[i] - b < 0) {
            result++;
            continue;
        }
        if ((arr[i] - b) % c != 0) {
            result += (arr[i] - b) / c + 2;
        } else {
            result += (arr[i] - b) / c + 1;
        }
    }
    cout << result;
}