#include <iostream>
#include <stack>

using namespace std;

int arr[500001];
int score[500001];

int main() {
    int n;
    stack<pair<int, int> > st;
    cin >> n;
    cin >> arr[0];
    st.push(make_pair(arr[0], 0));
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (st.top().first < arr[i]) {
            while (!st.empty()) {
                if (st.top().first < arr[i])
                    st.pop();
                else
                    break;
            }
        }
        if (!st.empty()) {
            if (st.top().first > arr[i]) {
                score[i] = st.top().second + 1;
                st.push(make_pair(arr[i], i));
            } else
                st.push(make_pair(arr[i], i));
        }
        st.push(make_pair(arr[i], i));
    }
    for (int i = 0; i < n; i++) {
        cout << score[i] << ' ';
    }
}
