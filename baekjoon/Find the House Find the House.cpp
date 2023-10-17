#include<iostream>
#include<vector>

#define ZERO 1000005
using namespace std;
struct Info {
    char dir;
    int end;
};

int main() {
    int n;
    cin >> n;
    vector<Info> vec(2000010);//백만5가 0이다.
    for (int i = 0; i < n; i++) {
        int start, end;
        char dir;
        cin >> start >> dir >> end;

        vec[start + ZERO].dir = dir;
        vec[start + ZERO].end = end;
    }
    int start;
    cin >> start;
    start += ZERO;
    while (n--) {
        int next;
        if (vec[start].dir == 'R') {
            next = start + vec[start].end;
        } else {
            next = start - vec[start].end;
        }
        start = next;
//        cout << start << '\n';
    }
    cout << start - ZERO;
}