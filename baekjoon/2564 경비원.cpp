#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> shop;
int n, m, cnt;

int trans_straight(int dir, int dis) {
    int res;
    if (dir == 3) {
        res = dis;
    } else if (dir == 2) {
        res = n + dis;
    } else if (dir == 4) {
        res = n * 2 + m - dis;
    } else {//dir==1
        res = n * 2 + m * 2 - dis;
    }
    return res;
}

int dis_from_dong(int shop1, int dong) {
    int res = min(abs(dong - shop1), m * 2 + n * 2 - abs(dong - shop1));
    return res;
}

int main() {
    cin >> m >> n;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int dir, dis;
        cin >> dir >> dis;
        int point = trans_straight(dir, dis);
        shop.push_back(point);
    }
    int dong_dir, dong_dis, dong_point;
    cin >> dong_dir >> dong_dis;
    dong_point = trans_straight(dong_dir, dong_dis);
    int sum = 0;
    for (auto shop1: shop) {
        sum += dis_from_dong(shop1, dong_point);
    }
    cout << sum;

}