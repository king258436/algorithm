#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[9];
vector<int> vec;

int main() {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int right;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            right = sum - arr[i] - arr[j];
            if (right == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    vec.push_back(arr[k]);
                }
                sort(vec.begin(), vec.end());
                for (int k = 0; k < 7; k++) {
                    cout << vec[k] << '\n';
                }
                return 0;
            }
        }
    }

}