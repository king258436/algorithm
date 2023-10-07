#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int lev;
        cin >> lev;
        vec.push_back(lev);
    }
    sort(vec.begin(), vec.end(), comp);
    int skill = 0;
    int level = 0;
    if (n > 42) {
        for (int i = 0; i < 42; i++) {
            int cur = vec[i];
            if (cur >= 250) {
                skill += 5;
            } else if (cur < 250 && cur >= 200) {
                skill += 4;
            } else if (cur < 200 && cur >= 140) {
                skill += 3;
            } else if (cur < 140 && cur >= 100) {
                skill += 2;
            } else if (cur < 100 && cur >= 60) {
                skill += 1;
            }
            level += cur;
        }
    } else {
        for (int i = 0; i < n; i++) {
            int cur = vec[i];
            if (cur >= 250) {
                skill += 5;
            } else if (cur < 250 && cur >= 200) {
                skill += 4;
            } else if (cur < 200 && cur >= 140) {
                skill += 3;
            } else if (cur < 140 && cur >= 100) {
                skill += 2;
            } else if (cur < 100 && cur >= 60) {
                skill += 1;
            }
            level += cur;
        }
    }
//    for (auto a: vec) {
//        cout << a << ' ';
//    }
    cout << level << ' ' << skill;
}