#include <iostream>
using namespace std;

void star(int n, int i, int j) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << ' ';
    } else {
        if (n / 3 == 0)
            cout << '*';
        else
            star(n / 3, i, j);
    }
}

int main() {
    int i, j;
    int n;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            star(n, i, j);
        }
        cout << '\n';
    }
}