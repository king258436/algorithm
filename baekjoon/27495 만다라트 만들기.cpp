#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
struct goal {
    string middleGoal;
    pair<int, int> p;
};

vector<string> str[3][3];
vector<goal> middleArr;

bool comp1(goal &a, goal &b) {
    return a.middleGoal < b.middleGoal;
}

int main() {
    string temp;
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> temp;
            if (i / 3 == 1 && j / 3 == 1) continue;
            if (i % 3 == 1 && j % 3 == 1) { // 중간목표는 중간목표의 세부목표 벡터의 주소와 같이저장.
                middleArr.push_back({temp, {i / 3, j / 3}});
                continue;
            }
            str[i / 3][j / 3].push_back(temp);
        }
    }

    sort(middleArr.begin(), middleArr.end(), comp1); // 중간목표 정렬.

    for (int i = 0; i < middleArr.size(); i++) {// 중간목표의 세부목표도 정렬완료.
        pair<int, int> arr = middleArr[i].p;
        sort(str[arr.first][arr.second].begin(), str[arr.first][arr.second].end());
        cout << '#' << i + 1 << ". " << middleArr[i].middleGoal << endl;
        for (int j = 0; j < str[arr.first][arr.second].size(); j++) {
            cout << '#' << i + 1 << '-' << j + 1 << ". " << str[arr.first][arr.second][j] << endl;
        }
    }

}