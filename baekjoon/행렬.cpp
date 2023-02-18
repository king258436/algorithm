#include <iostream>

using namespace std;

char a[50][50], b[50][50];

int main() {
    int n, m;
    int i, j;
    int cnt = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    if (n < 3 || m < 3) {
        int flag=1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if(a[i][j]!= b[i][j]) flag=0;
            }
        }
        if(flag==0) cout<<-1;
        else cout<<0;
        return 0;
    } 
    else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (a[i][j] != b[i][j]) {
                    if (m - j >= 3 && n - i >= 3) {
                        for (int k = i; k < i + 3; k++) {
                            for (int l = j; l < j + 3; l++) {
                                if (a[k][l] == '0')
                                    a[k][l] = '1';
                                else
                                    a[k][l] = '0';
                            }
                        }
                    } else {
                        cout << -1;
                        return 0;
                    }
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}