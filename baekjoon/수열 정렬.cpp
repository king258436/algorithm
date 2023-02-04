#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _ELEMENT {
    int idx;
    int num;
} element;

bool compare1(const element &e1, const element &e2) {
    if (e2.num != e1.num) return e2.num > e1.num ;
    else return e2.idx > e1.idx;
}

bool compare2(const element &e1, const element &e2) { return e2.idx > e1.idx; }

int main() {
    element arr[50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].num;
        arr[i].idx = i;
    }
    sort(arr, arr + n, compare1);
    for (int i = 0; i < n; i++) {
        arr[i].num = i;
    }
    sort(arr, arr + n, compare2);
    for (int i = 0; i < n; i++) {
        cout << arr[i].num << " ";
    }
}