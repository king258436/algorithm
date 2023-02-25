#include <algorithm>
#include <iostream>
using namespace std;

struct mem {
    int ti;
    int si;
};

mem work[1001];

bool compare(const mem &a, const mem &b) {
    if (a.si > b.si)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> work[i].ti >> work[i].si;
    }

    sort(work, work + n, compare);

    int top;

    for (int i = 0; i < n; i++) {
        if (i == 0) top = work[i].si;
        if (work[i].si >= top) {
            if (top - work[i].ti >= 0)
                top = top - work[i].ti;
            else {
                cout << -1;
                return 0;
            }
        } else {
            top = work[i].si;
            if (top - work[i].ti >= 0)
                top = top - work[i].ti;
            else {
                cout << -1;
                return 0;
            }
        }
    }
    cout << top;
}
