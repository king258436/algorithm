#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 우선순위

// 조건 1 : 맨뒤에 A가있는지 살펴보고 A가 있으면,
//   A를 빼주고,
//   문자열 재귀함수에 넣어줌.String t 로,
//  글고 비교때문에 string s 도 넣어줘야댐

//    조건 2 : 맨 앞에 B가 있는지 살펴보고 B가 있으면,
//    리버스 해주고 B삭제해줌 그런다음 재귀 돌려줌 만약에 문자열 개수같으면 비교해주고 맞으면 result = 1 로바꿔주고 리턴,
//    아니면 그냥 리턴
bool result = 0;
string temp;
void recursive(string t, string s) {
    if (t.length() == s.length()) {
        if (t.compare(s) == 0) {
            cout<<1;
            exit(0);
            
        }
    }
    if (t[t.length() - 1] == 'A') {
        temp = t;
        temp.erase(temp.length()-1);
        recursive(temp,s);
    }
    if(t[0]=='B'){
        temp = t;
        reverse(temp.begin(),temp.end());
        temp.erase(temp.length()-1);
        recursive(temp,s);
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    recursive(t,s);
    cout<< 0;
}