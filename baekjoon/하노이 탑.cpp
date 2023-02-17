#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void HanoiTowerMove(int n, int from, int by, int to) {  // from에 꽂혀있는 n개의 원반을 by를 거쳐 to 로 이동//
    if (n == 1)
        cout << from << ' ' << to << '\n';
    else {
        HanoiTowerMove(n - 1, from, to, by);  // 위의 원반 n-1 개를 (작은것들) 2로 이동
        cout << from << ' ' << to << '\n';    // 젤 큰원반 3으로 이동
        HanoiTowerMove(n - 1, by, from, to);  // 나머지 원반들 3으로 이동
    }
}

int main() {
    int n;
    cin >> n;
    string str = to_string(pow(2,n));
    int x=str.find('.');
    str = str.substr(0,x);
    str[str.length()-1]--;
    
    cout<<str<<'\n';
    if(n<=20)HanoiTowerMove(n, 1, 2, 3);

}