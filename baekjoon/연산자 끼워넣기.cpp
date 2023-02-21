#include <algorithm>
#include <iostream>
using namespace std;

int cal[4];
int arr[11];
int min_val = 99999999;
int max_val=-9999999;
int n;

void combi(int sum, int cnt) {
    if (cnt == n) {
        if (max_val < sum) max_val = sum;
        if (min_val > sum) min_val = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (cal[i] > 0) {
            cal[i]--;
            if (i == 0) {
                combi(sum + arr[cnt], cnt + 1);
            } 
            else if (i == 1) {
                combi(sum - arr[cnt], cnt + 1);
            } 
            else if (i == 2) {
                combi(sum * arr[cnt], cnt + 1);
            } 
            else
                combi(sum / arr[cnt], cnt + 1);
            cal[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> cal[i];
    }
    combi(arr[0], 1);
    cout << max_val << '\n' << min_val;
}
