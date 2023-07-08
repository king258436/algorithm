#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


bool comp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end(), comp);
    int Max = 0;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        Max += n - i - 1;
        sum += vec[i];
        if (sum > Max) {
            cout << -1;
            return 0;
        }
    }
    if (sum != Max) {
        cout << -1;
    } else { cout << 1; }
    return 0;
}