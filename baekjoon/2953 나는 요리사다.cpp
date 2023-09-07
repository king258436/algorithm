#include<iostream>

using namespace std;
int arr[5][4];
int max_num;
int max_idx;

int main() {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        if (max_num < sum) {
            max_num = sum;
            max_idx = i + 1;
        }
    }
    cout << max_idx << ' ' << max_num;
}