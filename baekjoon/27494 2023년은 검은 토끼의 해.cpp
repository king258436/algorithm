#include<string>
#include<iostream>
#include<vector>
#include<cmath>
#include<stack>

using namespace std;
int arr[10];

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 2023; i <= n; i++) {
        int temp = i;
        stack<int> st;
        st.push(2);
        st.push(0);
        st.push(2);
        st.push(3);
        while (temp) {
            if (temp % 10 == st.top())st.pop();
            temp /= 10;
            if (st.empty()) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}