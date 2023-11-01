#include<iostream>

using namespace std;
int arr[200];// 컨베이어 벨트 내구도
int n, k;
int cnt;
int robot[100];// 현재 로보트 위치

void print_test();

void rotation() {
    int arr_last = arr[2 * n - 1];
    for (int i = 2 * n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = arr_last;
    for (int i = n - 1; i > 0; i--) {
        robot[i] = robot[i - 1];
    }
    robot[0] = 0;
    if (robot[n - 1] == 1) {
        robot[n - 1] = 0;
    }
}

void move_robot() {
    for (int i = n - 2; i >= 0; i--) {
        if (robot[i] == 1 && robot[i + 1] == 0 && arr[i + 1] > 0) {// 다음칸에 로봇이 없고 다음 컨베이어 내구도가 살아있을때
            robot[i] = 0;
            robot[i + 1] = 1;
            arr[i + 1]--;
            if (arr[i + 1] == 0) {
                cnt++;
//                print_test();
            }
        }
    }
    if (robot[n - 1]) {
        robot[n - 1] = 0;
    }
}

void make_robot() {// 로봇 생성
    if (arr[0] > 0) {
        robot[0] = 1;
        arr[0]--;
        if (arr[0] == 0) {
            cnt++;
//            print_test();
        }
    }
}

void print_test() {
    for (int i = 0; i < 2 * n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// 1. 벨트가 로봇과 함께 회전 2. 로봇 이동 3. 로봇 생성 4. 내구도 0인거 확인하고 종료 할지 결정
int main() {

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {// 내구도 입력.
        cin >> arr[i];
    }
    int day = 0;
    while (1) {
        day++;
        rotation();
        move_robot();
        make_robot();

        if (cnt >= k) break;
    }
    cout << day;
}