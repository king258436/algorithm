#include <iostream>

using namespace std;

int a[50];
int main() {
    int n, s;
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    for (i = 0; i < n && s; i++) {
        int max = a[i];
        int max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (s - (j - i) >= 0) {
                if (max < a[j]) max = a[j], max_idx = j;  // 교환 한도내에서 오른쪽에서 가장 큰수 찾음
            } else
                break;
        }
        for (j = max_idx; j > i; j--) {
            swap(a[j], a[j - 1]);
        }
        s -= (max_idx - i);
    }
    for (i = 0; i < n; i++) cout << a[i] << ' ';
}