#include<iostream>
#include<algorithm>

using namespace std;
struct flower {
    int s;
    int e;
};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
flower flowers[100001];
int n;

int mtod(int m, int d) {// *월 *일 을 **일로 바꿔주는 함수
    int day = 0;
    for (int i = 0; i < m; i++) {
        day += month[i];
    }
    day += d;
    return day;
}

bool comp1(flower f1, flower f2) { //꽃이 핀 날을 기준으로 오름차순정렬 (같다면 꽃이 지는 날을 기준으로 오름차순)
    if (f1.s == f2.s) return f1.e < f2.e;
    return f1.s < f2.s;
}

bool comp2(flower f1, flower f2) {// 꽃이 지는날을 기준으로 내림차순
    return f1.e > f2.e;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sM, sD, eM, eD;
        cin >> sM >> sD >> eM >> eD;
        flowers[i] = {mtod(sM, sD), mtod(eM, eD)};
    }
    sort(flowers, flowers + n, comp2);
    if (flowers[0].e < mtod(12, 1)) {
        cout << 0;
        return 0;
    }
    sort(flowers, flowers + n, comp1);
    if (flowers[0].s > mtod(3, 1)) {
        cout << 0;
        return 0;
    }

    int cur = 0;
    for (int i = 1; i < n; i++) {
        flower f = flowers[i];
        if (f.s <= mtod(3, 1)) {
            if (f.e > flowers[cur].e) cur = i;
        }
    }
    int ans = 1;
    while (true) {
        if (flowers[cur].e > mtod(11, 30)) break;

        flower l = {1, flowers[cur].e};
        int l_idx = -1;
        for (int i = cur + 1; i < n; i++) {
            flower f = flowers[i];
            if (flowers[cur].e >= f.s) {
                if (f.e > l.e) {
                    l = f;
                    l_idx = i;
                }
            }
        }
        cur = l_idx;

        if (l.s == 1) {
            cout << 0;
            return 0;
        } else ans++;
    }
    cout << ans;

}
