#include<iostream>
#include<vector>

using namespace std;
vector<int> num, op;
int Max = -1e9;
int Min = 1e9;
int n;

void recursive(int depth, int sum) {
    if (depth == n) {
        if (sum > Max) Max = sum;
        if (sum < Min) Min = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if (i == 0) {
                recursive(depth + 1, sum + num[depth]);
            } else if (i == 1) {
                recursive(depth + 1, sum - num[depth]);
            } else if (i == 2) {
                recursive(depth + 1, sum * num[depth]);
            } else {
                recursive(depth + 1, sum / num[depth]);
            }
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        num.push_back(number);
    }
    for (int i = 0; i < 4; i++) {
        int oper;
        cin >> oper;
        op.push_back(oper);
    }
    recursive(1, num[0]);
    cout << Max << "\n" << Min;
}