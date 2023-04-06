#include <iostream>
#include <string>

using namespace std;
int n;
void dfs(string str) {
    if (str.length() > 1) {
        for (int i = 1; i <= str.length()/2; i++) {
            string temp = str;
            if (temp.substr(temp.length() - i, i) == temp.substr(temp.length() - 2 * i, i)) {
                return;
            }
            // 뒤에거랑 앞에꺼 문자열 비교
        }
    }
    if(str.length()==n) {
        cout << str;
        exit(0);
    }
    dfs(str+'1');
    dfs(str+'2');
    dfs(str+'3');
}

int main() { 
    cin >> n; 
    string s;
    
    dfs("");
    
}