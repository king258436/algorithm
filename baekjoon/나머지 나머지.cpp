#include<iostream>

using namespace std;
bool check[1001];

int main() {
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        check[num % 42] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (check[i]) {
            cnt++;
        }
    }
    cout << cnt;
}