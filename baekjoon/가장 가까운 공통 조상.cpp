#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[10001]={0,};
        int check[10001]={0,};
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int p, c;
            cin >> p >> c;
            arr[c] = p;
        }
        int n1, n2;
        cin >> n1 >> n2;
        while (arr[n1]) {
            int temp = arr[n1];
            check[n1] = 1;
            n1 = temp;
        }
        while (arr[n2]) {
            int temp = arr[n2];
            if (check[n2] == 1) break;
            n2 = temp;
        }
        cout << n2 << endl;
    }
}