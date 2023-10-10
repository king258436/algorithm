#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long cnt;
    long long x, y, d, rd, dd;
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        d = y - x;
        rd = (long long)sqrt(d);
        dd = d - (long long)pow(rd, 2);
        cnt = rd*2-1;
        cnt = cnt+ (long long)ceil((double)dd/(double)rd);
        cout << cnt <<'\n';
    }
}