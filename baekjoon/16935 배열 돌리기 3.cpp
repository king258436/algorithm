#include<iostream>

using namespace std;
int n, m, r;

void change(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void change_nm() {
    int t = n;
    n = m;
    m = t;
}

void one(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = arr[n - i - 1][j];
        }
    }
}

void two(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = arr[i][m - j - 1];
        }
    }
}

void three(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][n - 1 - i] = arr[i][j];
        }
    }
    change_nm();
}

void four(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[m - j - 1][i] = arr[i][j];
        }
    }
    change_nm();
}

void five(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i][j + m / 2] = arr[i][j];
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i + n / 2][j] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i][j - m / 2] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i - n / 2][j] = arr[i][j];
        }
    }
}

void six(int arr[100][100], int temp[100][100]) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i + n / 2][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i][j - m / 2] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i - n / 2][j] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i][j + m / 2] = arr[i][j];
        }
    }
}


int main() {
    int arr[100][100] = {0,};
    int temp[100][100] = {0,};
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            one(arr, temp);
            change(arr, temp);
        } else if (a == 2) {
            two(arr, temp);
            change(arr, temp);
        } else if (a == 3) {
            three(arr, temp);
            change(arr, temp);
        } else if (a == 4) {
            four(arr, temp);
            change(arr, temp);
        } else if (a == 5) {
            five(arr, temp);
            change(arr, temp);
        } else if (a == 6) {
            six(arr, temp);
            change(arr, temp);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}