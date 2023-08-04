#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> st;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        char cur = str[i];
        if (cur >= 'A' && cur <= 'Z') {
            cout << cur;
        } else {
            if (cur == ')') {
                while (st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();// ')'는 삭제 해줘야함.
            } else if (cur == '(') {
                st.push(cur);
            } else if (cur == '+' || cur == '-') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(cur);
            } else if (cur == '*' || cur == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(cur);
            }
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

}