#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    unsigned long long n, m;
    unsigned long long t[100001];
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> t[i];
    }
    sort(t, t + n);
    unsigned long long high = m * t[0]; 
    // 심사 시간이 제일 적은 데스크에 모든 사람이 검사 받는 경우를 최대 값으로 잡아줌
    unsigned long long low = 1;
    unsigned long long mid;
    unsigned long long ans = 0;
    unsigned long long people;
    while(high >= low){ // 이분탐색
        people = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < n;i++){
            people += mid / t[i]; // mid시간에 검사할 수 있는 인원 수
        }
        if(people >= m){ // 검사 인원이 주어진 인원이랑 같거나 커야 조건 만족
            if(ans > mid || ans ==0){ // 최소시간일때 답 저장
                ans = mid;
            }
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
