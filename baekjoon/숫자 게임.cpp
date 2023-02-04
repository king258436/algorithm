#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[1000][5] = {
        0,
    };
    int max[1001];
    int result = 0;
    int max_val = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
        int maX = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 4; k++) {
                for (int l = k + 1; l < 5; l++) {
                    int sum = arr[i][j] + arr[i][k] + arr[i][l];
                    sum %= 10;
                    if (sum > maX) maX = sum;
                }
            }
        }
        max[i] = maX;
    }
    for (int i = 0; i < n; i++) {
        if (max[i] >= max_val) {
            max_val = max[i];
            result = i + 1;
        }
    }
    cout << result;
    return 0;
}