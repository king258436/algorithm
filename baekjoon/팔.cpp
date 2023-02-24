#include <cstring>
#include <iostream>
using namespace std;

char L[12];
char R[12];
int cnt;
int main() {
    int i, size;
    cin >> L >> R;

    if (strlen(R) != strlen(L))
        cnt = 0;
    else {
        for (i = 0; i<strlen(L); i++) {
            if (L[i] == R[i]){
                if(L[i]=='8') cnt++;
            }
            else break;
        }
    }
    cout << cnt;
}