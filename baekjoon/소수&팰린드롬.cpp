#include <cmath>
#include <iostream>
#include <string>

using namespace std;
bool arr[10000000];
char pal[10];

void eratos1() {
    int number = 10000000;
    for (int i = 2; i <= number; i++) {
        if (arr[i] == true) continue;
        for (int j = i * 2; j <= number; j += i) {
            arr[j] = true;
        }
    }
}

bool Isitpal(int n) {
    string str = to_string(n);
    bool flag = false;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    arr[1] = true;
    eratos1();  // 짝수인거 전부다 1처리
    while (1) {
        if (arr[n] == false) {  // 인덱스 살아있는거임
            if (Isitpal(n)) {
                cout << n;
                return 0;
            }
        }
        n++;
    }
}