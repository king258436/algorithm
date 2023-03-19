#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
    cin >> str;
    bool flag = 0;
    bool same = 1;
    for (int i = 0; i < str.length(); i++) {
        int j = str.length() - i - 1;
        if (str[i] != str[j]) {
            flag = 1; // 펠린드롬 아님
            break;
        }
        if (same == 1 && str[0] != str[i] || str[0] != str[j]) same = 0;
    }
    if (flag){
        cout << str.length();
    }
    else{
        if(same) cout<< -1;
        else cout<< str.length()-1;
    }
    return 0;
}
