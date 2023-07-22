#include<iostream>
#include<cstring>
using namespace std;
int arr[100][100];
int check[100][100];
int temp[100][100];

int main() {
    int n, l;
    int result = 0;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {//가로
        for (int j = 0; j < n - 1; j++) {
            bool flag = 0;
            if (arr[i][j] + 1 == arr[i][j + 1]) {// 한칸앞이 현재보다 1더 큼
                if (j - l + 1 < 0 || check[i][j] == -1) {
                    break;
                }
                for (int k = j - l + 1; k <= j; k++) {
                    if (arr[i][j] != arr[i][k]) {
                        flag = 1;
                        break;
                    }
                    if (check[i][k] != check[i][j]) {
                        flag = 1;
                        break;
                    }
                    check[i][k] = 1;
                }
                if (flag) {
                    break;
                }
                if (j == n - 2) {
                    result++;
                }
            } else if (arr[i][j] == arr[i][j + 1] + 1) {// 한칸앞이 현재보다 1더 작음
                if (j + l >= n || check[i][j] == 1) {
                    break;
                }
                for (int k = j + 1; k <= j + l; k++) {
                    if (arr[i][j + l] != arr[i][k]) {
                        flag = 1;
                        break;
                    }
                    if (check[i][k] != check[i][j + l]) {
                        flag = 1;
                        break;
                    }
                    check[i][k] = -1;
                }
                if (flag) {
                    break;
                }
                if (j == n - 2) {
                    result++;
                }
            } else if (arr[i][j] == arr[i][j + 1]) {
                if (j == n - 2) {
                    result++;
//                    cout << i << '\n';
                    continue;
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {//세로
        for (int j = 0; j < n - 1; j++) {
            bool flag = 0;
            if (temp[i][j] + 1 == temp[i][j + 1]) {// 한칸앞이 현재보다 1더 큼
                if (j - l + 1 < 0 || check[i][j] == -1) {
                    break;
                }
                for (int k = j - l + 1; k <= j; k++) {
                    if (temp[i][j] != temp[i][k]) {
                        flag = 1;
                        break;
                    }
                    if (check[i][k] != check[i][j]) {
                        flag = 1;
                        break;
                    }
                    check[i][k] = 1;
                }
                if (flag) {
                    break;
                }
                if (j == n - 2) {
                    result++;
                }
            } else if (temp[i][j] == temp[i][j + 1] + 1) {// 한칸앞이 현재보다 1더 작음
                if (j + l >= n || check[i][j] == 1) {
                    break;
                }
                for (int k = j + 1; k <= j + l; k++) {
                    if (temp[i][j + l] != temp[i][k]) {
                        flag = 1;
                        break;
                    }
                    if (check[i][k] != check[i][j + l]) {
                        flag = 1;
                        break;
                    }
                    check[i][k] = -1;
                }
                if (flag) {
                    break;
                }
                if (j == n - 2) {
                    result++;
                }
            } else if (temp[i][j] == temp[i][j + 1]) {
                if (j == n - 2) {
                    result++;
//                    cout << i << '\n';
                    continue;
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }
    cout << result << '\n';

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << check[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}